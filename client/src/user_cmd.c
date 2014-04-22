/*
** user_cmd.c for  in /home/pinon_a/rendu/PSU_2013_myirc/client
** 
** Made by pinon
** Login   <pinon_a@epitech.net>
** 
** Started on  Tue Apr 22 17:15:42 2014 pinon
** Last update Tue Apr 22 17:23:23 2014 pinon
*/

#include <stdio.h>

void    rpl_usersstart(char* data)
{
  printf("USER START\n");
}

void    rpl_users(char* data)
{
  printf("USER\n");
}

void    rpl_usersend(char* data)
{
  printf("USER END\n");
}
