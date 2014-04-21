/*
** channel.c for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Mon Apr 21 19:31:15 2014 guerot_a
** Last update Mon Apr 21 23:00:13 2014 guerot_a
*/

#include "myirc.h"

channel_t*	new_channel(char* channel_name)
{
  channel_t*	chan;

  chan = malloc(sizeof(channel_t));
  strncpy(chan->name, channel_name, C_NAME_SIZE);
  chan->users = new_list();
  chan->last_nameid = 0;
  return (chan);
}

void	user_join_channel(server_t* server,
			  channel_t* channel,
			  list_elm_t* e_user)
{
  user_t*	user;

  user = e_user->data;
  list_erase(server->users, e_user);
  list_push_back(channel->users, user);
  name_user(channel, user->name);
}

void	add_channel(server_t* server, char* channel_name)
{
  channel_t*	channel;

  channel = new_channel(channel_name);
  list_push_back(server->chans, channel);
}
