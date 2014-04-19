/*
** sockstream.h for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Apr 18 15:15:22 2014 guerot_a
** Last update Fri Apr 18 15:37:41 2014 guerot_a
*/

#ifndef SOCKSTREAM_H
# define SOCKSTREAM_H

# define BUFFER_SIZE	4096
# define IO_SIZE	512

typedef struct	sockstream_s
{
  int		ss_read_start;
  int		ss_read_size;
  char		ss_buffer_read[BUFFER_SIZE];
  int		ss_write_start;
  int		ss_write_size;
  char		ss_buffer_write[BUFFER_SIZE];
  int		ss_socket;
}		sockstream_t;

#endif /* SOCKSTREAM_H */