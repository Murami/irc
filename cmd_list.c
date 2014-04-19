/*
** cmd_list.c for  in /home/pinon_a/rendu/PSU_2013_myirc
**
** Made by pinon
** Login   <pinon_a@epitech.net>
**
** Started on  Fri Apr 18 13:39:52 2014 pinon
** Last update Sat Apr 19 09:47:29 2014 pinon
*/

#include <stdlib.h>
#include <stdio.h>
#include "channel.h"

void	cmd_list(char *str, channel_t *channels, int channel_amount)
{
  int	i;

  i = 0;
  while (i < channel_amount)
    {
      if (str == NULL)
	printf("%s\n", channels[i].c_name);
      else if (str != NULL && str_match(str, channels[i].c_name))
	printf("%s\n", channels[i].c_name);
      i++;
    }
}
