/*
** buffer_flush.c for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Mon Apr 21 19:29:20 2014 guerot_a
** Last update Mon Apr 21 22:39:39 2014 guerot_a
*/

#include "myirc.h"

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
      if (n == BUFFER_SIZE - sstream->rstart)
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

void	send_sockstream(sockstream_t* sstream)
{
  int	wsize;
  int	n;

  wsize = IO_SIZE;
  if (wsize > sstream->wsize)
    wsize = sstream->wsize;
  n = write(sstream->socket,
	    sstream->wbuff + sstream->wstart,
	    wsize - (sstream->wstart + wsize) % BUFFER_SIZE);
  if (n == (sstream->wstart + wsize) % BUFFER_SIZE)
    n += write(sstream->socket,
	       sstream->wbuff,
	       wsize - n);
  sstream->wsize -= n;
  sstream->wstart = (sstream->wstart + n) % BUFFER_SIZE;
}
