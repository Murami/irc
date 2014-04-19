/*
** utils.c for  in /home/pinon_a/rendu/PSU_2013_myirc
** 
** Made by pinon
** Login   <pinon_a@epitech.net>
** 
** Started on  Sat Apr 19 09:42:33 2014 pinon
** Last update Sat Apr 19 09:48:57 2014 pinon
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"

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

int     find_empty_unregistered(server_t* server)
{
  int   i;

  i = 0;
  while (i < s_unregistered_capacity)
    {
      if (s_unregistered_sockets[i] == NULL)
        return (i);
      i++;
    }
  return (-1);
}
