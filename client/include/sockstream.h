/*
** sockstream.h for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Apr 18 15:15:22 2014 guerot_a
** Last update Tue Apr 22 19:10:42 2014 pinon
*/

#ifndef SOCKSTREAM_H
# define SOCKSTREAM_H

# include "constants.h"

typedef struct	sockstream_s
{
  int		rstart;
  int		rsize;
  char		rbuff[BUFFER_SIZE];
  int		socket;
}		sockstream_t;

#endif /* SOCKSTREAM_H */
