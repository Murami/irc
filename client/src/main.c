/*
** main.c for  in /home/guerot_a/rendu/PSU_2013_myirc/client
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Apr 19 10:51:25 2014 guerot_a
** Last update Tue Apr 22 16:04:26 2014 pinon
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#include <pthread.h>

#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "client.h"

int isnumeric(char *str)
{
  while(*str)
    {
      if(!isdigit(*str))
	return (0);
      str++;
    }
  return (1);
}

int	get_port(char* port)
{
  int ret;

  if (!isnumeric(port) || strlen(port) > 10)
    {
      printf("Error: invalid port\n");
      return (0);
    }
  else if (strlen(port) == 10 && strcmp("2147483647", port) < 0)
    {
      printf("Error: invalid port\n");
      return (0);
    }
  ret = atoi(port);
  if (ret == 0)
    printf("Error: invalid port\n");
  return (ret);
}

in_addr_t	get_addr(char *ip)
{
  in_addr_t ret;

  if (strcmp(ip, "localhost") == 0)
    ret = inet_addr("192.0.0.1");
  else
    ret = inet_addr(ip);
  if (ret == (in_addr_t)(-1))
    printf("Error: invalid ip\n");
  return (ret);
}

int	init_client(client_t* client, char **argv)
{
  struct protoent*	protocol;
  struct sockaddr_in	sin;
  int			port;

  if (!(port = get_port(argv[1])))
    return (0);
  protocol = getprotobyname("TCP");
  if ((client->socket = socket(AF_INET, SOCK_STREAM, protocol->p_proto)) < 0)
    {
      printf("Error: init socket failure\n");
      return (0);
    }
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  if ((sin.sin_addr.s_addr = get_addr(argv[0])) == (in_addr_t)(-1))
    return (0);
  if (connect(client->socket, (const struct sockaddr*)&sin, sizeof(sin)) == -1)
    {
      printf("Error: connect failure\n");
      close(client->socket);
      return (0);
    }
  return (1);
}

void	format_buffer(char* buffer, char* formated_buffer)
{
  int	i = 0;
  char*	token;

  while ((token = strtok(buffer, " ")))
    {
      memcpy(formated_buffer + i, token, strlen(token));
      i += strlen(token) + 1;
      buffer = NULL;
    }
  formated_buffer[i] = '\0';
}

void*	client_read(void *p)
{
  client_t*	client;
  char		buffer[IO_SIZE + 1];

  client = (client_t*)p;
  while (42)
    {
      memset(buffer, 0, IO_SIZE + 1);
      if (read(client->socket, &buffer, IO_SIZE) <= 0)
	{
	  printf("server disconnected\n");
	  return (NULL);
	}
      else
	printf("read = %s\n", buffer);
    }
  return (NULL);
}

void*	client_write(void *p)
{
  client_t*     client;
  int		size;
  char		buffer[IO_SIZE + 1];
  char		formated_buffer[IO_SIZE + 1];

  client = (client_t*)p;
  while (42)
    {
      system("clear");
      write(1, "client >", 8);
      memset(buffer, 0, IO_SIZE + 1);
      memset(formated_buffer, ' ', IO_SIZE + 1);
      size = read(0, buffer, IO_SIZE);
      fflush(0);
      format_buffer(buffer, formated_buffer);
      write(client->socket, formated_buffer, size);
    }
  return (NULL);
}

int	main(int argc, char **argv)
{
  client_t client;
  pthread_t pthread_r;
  pthread_t pthread_w;

  if (argc != 3)
    {
      printf("usage: %s ip port\n", argv[0]);
      return (EXIT_FAILURE);
    }
  if (!init_client(&client, argv + 1))
    return (EXIT_FAILURE);
  pthread_create (&pthread_r, NULL, client_read, &client);
  pthread_create (&pthread_w, NULL, client_write, &client);
  pthread_join (pthread_r, NULL);
  return (0);
}
