/*
** main.c for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Apr 18 13:04:36 2014 guerot_a
** Last update Tue Apr 22 11:28:21 2014 guerot_a
*/

#include "myirc.h"

int		available_name(channel_t* channel, char* name)
{
  list_elm_t*	curr;
  user_t*	user;

  curr = LISTBEGIN(channel->users);
  while (curr != LISTEND(channel->users))
    {
      user = (user_t*)curr->data;
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
      user = (user_t*)curr->data;
      while (parse_request(user->sockstream, &request))
	{
	  request.user = user;
	  request.server = server;
	  manage_request_user(&request, 0);
	}
      INC(curr);
    }
}

int	main(int argc, char **argv)
{
  int		select_error;
  server_t	server;
  socketset_t	sets;

  (void) argc;
  init_server(&server, atoi(argv[1]));
  while (42)
    {
      refresh_sets(&server, &sets);
      select_error = select(server.sockmax + 1,
			    &sets.read_set,
			    /* &sets.write_set, */
			    NULL,
			    NULL, NULL);
      (void) select_error;
      manage_io(&server, &sets);
      manage_server_datas(&server);
      usleep(100);
    }
}
