/*
** user.c for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Mon Apr 21 19:48:04 2014 guerot_a
** Last update Mon Apr 21 19:49:39 2014 guerot_a
*/

void		name_user(channel_t* channel, char* name)
{
  channel->last_nameid++;
  strcpy(name, "anon");
  sprintf(name, "%d", channel->last_nameid);
}

user_t* 	new_user(sockstream_t* sockstream)
{
  user_t*	user;

  user = malloc(sizeof(user_t));
  user->sockstream = sockstream;
  memset(user->name, 0, U_NAME_SIZE);
  user->channel = NULL;
  return (user);
}

void	add_user(server_t* server, sockstream_t* sockstream)
{
  user_t*	user;

  user = new_user(sockstream);
  list_push_back(server->users, user);
}
