/*
** cmd_list.c for  in /home/pinon_a/rendu/PSU_2013_myirc
**
** Made by pinon
** Login   <pinon_a@epitech.net>
**
** Started on  Fri Apr 18 13:39:52 2014 pinon
** Last update Mon Apr 21 19:00:51 2014 guerot_a
*/

#include <stdlib.h>
#include <stdio.h>
#include "channel.h"

void	cmd_list(char *str, channel_t *channels, int channel_amount)
{
  int	i;

  i = 0;
  while (i < channel_amount)
    {
      if (str == NULL)
	printf("%s\n", channels[i].c_name);
      else if (str != NULL && str_match(str, channels[i].c_name))
	printf("%s\n", channels[i].c_name);
      i++;
    }
}

/* LIST CHAINÉ ... */

void	init_root(list_elm_t* root)
{
  root->next = root;
  root->prev = root;
  root->data = NULL;
}

void	init_list(list_t* l)
{
  init_root(l->root);
  l->size = 0;
}

list_t*	new_list()
{
  list_t*	l;

  l = malloc(sizeof(list_t));
  init_list(l);
  return (l);
}

void	list_push_back(list_t* list, void* elm)
{
  list_elm_t*	elm;

  elm = malloc(sizeof(list_elm_t));
  elm->next = list->root;
  elm->prev = list->root->prev;
  list->root->prev->next = elm;
  list->root->prev = elm;
  list->size++;
}

void	list_push_front(list_t* list, void* elm)
{
  list_elm_t*	elm;

  elm = malloc(sizeof(list_elm_t));
  elm->next = list->root->next;
  elm->prev = list->root;
  list->root->next->prev = elm;
  list->root->next = elm;
  list->size++;
}

void	list_pop_back(list_t* list)
{
  list_elm_t*	elm;

  elm = list->root->prev;
  elm->prev->next = root;
  root->prev = elm->prev;
  free(elm);
  list->size--;
}

void	list_pop_front(list_t* list)
{
  list_elm_t*	elm;

  elm = list->root->prev;
  elm->prev->next = root;
  root->prev = elm->prev;
  free(elm);
  list->size--;
}

void	list_erase(list_t* list, list_elm_t* elm)
{
  if (!list->size)
    return;
  elm->next->prev = elm->prev;
  elm->prev->next = elm->next;
  list->size--;
}
