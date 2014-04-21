/*
** init.c for  in /home/pinon_a/rendu/PSU_2013_myirc
**
** Made by pinon
** Login   <pinon_a@epitech.net>
**
** Started on  Sat Apr 19 09:29:05 2014 pinon
** Last update Tue Apr 22 00:06:20 2014 guerot_a
*/

#include "myirc.h"

sockstream_t*	create_sockstream(int socket)
{
  sockstream_t*	stream;

  stream = (sockstream_t*)malloc(sizeof(sockstream_t));
  stream->rstart = 0;
  stream->rsize = 0;
  memset(stream->rbuff, 0, BUFFER_SIZE);
  stream->wstart = 0;
  stream->wsize = 0;
  memset(stream->wbuff, 0, BUFFER_SIZE);
  stream->socket = socket;
  return (stream);
}
