/*
** client.h for  in /home/pinon_a/rendu/PSU_2013_myirc/client/include
** 
** Made by pinon
** Login   <pinon_a@epitech.net>
** 
** Started on  Tue Apr 22 14:17:55 2014 pinon
** Last update Tue Apr 22 17:19:16 2014 pinon
*/

#ifndef CLIENT_H
# define CLIENT_H

# define IO_SIZE 512

typedef struct	error_s
{
  int		code;
  const char*	msg;
}		error_t;

typedef struct	cmd_s
{
  int		code;
  void		(*func)(char *data);
}		cmd_t;

typedef struct	client_s
{
  int	socket;
}		client_t;

#endif
