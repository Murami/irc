/*
** channel.h for  in /home/pinon_a/rendu/PSU_2013_myirc
**
** Made by pinon
** Login   <pinon_a@epitech.net>
**
** Started on  Fri Apr 18 13:29:51 2014 pinon
** Last update Fri Apr 18 15:22:40 2014 guerot_a
*/

#ifndef CHANNEL_H_
# define CHANNEL_H_

# include "user.h"

# define		C_NAME_SIZE 128

typedef struct	channel_s
{
  char		c_name[C_NAME_SIZE];
  int		c_user_amount;
  user_t*	c_users;
}		channel_t;

#endif
