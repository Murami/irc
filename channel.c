/*
** channel.c for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Mon Apr 21 19:31:15 2014 guerot_a
** Last update Mon Apr 21 19:31:41 2014 guerot_a
*/

channel_t*	new_channel(char* channel_name)
{
  channel_t*	chan;

  chan = malloc(sizeof(channel_t));
  strncpy(chan->c_name, channel_name, C_NAME_SIZE);
  init_list(chan->users);
  chan->last_nameid = 0;
  return (chan);
}

void	user_join_channel(channel_t* channel, t_list_elm* e_user)
{
  user_t*	user;

  user = s_user->data;
  list_erase(server->users, e_user);
  list_push_back(channel->user, user);
  name_user(channel, user->name);
}

void	add_channel(server_t* server, char* channel_name)
{
  channel_t*	channel;

  channel = new_channel(channel_name);
  list_push_back(server->chans, channel);
}
