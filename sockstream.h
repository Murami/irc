/*
** sockstream.h for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Apr 18 15:15:22 2014 guerot_a
** Last update Mon Apr 21 18:26:51 2014 guerot_a
*/

#ifndef SOCKSTREAM_H
# define SOCKSTREAM_H

# define BUFFER_SIZE	4096
# define REQUEST_SIZE	512
# define IO_SIZE	REQUEST_SIZE

typedef struct	sockstream_s
{
  int		rstart;
  int		rsize;
  char		rbuff[BUFFER_SIZE];
  int		wstart;
  int		wsize;
  char		wbuffer[BUFFER_SIZE];
  int		socket;
}		sockstream_t;

#endif /* SOCKSTREAM_H */
