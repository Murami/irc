/*
** server.c for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Mon Apr 21 19:32:20 2014 guerot_a
** Last update Tue Apr 22 17:09:11 2014 guerot_a
*/

#include "myirc.h"

void	init_user_list(server_t* server)
{
  server->users = new_list();
}

void	init_channel_list(server_t* server)
{
  server->chans = new_list();
  add_channel(server, "chan1");
  add_channel(server, "chan2");
}

void	init_server(server_t* server, short port)
{
  struct protoent*	protocol;
  struct sockaddr_in	address;

  protocol = getprotobyname("TCP");
  server->sock = socket(AF_INET, SOCK_STREAM, protocol->p_proto);
  address.sin_family = AF_INET;
  address.sin_port = htons(port);
  address.sin_addr.s_addr = INADDR_ANY;
  bind(server->sock,
       (struct sockaddr*)&address,
       sizeof(struct sockaddr_in));
  listen(server->sock, 42);
  server->sockmax = server->sock;
  init_channel_list(server);
  init_user_list(server);
}

void	accept_client(server_t* server)
{
  int		client_sock;

  printf("new client\n");
  client_sock = accept(server->sock, NULL, NULL);
  server->sockmax = MAX(client_sock, server->sockmax);
  add_user(server, client_sock);
}
