/*
** channel.h for  in /home/pinon_a/rendu/PSU_2013_myirc
**
** Made by pinon
** Login   <pinon_a@epitech.net>
**
** Started on  Fri Apr 18 13:29:51 2014 pinon
** Last update Mon Apr 21 23:00:36 2014 guerot_a
*/

#ifndef CHANNEL_H_
# define CHANNEL_H_

# include "constants.h"
# include "list.h"

typedef struct	channel_s
{
  char		name[C_NAME_SIZE];
  list_t*	users;
  int		last_nameid;
}		channel_t;

#endif
