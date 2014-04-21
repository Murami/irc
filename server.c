/*
** server.c for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Mon Apr 21 19:32:20 2014 guerot_a
** Last update Mon Apr 21 19:33:39 2014 guerot_a
*/

void	init_user_list(server_t* server)
{
  init_list(server->users);
}

void	init_channel_list(server_t* server)
{
  init_list(server->chans);
  add_channel("chan1");
  add_channel("chan2");
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
  int		empty_u;
  int		client_sock;

  client_sock = accept(server->s_socket, NULL, NULL);
  server->s_socket_max = MAX(client_sock, server->s_socket_max);
  add_unregistered(server, client_sock);
}
