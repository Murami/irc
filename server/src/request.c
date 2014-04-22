/*
** request.c for  in /home/pinon_a/rendu/PSU_2013_myirc
**
** Made by pinon
** Login   <pinon_a@epitech.net>
**
** Started on  Sat Apr 19 10:05:36 2014 pinon
** Last update Tue Apr 22 12:11:37 2014 pinon
*/

#include "myirc.h"

pair_request_t	pairs[] =
  {
    {"/nick", REQ_NICK, manage_nickname, 1},
    {"/join", REQ_JOIN, manage_join, 0},
    {"/list", REQ_LIST, manage_list, 1},
    {"/part", REQ_PART, manage_part, 1},
    {"/users", REQ_USERS, manage_users, 1},
    {"/msg", REQ_MSG, manage_msg, 1},
    {"/send_file", REQ_SEND_FILE, manage_send_file, 1},
    {"/accept_file", REQ_ACCEPT_FILE, manage_accept_file, 1},
    {NULL, REQ_MSG_ALL, manage_msg_all, 1},
    {NULL, 0, NULL, 0}
  };

void parse_args(char **tab, char *str)
{
  str[index(str, '\n') - str + 1] = '\0';
  strtok(str, " ");
  tab[0] = strtok(NULL, " ");
  tab[1] = strtok(NULL, " ");
}

int	init_request(server_t* server, user_t* user, request_t* request)
{
  int	i;

  request->type = REQ_NONE;
  request->arg1 = NULL;
  request->arg2 = NULL;
  request->channelaction = 0;
  request->func = NULL;
  request->user = user;
  request->server = server;
  memset(request->buffer, 0, REQUEST_SIZE);
  i = BUFFER_SIZE - user->sockstream->rstart;
  if (user->sockstream->rsize < i)
    i = user->sockstream->rsize;
  memcpy(request->buffer, user->sockstream->rbuff + user->sockstream->rstart, i);
  memcpy(request->buffer + i, user->sockstream->rbuff, user->sockstream->rsize - i);
}

void	get_request_type(user_t* user, request_t* request)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while ((request->buffer[i] == ' ' || request->buffer[i] == '\t')
	 && i < user->sockstream->rsize)
    i++;
  if (request->buffer[i] == '/')
    while (pairs[j].cmd != NULL)
      {
	if (request->type == REQ_NONE
	    && !strncmp(pairs[j].cmd, request->buffer + i, strlen(pairs[j].cmd))
	    && (request->buffer[i + strlen(pairs[j].cmd)] == ' '
		|| request->buffer[i + strlen(pairs[j].cmd)] == '\n'))
	  {
	    request->type = pairs[j].req;
	    request->channelaction = pairs[j].channelcmd;
	    request->func = pairs[j].func;
	  }
	j++;
      }
  else
    request->type = REQ_MSG_ALL;
}

void	set_cursor(user_t* user, request_t* request)
{
  if (!strchr(request->buffer, '\n'))
    {
      user->sockstream->rsize = 0;
      user->sockstream->rstart = 0;
    }
  else
    {
      offset = MIN(strchr(request->buffer, '\n')
		   - request->buffer + 1, user->sockstream->rsize);
      user->sockstream->rstart += offset;
      user->sockstream->rsize -= offset;
      user->sockstream->rstart %= REQUEST_SIZE;
    }
}

int	parse_request(server_t* server, user_t* user, request_t* request)
{
  int	i;
  int	j;
  int	offset;

  if (user->sockstream->rsize == 0)
    return (0);
  init_request(server, user, request);
  get_request_type(user, request);
  ser_cursor(user, request);
  return (1);
}
