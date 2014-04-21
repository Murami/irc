/*
** channel.h for  in /home/pinon_a/rendu/PSU_2013_myirc
**
** Made by pinon
** Login   <pinon_a@epitech.net>
**
** Started on  Fri Apr 18 13:29:51 2014 pinon
** Last update Mon Apr 21 19:15:30 2014 guerot_a
*/

#ifndef CHANNEL_H_
# define CHANNEL_H_

# include "user.h"

# define		C_NAME_SIZE 128

typedef struct	channel_s
{
  char		name[C_NAME_SIZE];
  list_t	user;
  int		last_nameid;
}		channel_t;

#endif
