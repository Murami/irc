/*
** main.c for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Apr 18 13:04:36 2014 guerot_a
** Last update Sat Apr 19 13:36:34 2014 guerot_a
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "server.h"
#include "socketset.h"
#include "request.h"

sockstream_t*	create_sockstream(int);

void	init_server(server_t* server, short port)
{
  struct protoent*	protocol;
  struct sockaddr_in	address;
  u_long		argp=1;

  /* Create and init the socket */
  protocol = getprotobyname("TCP");
  server->s_socket = socket(AF_INET, SOCK_STREAM, protocol->p_proto);
  address.sin_family = AF_INET;
  address.sin_port = htons(port);
  address.sin_addr.s_addr = INADDR_ANY;
  bind(server->s_socket,
       (struct sockaddr*)&address,
       sizeof(struct sockaddr_in));
  listen(server->s_socket, 42);
  server->s_socket_max = server->s_socket;

  /* Others */
  server->s_channel_amount = 0;
  server->s_channels = NULL;
  server->s_unregistered_amount = 0;
  server->s_unregistered_capacity = 0;
  server->s_unregistered_sockets = NULL;
}

void	refresh_socket_sets(server_t* server, socketset_t* sets)
{
  int	i;
  int	j;

  /* reset */
  FD_ZERO(&sets->ss_read_set);
  FD_ZERO(&sets->ss_write_set);
  sets->ss_size = 0;

  /* unregistered */
  i = 0;
  while (i < server->s_unregistered_amount)
    {
      FD_SET(server->s_unregistered_sockets[i]->ss_socket, &sets->ss_read_set);
      FD_SET(server->s_unregistered_sockets[i]->ss_socket, &sets->ss_write_set);
      i++;
    }

  /* /\* users in chans *\/ */
  /* i = 0; */
  /* while (i < server->s_channel_amount) */
  /*   { */
  /*     j = 0; */
  /*     while (j < server->s_channels[i].c_user_amount) */
  /* 	{ */
  /* 	  FD_SET(server->s_channels[i].c_users[j].u_socket->ss_socket, */
  /* 		 &sets->ss_read_set); */
  /* 	  FD_SET(server->s_channels[i].c_users[j].u_socket->ss_socket, */
  /* 		 &sets->ss_write_set); */
  /* 	  FD_SET(server->s_channels[i].c_users[j].u_socket->ss_socket, */
  /* 		 &sets->ss_except_set); */
  /* 	  j++; */
  /* 	} */
  /*     i++; */
  /*   } */

  /* listen socket */
  FD_SET(server->s_socket,  &sets->ss_read_set);
  FD_SET(server->s_socket,  &sets->ss_write_set);
  sets->ss_size++;
}

void	recv_sockstream(sockstream_t* sstream)
{
  int	readsize;
  int	nread;

  /* printf("rcv\n"); */
  readsize = IO_SIZE;
  if (readsize > BUFFER_SIZE - sstream->ss_read_size)
    readsize = BUFFER_SIZE - sstream->ss_read_size;
  if (readsize == 0)
    return;
  if (readsize + sstream->ss_read_start > BUFFER_SIZE)
    {
      nread = read(sstream->ss_socket,
		   sstream->ss_buffer_read + sstream->ss_read_start,
		   BUFFER_SIZE - sstream->ss_read_start);
      if (nread == BUFFER_SIZE - sstream->ss_read_start)
	{
	  nread += read(sstream->ss_socket,
			sstream->ss_buffer_read + sstream->ss_read_start,
			readsize - BUFFER_SIZE + sstream->ss_read_start);
	}
    }
  else
    {
      nread = read(sstream->ss_socket,
		   sstream->ss_buffer_read + sstream->ss_read_start,
		   readsize);
    }
  sstream->ss_read_size += nread;
}

void	send_sockstream(sockstream_t* sstream)
{
  int	writesize;
  int	nwrite;

  writesize = IO_SIZE;
  if (writesize > sstream->ss_write_size)
    writesize = sstream->ss_write_size;
  nwrite = write(sstream->ss_socket,
		 sstream->ss_buffer_write + sstream->ss_write_start,
		 writesize - (sstream->ss_write_start + writesize) % BUFFER_SIZE);
  if (nwrite == (sstream->ss_write_start + writesize) % BUFFER_SIZE)
    {
      nwrite += write(sstream->ss_socket,
		      sstream->ss_buffer_write,
		      writesize - nwrite);
    }
  sstream->ss_write_size -= nwrite;
  sstream->ss_write_start = (sstream->ss_write_start + nwrite) % BUFFER_SIZE;
}

