/*
** manage_io.c for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Mon Apr 21 19:33:03 2014 guerot_a
** Last update Mon Apr 21 23:08:48 2014 guerot_a
*/

#include "myirc.h"

void	refresh_socket_sets(server_t* server,
			    socketset_t* sets)
{
  list_elm_t*	curr;
  user_t*	user;

  FD_ZERO(&sets->read_set);
  FD_ZERO(&sets->write_set);
  sets->size = 0;
  curr = LISTBEGIN(server->users);
  while (curr != LISTEND(server->users))
    {
      user = curr->data;
      FD_SET(user->sockstream->socket, &sets->read_set);
      FD_SET(user->sockstream->socket, &sets->write_set);
      INC(curr);
      sets->size++;
    }
  FD_SET(server->sock, &sets->read_set);
  FD_SET(server->sock, &sets->write_set);
  sets->size++;
}

void	manage_io_sockets_unregistered(server_t* server,
				       socketset_t* sets)
{
  list_elm_t*	curr;
  user_t*	user;

  curr = LISTBEGIN(server->users);
  while (curr != LISTEND(server->users))
    {
      user = curr->data;
      if (FD_ISSET(user->sockstream->socket, &sets->read_set))
	recv_sockstream(user->sockstream);
      if (FD_ISSET(user->sockstream->socket, &sets->write_set))
	send_sockstream(user->sockstream);
      INC(curr);
    }
}

void	manage_io_sockets_listen(server_t* server,
				 socketset_t* sets)
{
  if (FD_ISSET(server->sock, &sets->read_set))
    accept_client(server);
}

void	manage_io_sockets(server_t* server,
			  socketset_t* sets)
{
  manage_io_sockets_unregistered(server, sets);
  manage_io_sockets_listen(server, sets);
}
