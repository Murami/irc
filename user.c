/*
** user.c for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Mon Apr 21 19:48:04 2014 guerot_a
** Last update Mon Apr 21 23:49:31 2014 guerot_a
*/

#include "myirc.h"

void		name_user(channel_t* channel, char* name)
{
  channel->last_nameid++;
  strcpy(name, "anon");
  sprintf(name, "%d", channel->last_nameid);
}

user_t* 	new_user(int socket)
{
  user_t*	user;

  user = malloc(sizeof(user_t));
  user->sockstream = new_sockstream(socket);
  memset(user->name, 0, U_NAME_SIZE);
  user->channel = NULL;
  return (user);
}

void		add_user(server_t* server, int socket)
{
  user_t*	user;

  user = new_user(socket);
  list_push_back(server->users, user);
}
