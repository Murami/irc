/*
** utils.c for  in /home/pinon_a/rendu/PSU_2013_myirc
**
** Made by pinon
** Login   <pinon_a@epitech.net>
**
** Started on  Sat Apr 19 09:42:33 2014 pinon
** Last update Mon Apr 21 23:50:16 2014 guerot_a
*/

#include "myirc.h"

int     str_match(char *str, char *name)
{
  int   i;

  i = 0;
  while (name[i] != 0)
    {
      if (str != NULL && !strncmp(str, name, strlen(str)))
        return (1);
      i++;
    }
  return (0);
}
