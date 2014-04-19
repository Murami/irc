/*
** init.c for  in /home/pinon_a/rendu/PSU_2013_myirc
** 
** Made by pinon
** Login   <pinon_a@epitech.net>
** 
** Started on  Sat Apr 19 09:29:05 2014 pinon
** Last update Sat Apr 19 10:07:41 2014 pinon
*/

#include <string.h>
#include "sockstream.h"

sockstream_t*	creat_sockstream(int socket)
{
  sockstream_t*	stream;

  stream = malloc(sizeof(sockstream));
  stream->ss_read_start = 0;
  stream->ss_read_size = 0;
  memset(stream->ss_buffer_read, 0, BUFFER_SIZE);
  stream->ss_write_start = 0;
  stream->write_size = 0;
  memset(stream->ss_buffer_write, 0, BUFFER_SIZE);
  stream->ss_socket = socket;
  return (stream);
}
