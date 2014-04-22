/*
** action_unregistered.c for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Mon Apr 21 19:30:39 2014 guerot_a
** Last update Tue Apr 22 18:32:58 2014 guerot_a
*/

#include "myirc.h"

void	send_servermsg(int socket, int msgid,
		       char* data, int datalen)
{
  char	buff[IO_SIZE + 1];

  memset(buff, 0, IO_SIZE);
  snprintf(buff, 4, "%03d", msgid);
  if (data != NULL)
    {
      strncat(buff, data,
	      MIN(IO_SIZE - RPL_LIST - 1, datalen));
    }
  strncat(buff, "\n", IO_SIZE - RPL_LIST);
  write(socket, buff, strnlen(buff, IO_SIZE));
}

/* IRC COMMANDS */

void	manage_nickname(request_t* req)
{
  printf("nick\n");
  /* printf("%s\n", req->arg1); */
  if (req->arg1 == NULL)
    {
      send_servermsg(req->user->sockstream->socket,
		     ERR_NONICKNAMEGIVEN, NULL, 0);
      return;
    }
  if (!(available_name(req->server, req->arg1)))
    {
      send_servermsg(req->user->sockstream->socket,
		     ERR_NICKNAMEINUSE, NULL, 0);
      return;
    }
  strncpy(req->user->name, req->arg1, U_NAME_SIZE);
}

void	manage_list(request_t* req)
{
  list_elm_t*	curr;
  channel_t*	chan;

  printf("nick\n");
  /* LISTSTART */
  send_servermsg(req->user->sockstream->socket,
		 RPL_LISTSTART, NULL, 0);

  /* LIST */
  curr = LISTBEGIN(req->server->chans);
  while (curr != LISTEND(req->server->chans))
    {
      chan = (channel_t*)curr->data;
      send_servermsg(req->user->sockstream->socket,
		     RPL_LIST, chan->name, C_NAME_SIZE);
      INC(curr);
    }

  /* LISTEND */
  send_servermsg(req->user->sockstream->socket,
		 RPL_LISTEND, NULL, 0);
}

void	manage_join(request_t* req)
{
  channel_t*	chan;

  printf("join\n");
  if (req->arg1 == NULL)
    {
      send_servermsg(req->user->sockstream->socket,
		     ERR_NEEDMOREPARAM, NULL, 0);
      return;
    }
  if (!(chan = find_channel(req->server, req->arg1)))
    {
      send_servermsg(req->user->sockstream->socket,
		     ERR_NOSUCHCHANNEL, NULL, 0);
      return;
    }
  req->user->channel = chan;
  send_servermsg(req->user->sockstream->socket,
		 RPL_JOINOK, NULL, 0);
  /* IL FAUT PREVENIR TOUS LES USERS SUR LE CHAN AVC RPL_NEWJOIN */
}

void	manage_part(request_t* req)
{
  printf("part\n");
  if (req->user->channel == NULL)
    {
      send_servermsg(req->user->sockstream->socket,
		     ERR_NOTONCHANNEL, NULL, 0);
    }
  req->user->channel = NULL;
  send_servermsg(req->user->sockstream->socket,
		 RPL_PARTOK, NULL, 0);
  /* IL FAUT PREVENIR TOUS LES USERS DU CHAN AVEC RPL_NEWPART */
}

void	manage_users(request_t* req)
{
  list_elm_t*	curr;
  user_t*	user;

  printf("users\n");
  /* USERSSTART */
  send_servermsg(req->user->sockstream->socket,
		 RPL_USERSSTART, NULL, 0);

  /* USERS */
  curr = LISTBEGIN(req->server->users);
  while (curr != LISTEND(req->server->users))
    {
      user = (user_t*)curr->data;
      if (user->channel != NULL)
      	{
	  send_servermsg(req->user->sockstream->socket,
			 RPL_USERS, user->name, U_NAME_SIZE);
	}
      INC(curr);
    }

  /* USERSEND */
  send_servermsg(req->user->sockstream->socket,
		 RPL_USERSEND, NULL, 0);
}

void	manage_msg(request_t* req)
{
  user_t*	user;

  printf("msg\n");
  if (req->arg1 == NULL || req->arg2 == NULL)
    {
      send_servermsg(req->user->sockstream->socket,
		     ERR_NEEDMOREPARAM, NULL, 0);
      return;
    }
  if (!(user = find_user(req->server, req->arg1)))
    {
      send_servermsg(req->user->sockstream->socket,
		     ERR_NOSUCHUSER, NULL, 0);
      return;
    }
  send_servermsg(user->sockstream->socket, RPL_MSGSENDER,
		 req->user->name, IO_SIZE);
  send_servermsg(user->sockstream->socket, RPL_MSG, req->arg2, IO_SIZE);
}

void	manage_msg_all(request_t* request)
{
  (void) request;
  printf("msg all\n");
}

void	manage_send_file(request_t* request)
{
  (void) request;
  printf("send file\n");
}

void	manage_accept_file(request_t* request)
{
  (void) request;
  printf("accept file\n");
}

void	manage_invalidcmd(request_t* request)
{
  (void) request;
  printf("invalid cmd\n");
}

/* */

void	manage_request_user(request_t* request, int inchannel)
{
  if (inchannel == request->channelaction)
    request->func(request);
  else
    manage_invalidcmd(request);
}
