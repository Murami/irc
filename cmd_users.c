/*
** cmd_users.c for  in /home/pinon_a/rendu/PSU_2013_myirc
**
** Made by pinon
** Login   <pinon_a@epitech.net>
**
** Started on  Fri Apr 18 13:47:44 2014 pinon
** Last update Fri Apr 18 15:25:19 2014 guerot_a
*/

#include <stdio.h>
#include "user.h"

void	cmd_users(user_t *users, int user_amount)
{
  int	i;

  i = 0;
  while (i < user_amount)
    {
      printf("%s\n", users[i].u_name);
      i++;
    }
}
