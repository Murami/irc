/*
** action_unregistered.c for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Mon Apr 21 19:30:39 2014 guerot_a
** Last update Mon Apr 21 19:47:59 2014 guerot_a
*/

void manage_nickname_unregistered(server_t* server,
				  request_t* request,
				  int socket_id)
{
  printf("nick (ta mere)\n");
}

void manage_list_unregistered(server_t* server,
			      request_t* request,
			      int socket_id)
{
  printf("list\n");
}

void manage_join_unregistered(server_t* server,
			      request_t* request,
			      int socket_id)
{
  char *arg[2];

  memset(arg, 0, 2 * sizeof(void*));
  printf("cmd join\n");
  printf("%s\n", request->r_buffer);
  parse_args(arg, request->r_buffer);
  printf("arg1 = %s\n", arg[0]);
  printf("arg2 = %s\n", arg[1]);
}

void manage_part_unregistered(server_t* server,
			      request_t* request,
			      int socket_id)
{
  /* not supported */
  printf("part ouze\n");
}

void manage_users_unregistered(server_t* server,
			       request_t* request,
			       int socket_id)
{
  /* not supported */
  printf("users\n");
}

void manage_msg_unregistered(server_t* server,
			     request_t* request,
			     int socket_id)
{
  /* not supported */
  printf("msg\n");
}

void manage_msg_all_unregistered(server_t* server,
				 request_t* request,
				 int socket_id)
{
  /* not supported */
  printf("msg all\n");
}

void manage_send_file_unregistered(server_t* server,
				   request_t* request,
				   int socket_id)
{
  /* not supported */
  printf("send file\n");
}

void manage_accept_file_unregistered(server_t* server,
				     request_t* request,
				     int socket_id)
{
  printf("accept file\n");
}

void	manage_request_unregistered(server_t* server,
				    request_t* request,
				    int socket_id)
{
  printf("%d\n", request->r_type);
  switch (request->r_type)
    {
    case REQ_NICK:
      manage_nickname_unregistered(server, request, socket_id);
      break;
    case REQ_LIST:
      manage_list_unregistered(server, request, socket_id);
      break;
    case REQ_JOIN:
      manage_join_unregistered(server, request, socket_id);
      break;
    case REQ_PART:
      manage_part_unregistered(server, request, socket_id);
      break;
    case REQ_USERS:
      manage_users_unregistered(server, request, socket_id);
      break;
    case REQ_MSG:
      manage_msg_unregistered(server, request, socket_id);
      break;
    case REQ_MSG_ALL:
      manage_msg_all_unregistered(server, request, socket_id);
      break;
    case REQ_SEND_FILE:
      manage_send_file_unregistered(server, request, socket_id);
      break;
    case REQ_ACCEPT_FILE:
      manage_accept_file_unregistered(server, request, socket_id);
      break;
    default:
      return;
    }
}
