/*
** request.c for  in /home/pinon_a/rendu/PSU_2013_myirc
** 
** Made by pinon
** Login   <pinon_a@epitech.net>
** 
** Started on  Sat Apr 19 10:05:36 2014 pinon
** Last update Sat Apr 19 11:01:44 2014 pinon
*/

#include <string.h>
#include <stdlib.h>
#include "request.h"

pair_request_t	pairs[] = 
  {
    {"/nick", REQUEST_NICK},
    {"/join", REQUEST_JOIN},
    {"/list", REQUEST_LIST},
    {"/part", REQUEST_PART},
    {"/users", REQUEST_USERS},
    {"/msg", REQUEST_MSG},
    {"/send_file", REQUEST_SEND_FILE},
    {"/accept_file", REQUEST_ACCEPT_FILE},
    {NULL, 0}
  };

void	parse_request(sockstream_t* stream, request_t* request)
{
  int	i;
  int	j;

  request->r_type = REQ_NONE;
  i = BUFFER_SIZE - stream->ss_buffer_start;
  if (stream->ss_buffer_size < i)
    i = stream->ss_buffer_size;
  memcpy(request->r_buffer, stream->ss_buffer_read + stream->ss_buffer_start, i);
  memcpy(request->r_buffer + i, stream->ss_buffer_read, stream->ss_buffer_size - i);
  i = 0;
  j = 0;
  while ((request->r_buffer[i] == ' ' || request->r_buffer[i] == '\t')
	 && i < stream->ss_buffer_size)
    i++;
  if (request->r_buffer[i] == "/")
    while (pairs[j].cmd != NULL)
      {
	if (!strncmp(pairs[j].cmd, request->r_buffer + i, strlen(pairs[j].cmd))
	    && request->r_buffer + i + strlen(pairs[j].cmd) + 1 == ' ')
	  request->r_type = pairs[j].req;
	j++;
      }
  else
    request->r_type = REQ_MSG_ALL;
}
