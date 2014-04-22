/*
** utils.c for  in /home/pinon_a/rendu/PSU_2013_myirc
**
** Made by pinon
** Login   <pinon_a@epitech.net>
**
** Started on  Sat Apr 19 09:42:33 2014 pinon
** Last update Tue Apr 22 17:51:28 2014 guerot_a
*/

#include "myirc.h"

int     str_match(char *str, char *name)
{
  int   i;

  i = 0;
  while (name[i] != 0)
    {
      if (str != NULL && !strncmp(str, name, strlen(str)))
        return (1);
      i++;
    }
  return (0);
}

int		available_name(server_t* server, char* name)
{
  list_elm_t*	curr;
  user_t*	user;

  curr = LISTBEGIN(server->users);
  while (curr != LISTEND(server->users))
    {
      user = (user_t*)curr->data;
      if (strncmp(user->name, name, U_NAME_SIZE) == 0)
	return (0);
      INC(curr);
    }
  return (1);
}

channel_t*	find_channel(server_t* server, /*const*/ char* name)
{
  list_elm_t*	curr;
  channel_t*	chan;

  curr = LISTBEGIN(server->chans);
  while (curr != LISTEND(server->chans))
    {
      chan = (channel_t*)curr->data;
      /* printf("%s\n", chan->name); */
      printf("%s -- %s -- %d\n", name, chan->name, strncmp(name, chan->name, U_NAME_SIZE));
      if (strncmp(name, chan->name, U_NAME_SIZE) == 0)
	return (curr->data);
      INC(curr);
    }
  return (NULL);
}

user_t*		find_user(server_t* server, const char* name)
{
  list_elm_t*	curr;
  user_t*	user;

  curr = LISTBEGIN(server->users);
  while (curr != LISTEND(server->users))
    {
      user = (user_t*)curr->data;
      if (strncmp(name, user->name, U_NAME_SIZE))
	return (curr->data);
      INC(curr);
    }
  return (NULL);
}
