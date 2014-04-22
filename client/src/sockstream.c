/*
** sockstream.c for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Mon Apr 21 23:13:19 2014 guerot_a
** Last update Tue Apr 22 19:12:31 2014 pinon
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "sockstream.h"

sockstream_t*	new_sockstream(int socket)
{
  sockstream_t*	sstream;

  sstream = (sockstream_t*)malloc(sizeof(sockstream_t));
  memset(sstream, 0, sizeof(sockstream_t));
  sstream->socket = socket;
  return (sstream);
}

void	recv_sockstream(sockstream_t* sstream)
{
  int	rsize;
  int	n;

  rsize = IO_SIZE;
  if (rsize > BUFFER_SIZE - sstream->rsize)
    rsize = BUFFER_SIZE - sstream->rsize;
  if (rsize == 0)
    return;
  if (rsize + sstream->rstart > BUFFER_SIZE)
    {
      n = read(sstream->socket,
	       sstream->rbuff + sstream->rstart,
	       BUFFER_SIZE - sstream->rstart);
      if (n == BUFFER_SIZE - sstream->rstart && n != rsize)
	n += read(sstream->socket,
		  sstream->rbuff + sstream->rstart,
		  rsize - BUFFER_SIZE + sstream->rstart);
    }
  else
    n = read(sstream->socket,
	     sstream->rbuff + sstream->rstart,
	     rsize);
  sstream->rsize += n;
}

/* void	send_sockstream(sockstream_t* sstream) */
/* { */
/*   int	wsize; */
/*   int	n; */

/*   wsize = IO_SIZE; */
/*   if (wsize > sstream->wsize) */
/*     wsize = sstream->wsize; */
/*   n = write(sstream->socket, */
/* 	    sstream->wbuff + sstream->wstart, */
/* 	    wsize - (sstream->wstart + wsize) % BUFFER_SIZE); */
/*   if (n == (sstream->wstart + wsize) % BUFFER_SIZE) */
/*     n += write(sstream->socket, */
/* 	       sstream->wbuff, */
/* 	       wsize - n); */
/*   sstream->wsize -= n; */
/*   sstream->wstart = (sstream->wstart + n) % BUFFER_SIZE; */
/* } */
