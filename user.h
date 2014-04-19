/*
** user.h for  in /home/pinon_a/rendu/PSU_2013_myirc
**
** Made by pinon
** Login   <pinon_a@epitech.net>
**
** Started on  Fri Apr 18 13:37:02 2014 pinon
** Last update Sat Apr 19 14:47:04 2014 guerot_a
*/

#ifndef USER_H_
# define USER_H_

# include "sockstream.h"

# define	U_NAME_SIZE 128

typedef struct  user_s
{
  sockstream_t*	u_sstream;
  char          u_name[U_NAME_SIZE];
}               user_t;

#endif
