/*
** main.c for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Apr 18 13:04:36 2014 guerot_a
** Last update Tue Apr 22 17:55:06 2014 guerot_a
*/

#include "myirc.h"

void	manage_server_datas(server_t* server)
{
  list_elm_t*	curr;
  user_t*	user;
  request_t	request;

  curr = LISTBEGIN(server->users);
  while (curr != LISTEND(server->users))
    {
      user = (user_t*)curr->data;
      while (parse_request(server, user, &request))
	{
	  request.user = user;
	  request.server = server;
	  manage_request_user(&request, user->channel != NULL);
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
