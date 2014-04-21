/*
** server.h for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Apr 18 15:25:42 2014 guerot_a
** Last update Mon Apr 21 19:07:00 2014 guerot_a
*/

#ifndef SERVER_H
# define SERVER_H

# include "channel.h"
# include "sockstream.h"

# define MAX(a, b)	((a > b) ? a : b)
# define MIN(a, b)	((a < b) ? a : b)

typedef struct		server_s
{
  int			sock;
  list_t		chans;
  list_t		users;
  int			sockmax;
}			server_t;

#endif /* SERVER_H */
