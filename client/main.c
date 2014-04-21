/*
** main.c for  in /home/guerot_a/rendu/PSU_2013_myirc/client
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Apr 19 10:51:25 2014 guerot_a
** Last update Sat Apr 19 11:25:15 2014 guerot_a
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	format_buffer(char* buffer, char* formated_buffer)
{
  int	i = 0;
  char*	token;

  while (token = strtok(buffer, " "))
    {
      memcpy(formated_buffer + i, token, strlen(token));
      i += strlen(token) + 1;
      buffer = NULL;
    }
  formated_buffer[i] = '\0';
}

int	main()
{
  char	buffer[513];
  char	formated_buffer[513];

  while (42)
    {
      memset(buffer, 0, 513);
      memset(formated_buffer, ' ', 513);
      read(0, buffer, 512);
      fflush(0);
      format_buffer(buffer, formated_buffer);
      printf("%s\n", formated_buffer);
    }
  return (0);
}
