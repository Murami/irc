/*
** action_unregistered.c for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Mon Apr 21 19:30:39 2014 guerot_a
** Last update Mon Apr 21 23:46:55 2014 guerot_a
*/

#include "myirc.h"

void manage_nickname_unregistered(request_t* request)
{
  printf("nick (ta mere)\n");
}

void manage_list_unregistered(request_t* request)
{
  printf("list\n");
}

void manage_join_unregistered(request_t* request)
{
  char *arg[2];

  memset(arg, 0, 2 * sizeof(void*));
  printf("cmd join\n");
  printf("%s\n", request->buffer);
  parse_args(arg, request->buffer);
  printf("arg1 = %s\n", arg[0]);
  printf("arg2 = %s\n", arg[1]);
}

void manage_part_unregistered(request_t* request)
{
  /* not supported */
  printf("part ouze\n");
}

void manage_users_unregistered(request_t* request)
{
  /* not supported */
  printf("users\n");
}

void manage_msg_unregistered(request_t* request)
{
  /* not supported */
  printf("msg\n");
}

void manage_msg_all_unregistered(request_t* request)
{
  /* not supported */
  printf("msg all\n");
}

void manage_send_file_unregistered(request_t* request)
{
  /* not supported */
  printf("send file\n");
}

void manage_accept_file_unregistered(request_t* request)
{
  printf("accept file\n");
}

void	manage_request_unregistered(request_t* request)
{
  printf("%d\n", request->type);
  switch (request->type)
    {
    case REQ_NICK:
      manage_nickname_unregistered(request);
      break;
    case REQ_LIST:
      manage_list_unregistered(request);
      break;
    case REQ_JOIN:
      manage_join_unregistered(request);
      break;
    case REQ_PART:
      manage_part_unregistered(request);
      break;
    case REQ_USERS:
      manage_users_unregistered(request);
      break;
    case REQ_MSG:
      manage_msg_unregistered(request);
      break;
    case REQ_MSG_ALL:
      manage_msg_all_unregistered(request);
      break;
    case REQ_SEND_FILE:
      manage_send_file_unregistered(request);
      break;
    case REQ_ACCEPT_FILE:
      manage_accept_file_unregistered(request);
      break;
    default:
      return;
    }
}
