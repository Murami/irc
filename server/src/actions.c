/*
** action_unregistered.c for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Mon Apr 21 19:30:39 2014 guerot_a
** Last update Tue Apr 22 11:15:55 2014 guerot_a
*/

#include "myirc.h"

/* IRC COMMANDS */

void	manage_nickname(request_t* request)
{
  (void) request;
  printf("nick (ta mere)\n");
}

void	manage_list(request_t* request)
{
  (void) request;
  printf("list\n");
}

void	manage_join(request_t* request)
{
  (void) request;
  printf("join\n");
}

void	manage_part(request_t* request)
{
  (void) request;
  printf("part\n");
}

void	manage_users(request_t* request)
{
  (void) request;
  printf("users\n");
}

void	manage_msg(request_t* request)
{
  (void) request;
  printf("msg\n");
}

void	manage_msg_all(request_t* request)
{
  (void) request;
  printf("msg all\n");
}

void	manage_send_file(request_t* request)
{
  (void) request;
  printf("send file\n");
}

void	manage_accept_file(request_t* request)
{
  (void) request;
  printf("accept file\n");
}

void	manage_invalidcmd(request_t* request)
{
  (void) request;
  printf("invalid cmd\n");
}

void	manage_request_user(request_t* request, int inchannel)
{
  /* NO ACTION */
  (void) request;
  (void) inchannel;
}
