/*
** list_cmd.c for  in /home/pinon_a/rendu/PSU_2013_myirc/client
** 
** Made by pinon
** Login   <pinon_a@epitech.net>
** 
** Started on  Tue Apr 22 17:15:07 2014 pinon
** Last update Tue Apr 22 17:23:18 2014 pinon
*/

#include <stdio.h>

void    rpl_liststart(char* data)
{
  printf("LIST START\n");
}

void    rpl_list(char* data)
{
  printf("LIST\n");
}

void    rpl_listend(char* data)
{
  printf("LIST END\n");
}
