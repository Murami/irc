/*
** cmd_list.c for  in /home/pinon_a/rendu/PSU_2013_myirc
** 
** Made by pinon
** Login   <pinon_a@epitech.net>
** 
** Started on  Fri Apr 18 13:39:52 2014 pinon
** Last update Fri Apr 18 13:59:54 2014 pinon
*/

#include "channel.h"

int	str_match(char *str, char *name)
{
  int	i;

  i = 0;
  while (name[i] != 0)
    {
      if (str != NULL && !strncmp(str, name, strlen(str)))
	return (1);
      i++;
    }
  return (0);
}

void	cmd_list(char *str, channel_t *channels, int channel_amount)
{
  int	i;

  i = 0;
  while (i < channel_amount)
    {
      if (str == NULL)
	printf("%s\n", channels[i]->name);
      else if (str != NULL && str_match(str, channels[i].name))
	printf("%s\n", channels[i]->name);
      i++;
    }
}
