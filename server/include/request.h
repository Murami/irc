/*
** request.h for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Apr 19 09:55:33 2014 guerot_a
** Last update Tue Apr 22 00:09:29 2014 guerot_a
*/

#ifndef REQUEST_H
# define REQUEST_H

# include "user.h"
# include "server.h"
# include "constants.h"

# define REQ_NONE		0
# define REQ_NICK		1
# define REQ_LIST		2
# define REQ_JOIN		3
# define REQ_PART		4
# define REQ_USERS		5
# define REQ_MSG		6
# define REQ_MSG_ALL		7
# define REQ_SEND_FILE		8
# define REQ_ACCEPT_FILE	9

typedef struct  pair_request_s
{
  const char	*cmd;
  int		req;
}               pair_request_t;

typedef struct	request_s
{
  int		type;
  char		buffer[REQUEST_SIZE];
  user_t*	user;
  server_t*	server;
}		request_t;

#endif /* REQUEST_H */
