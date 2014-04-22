/*
** join_cmd.c for  in /home/pinon_a/rendu/PSU_2013_myirc/client
** 
** Made by pinon
** Login   <pinon_a@epitech.net>
** 
** Started on  Tue Apr 22 17:14:16 2014 pinon
** Last update Tue Apr 22 17:23:04 2014 pinon
*/

#include <stdio.h>

void    rpl_joinok(char* data)
{
  printf("JOIN\n");
}

void    rpl_newjoin(char* data)
{
  printf("NEWJOIN\n");
}