void	accept_client(server_t* server)
{
  int		empty_unregistered;
  int		client_sock;

  client_sock = accept(server->s_socket, NULL, NULL);
  printf("a client have just connected !\n");/* DBG LINE */
  server->s_socket_max = MAX(client_sock, server->s_socket_max);
  if ((empty_unregistered = find_empty_unregistered(server)) != -1)
    {
      server->s_unregistered_sockets[empty_unregistered] = create_sockstream(client_sock);
    }
  else
    {
      if (server->s_unregistered_amount >= server->s_unregistered_capacity)
	{
	  server->s_unregistered_capacity *= 2;
	  if (server->s_unregistered_capacity == 0)
	    server->s_unregistered_capacity = 1;
	  server->s_unregistered_sockets = realloc(server->s_unregistered_sockets, server->s_unregistered_capacity * sizeof(void*));
	}
      server->s_unregistered_sockets[server->s_unregistered_amount] = create_sockstream(client_sock);
      server->s_unregistered_amount += 1;
    }
}

void	manage_io_sockets(server_t* server, socketset_t* sets)
{
  int	i;
  int	j;

  /* unregistered */
  i = 0;
  while (i < server->s_unregistered_amount)
    {
      if (FD_ISSET(server->s_unregistered_sockets[i]->ss_socket, &sets->ss_read_set))
	recv_sockstream(server->s_unregistered_sockets[i]);
      if (FD_ISSET(server->s_unregistered_sockets[i]->ss_socket, &sets->ss_write_set))
  	send_sockstream(server->s_unregistered_sockets[i]);
      i++;
    }

  /* /\* users in chans *\/ */
  /* i = 0; */
  /* while (i < server->s_channel_amount) */
  /*   { */
  /*     j = 0; */
  /*     while (j < server->s_channels[i].c_user_amount) */
  /* 	{ */
  /* 	  if (FD_ISSET(server->s_channels[i].c_users[j].u_socket->ss_socket, */
  /* 		       &sets->ss_read_set)) */
  /* 	    recv_sockstream(&server->s_channels[i].c_users[j].u_socket); */
  /* 	  if (FD_ISSET(server->s_channels[i].c_users[j].u_socket->ss_socket, */
  /* 		       &sets->ss_write_set)) */
  /* 	    send_sockstream(&server->s_channels[i].c_users[j].u_socket); */
  /* 	  /\* if (FD_ISSET(server->s_channels[i]->c_users[j]->u_socket->ss_socket, *\/ */
  /* 	  /\* 	       sets->ss_except_set)) *\/ */
  /* 	  /\*   ; *\/ */
  /* 	  j++; */
  /* 	} */
  /*     i++; */
  /*   } */

  /* listen socket */
  if (FD_ISSET(server->s_socket,  &sets->ss_read_set))
    accept_client(server);
  if (FD_ISSET(server->s_socket,  &sets->ss_write_set))
    ;
}

void	manage_request_unregistered(server_t* server, request_t* request, int socket_id)
{

}

void	manage_server_datas(server_t* server)
{
  int		i;
  request_t	request;

  /* manage unregistered */
  i = 0;
  while (i < server->s_unregistered_amount)
    {
      while (parse_request(server->s_unregistered_sockets[i], &request))
      	{
      	  manage_request_unregistered(server, &request, i);
      	}
      i++;
    }
}

int	main(int argc, char **argv)
{
  int		select_error;
  server_t	server;
  socketset_t	sets;

  init_server(&server, atoi(argv[1]));
  while (42)
    {
      refresh_socket_sets(&server, &sets);
      select_error = select(server.s_socket_max + 1,
			    &sets.ss_read_set,
			    /* &sets.ss_write_set, */
			    NULL,
			    NULL, NULL);
      manage_io_sockets(&server, &sets);
      manage_server_datas(&server);
    }
}
