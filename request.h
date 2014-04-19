/*
** request.h for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Apr 19 09:55:33 2014 guerot_a
** Last update Sat Apr 19 10:14:24 2014 guerot_a
*/

#ifndef REQUEST_H
# define REQUEST_H

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

typedef struct	request_s
{
  int		r_type;
  char		r_buffer[REQUEST_SIZE];
}		request_t;

#endif /* REQUEST_H */
