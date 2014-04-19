/*
** server.h for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Apr 18 15:25:42 2014 guerot_a
** Last update Sat Apr 19 09:33:49 2014 guerot_a
*/

#ifndef SERVER_H
# define SERVER_H

# include "channel.h"
# include "sockstream.h"

# define MAX(a, b)	((a > b) ? a : b)

typedef struct	server_s
{
  int		s_socket;
  int		s_channel_amount;
  channel_t*	s_channels;
  int		s_unregistered_amount;
  int		s_unregistered_capacity;
  sockstream_t*	s_unregistered_sockets;
  int		s_socket_max;
}		server_t;

#endif /* SERVER_H */
