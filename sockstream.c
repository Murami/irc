/*
** sockstream.c for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Mon Apr 21 23:13:19 2014 guerot_a
** Last update Mon Apr 21 23:47:21 2014 guerot_a
*/

#include "myirc.h"

sockstream_t*	new_sockstream(int socket)
{
  sockstream_t*	sstream;

  sstream = malloc(sizeof(sockstream_t));
  memset(sstream, 0, sizeof(sockstream_t));
  sstream->socket = socket;
  return (sstream);
}
