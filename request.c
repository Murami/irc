/*
** request.c for  in /home/pinon_a/rendu/PSU_2013_myirc
**
** Made by pinon
** Login   <pinon_a@epitech.net>
**
** Started on  Sat Apr 19 10:05:36 2014 pinon
** Last update Sat Apr 19 15:59:39 2014 guerot_a
*/

#include <string.h>
#include <stdlib.h>
#include "sockstream.h"
#include "request.h"
#include "server.h"

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

int	parse_request(sockstream_t* stream, request_t* request)
{
  int	i;
  int	j;

  if (stream->ss_read_size == 0)
    return (0);
  request->r_type = REQ_NONE;
  i = BUFFER_SIZE - stream->ss_read_start;
  if (stream->ss_read_size < i)
    i = stream->ss_read_size;
  memset(request->r_buffer, 0, REQUEST_SIZE);
  memcpy(request->r_buffer, stream->ss_buffer_read + stream->ss_read_start, i);
  memcpy(request->r_buffer + i, stream->ss_buffer_read, stream->ss_read_size - i);
  write(1, request->r_buffer, stream->ss_read_size);
  i = 0;
  j = 0;
  while ((request->r_buffer[i] == ' ' || request->r_buffer[i] == '\t')
	 && i < stream->ss_read_size)
    i++;
  printf("%d --> %c\n", i, request->r_buffer[i]);
  if (request->r_buffer[i] == '/')
    while (pairs[j].cmd != NULL)
      {
	if (request->r_type == REQ_NONE
	    && !strncmp(pairs[j].cmd, request->r_buffer + i, strlen(pairs[j].cmd))
	    && (request->r_buffer[i + strlen(pairs[j].cmd)] == ' '
		|| request->r_buffer[i + strlen(pairs[j].cmd)] == '\n'))
	  request->r_type = pairs[j].req;
	j++;
      }
  else
    request->r_type = REQ_MSG_ALL;
  stream->ss_read_start += MIN(strchr(request->r_buffer, '\n') - request->r_buffer + 1, stream->ss_read_size);
  stream->ss_read_size -= MIN(strchr(request->r_buffer, '\n') - request->r_buffer + 1, stream->ss_read_size);
  stream->ss_read_start %= REQUEST_SIZE;
  return (1);
}
