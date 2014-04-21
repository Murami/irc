/*
** list.h for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Mon Apr 21 18:39:56 2014 guerot_a
** Last update Mon Apr 21 19:21:16 2014 guerot_a
*/

#ifndef LIST_H
# define LIST_H

# define LISTEND(l)	(l->root);
# define LISTBEGIN(l)	(l->root->next);
# define INC(l)		(l = l->next);

typedef struct		list_elm_s
{
  struct list_elm_s*	prev;
  struct list_elm_s*	next;
  void*			data;
}			list_elm_t;

typedef struct	list_s
{
  int		size;
  list_elm_t	root;
}		list_t;

#endif /* LIST_H */
