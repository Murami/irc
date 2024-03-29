/*
** channel.c for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Mon Apr 21 19:31:15 2014 guerot_a
** Last update Tue Apr 22 16:37:56 2014 guerot_a
*/

#include "myirc.h"

channel_t*	new_channel(const char* channel_name)
{
  channel_t*	chan;

  chan = (channel_t*)malloc(sizeof(channel_t));
  strncpy(chan->name, channel_name, C_NAME_SIZE);
  chan->last_nameid = 0;
  return (chan);
}

void	add_channel(server_t* server, const char* channel_name)
{
  channel_t*	channel;

  channel = (channel_t*)new_channel(channel_name);
  list_push_back(server->chans, channel);
}
