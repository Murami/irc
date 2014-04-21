/*
** main.c for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Apr 18 13:04:36 2014 guerot_a
** Last update Mon Apr 21 19:47:21 2014 guerot_a
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int		available_name(channel_t* channel, char* name)
{
  t_list_elm*	curr;
  user_t*	user;

  curr = LISTBEGIN(channel->users);
  while (curr != LISTEND(channel->users))
    {
      user = curr->data;
      if (strncmp(user->name, name, U_NAME_SIZE) == 0)
	return (0);
      INC(curr);
    }
  return (1);
}

void	manage_server_datas(server_t* server)
{
  list_elm_t*	curr;
  user_t*	user;
  request_t	request;

  curr = LISTBEGIN(server->users);
  while (curr != LISTEND(server->users))
    {
      user = curr->data;
      while (parse_request(user->sockstream, &request))
	manage_request_unregistered(server, &request, user);
      INC(curr);
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
			    &sets.read_set,
			    /* &sets.write_set, */
			    NULL,
			    NULL, NULL);
      manage_io_sockets(&server, &sets);
      manage_server_datas(&server);
      usleep(100);
    }
}
