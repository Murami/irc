/*
** socketset.h for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Apr 18 15:32:33 2014 guerot_a
** Last update Fri Apr 18 15:34:11 2014 guerot_a
*/

#ifndef SOCKETSET_H
# define SOCKETSET_H

# include <sys/select.h>

typedef struct	socketset_s
{
  fd_set	ss_read_set;
  fd_set	ss_write_set;
  fd_set	ss_except_set;
  int		ss_size;
}		socketset_t;

#endif /* SOCKETSET_H */
