/*
** user.h for  in /home/pinon_a/rendu/PSU_2013_myirc
**
** Made by pinon
** Login   <pinon_a@epitech.net>
**
** Started on  Fri Apr 18 13:37:02 2014 pinon
** Last update Tue Apr 22 14:54:23 2014 guerot_a
*/

#ifndef USER_H_
# define USER_H_

# include "channel.h"
# include "sockstream.h"

typedef struct  user_s
{
  sockstream_t*	sockstream;
  char          name[U_NAME_SIZE];
  channel_t*	channel;
}               user_t;

#endif
