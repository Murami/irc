/*
** request.c for  in /home/pinon_a/rendu/PSU_2013_myirc
**
** Made by pinon
** Login   <pinon_a@epitech.net>
**
** Started on  Sat Apr 19 10:05:36 2014 pinon
** Last update Mon Apr 21 23:45:29 2014 guerot_a
*/

#include "myirc.h"

pair_request_t	pairs[] =
  {
    {"/nick", REQ_NICK},
    {"/join", REQ_JOIN},
    {"/list", REQ_LIST},
    {"/part", REQ_PART},
    {"/users", REQ_USERS},
    {"/msg", REQ_MSG},
    {"/send_file", REQ_SEND_FILE},
    {"/accept_file", REQ_ACCEPT_FILE},
    {NULL, 0}
  };

void parse_args(char **tab, char *str)
{
  str[index(str, '\n') - str + 1] = '\0';
  strtok(str, " ");
  tab[0] = strtok(NULL, " ");
  tab[1] = strtok(NULL, " ");
}

int	parse_request(sockstream_t* stream, request_t* request)
{
  int	i;
  int	j;

  if (stream->rsize == 0)
    return (0);
  printf("1 - size = %d\n", stream->rsize);
  printf("1 - start = %d\n", stream->rstart);
  request->type = REQ_NONE;
  i = BUFFER_SIZE - stream->rstart;
  if (stream->rsize < i)
    i = stream->rsize;
  memset(request->buffer, 0, REQUEST_SIZE);
  memcpy(request->buffer, stream->rbuff + stream->rstart, i);
  memcpy(request->buffer + i, stream->rbuff, stream->rsize - i);
  write(1, request->buffer, stream->rsize);
  i = 0;
  j = 0;
  while ((request->buffer[i] == ' ' || request->buffer[i] == '\t')
	 && i < stream->rsize)
    i++;
  printf("%d --> %c\n", i, request->buffer[i]);
  if (request->buffer[i] == '/')
    while (pairs[j].cmd != NULL)
      {
	if (request->type == REQ_NONE
	    && !strncmp(pairs[j].cmd, request->buffer + i, strlen(pairs[j].cmd))
	    && (request->buffer[i + strlen(pairs[j].cmd)] == ' '
		|| request->buffer[i + strlen(pairs[j].cmd)] == '\n'))
	  request->type = pairs[j].req;
	j++;
      }
  else
    request->type = REQ_MSG_ALL;
  if (!strchr(request->buffer, '\n'))
    {
      stream->rsize = 0;
      stream->rstart = 0;
    }
  else
    {
      stream->rstart += MIN(strchr(request->buffer, '\n') - request->buffer + 1, stream->rsize);
      stream->rsize -= MIN(strchr(request->buffer, '\n') - request->buffer + 1, stream->rsize);
      stream->rstart %= REQUEST_SIZE;
    }

  printf("2 - size = %d\n", stream->rsize);
  printf("2 - start = %d\n", stream->rstart);
  return (1);
}
