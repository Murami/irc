/*
** socketset.h for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Apr 18 15:32:33 2014 guerot_a
** Last update Mon Apr 21 22:28:19 2014 guerot_a
*/

#ifndef SOCKETSET_H
# define SOCKETSET_H

# include "dependencies.h"

typedef struct	socketset_s
{
  fd_set	read_set;
  fd_set	write_set;
  fd_set	except_set;
  int		size;
}		socketset_t;

#endif /* SOCKETSET_H */
