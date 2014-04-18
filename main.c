/*
** main.c for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Apr 18 13:04:36 2014 guerot_a
** Last update Fri Apr 18 15:11:13 2014 guerot_a
*/

void	init_server(server_t* server, short port)
{
  struct protoent*	protocol;
  struct sockaddr_in	address;

  /* Create and init the socket */
  protocol = getprotobyname("TCP");
  server->s_listensocket = socket(AF_INET, SOCK_STREAM, protocol->p_proto);
  address.sin_family = AF_INET;
  address.sin_port = htons(port);
  address.sin_addr.s_addr = INADDR_ANY;
  bind(server->s_listensocket,
       (struct sockaddr*)&address,
       sizeof(struct sockaddr_in));
  listen(server->s_listensocket, SOMAXCONN);

  /* Init all the other variable of the server */
  memset(server->s_circularbuffer, 0, 4096);
}

void	refresh_socket_sets(server_t* server, socketset_t* sets)
{
  int	i;
  int	j;

  /* reset */
  FD_ZERO(sets->ss_read_set);
  FD_ZERO(sets->ss_write_set);
  FD_ZERO(sets->ss_except_set);
  ss_size = 0;

  /* unregistered */
  i = 0;
  while (i < server->s_unregistered_amount)
    {
      FD_SET(server_s->s_unregistered_sockets[i].ss_socket, sets->ss_read_set);
      FD_SET(server_s->s_unregistered_sockets[i].ss_socket, sets->ss_write_set);
      FD_SET(server_s->s_unregistered_sockets[i].ss_socket, sets->ss_except_set);
      i++;
    }

  /* users in chans */
  i = 0;
  while (i < server->s_channel_amount)
    {
      j = 0;
      while (j < server->s_channels[i]->c_user_amount)
	{
	  FD_SET(server_s->s_channels[i]->c_users[j]->u_socket.ss_socket,
		 sets->ss_read_set);
	  FD_SET(server_s->s_channels[i]->c_users[j]->u_socket.ss_socket,
		 sets->ss_write_set);
	  FD_SET(server_s->s_channels[i]->c_users[j]->u_socket.ss_socket,
		 sets->ss_except_set);
	  j++;
	}
      i++;
    }
}

void	recv_sockstream(sockstream_s* sstream)
{
  int	readsize;
  int	nread;

  if (sstream->ss_read_size == 0)
    return;
  readsize = 512;
  if (readsize > sstream->ss_read_size)
    readsize = sstream->ss_read_size;
  nread = read(ss_socket,
	       sstream->ss_buffer_read + sstream->ss_read_start,
	       readsize - (sstream->ss_read_start + readsize) % 4096);
  if (nread == (sstream->ss_read_start + readsize) % 4096)
    {
      nread += read(ss_socket,
		    sstream->ss_buffer_read + sstream->ss_read_start,
		    readsize - nread);
    }
  sstream->ss_read_size += nread;
}

void	send_sockstream(sockstream_s* sstream)
{
  int	writesize;
  int	nwrite;

  writesize = 512;
  if (writesize > sstream->ss_write_size)
    writesize = sstream->ss_write_size;
  nwrite = write(ss_socket,
		 sstream->ss_buffer_write + sstream->ss_write_start,
		 writesize - (sstream->ss_write_start + writesize) % 4096);
  if (nwrite == (sstream->ss_write_start + writesize) % 4096)
    {
      nwrite += write(ss_socket,
		      sstream->ss_buffer_write,
		      writesize - nwrite);
    }
  sstream->ss_write_size -= nwrite;
  sstream->ss_write_start = (sstream->ss_write_start + nwrite) % 4096;
}

void	manage_io_sockets(server_t* server, socketset_t* sets)
{
  /* unregistered */
  i = 0;
  while (i < server->s_unregistered_amount)
    {
      if (FD_ISSET(server_s->s_unregistered_sockets[i].ss_socket, sets->ss_read_set))
	recv_sockstream(&server_s->s_unregistered_sockets[i].ss_socket);
      if (FD_ISSET(server_s->s_unregistered_sockets[i].ss_socket, sets->ss_write_set))
	send_socksteam(&server_s->s_unregistered_sockets[i].ss_socket);
      /* if (FD_ISSET(server_s->s_unregistered_sockets[i].ss_socket, sets->ss_except_set)) */
      /* 	; */
      i++;
    }

  /* users in chans */
  i = 0;
  while (i < server->s_channel_amount)
    {
      j = 0;
      while (j < server->s_channels[i]->c_user_amount)
	{
	  if (FD_ISSET(server_s->s_channels[i]->c_users[j]->u_socket.ss_socket,
		       sets->ss_read_set))
	    recv_sockstream(&server_s->s_channels[i]->c_users[j]->u_socket.ss_socket);
	  if (FD_ISSET(server_s->s_channels[i]->c_users[j]->u_socket.ss_socket,
		       sets->ss_write_set))
	    send_sockstream(&server_s->s_channels[i]->c_users[j]->u_socket.ss_socket);
	  /* if (FD_ISSET(server_s->s_channels[i]->c_users[j]->u_socket.ss_socket, */
	  /* 	       sets->ss_except_set)) */
	  /*   ; */
	  j++;
	}
      i++;
    }

}

int	main()
{
  int		select_error;
  server_t	server;
  socketset_t	sets;

  init_server(&server);
  while (42)/* TROLOLOLOLOLOLOLOLOLO */
    {
      refresh_socket_sets(&sets);
      select_error = select(sets.ss_size,
			    sets.ss_read_set,
			    sets.ss_write_set,
			    sets.except_set,
			    NULL);
      manage_io_sockets(&sets);
    }
}
