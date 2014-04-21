/*
** list.c for  in /home/guerot_a/rendu/PSU_2013_myirc
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Mon Apr 21 22:46:44 2014 guerot_a
** Last update Tue Apr 22 00:07:38 2014 guerot_a
*/

#include <stdlib.h>
#include "list.h"

list_t*	new_list()
{
  list_t*	l;

  l = (list_t*)malloc(sizeof(list_t));
  l->size = 0;
  l->root = (list_elm_t*)malloc(sizeof(list_elm_t));
  l->root->next = l->root;
  l->root->prev = l->root;
  l->root->data = NULL;
  return (l);
}

void	list_push_back(list_t* list, void* data)
{
  list_elm_t*	elm;

  elm = (list_elm_t*)malloc(sizeof(list_elm_t));
  elm->next = list->root;
  elm->prev = list->root->prev;
  elm->data = data;
  list->root->prev->next = elm;
  list->root->prev = elm;
  list->size++;
}

void	list_push_front(list_t* list, void* data)
{
  list_elm_t*	elm;

  elm = (list_elm_t*)malloc(sizeof(list_elm_t));
  elm->next = list->root->next;
  elm->prev = list->root;
  elm->data = data;
  list->root->next->prev = elm;
  list->root->next = elm;
  list->size++;
}

void	list_pop_back(list_t* list)
{
  list_elm_t*	elm;

  elm = (list_elm_t*)list->root->prev;
  elm->prev->next = list->root;
  list->root->prev = elm->prev;
  free(elm);
  list->size--;
}

void	list_pop_front(list_t* list)
{
  list_elm_t*	elm;

  elm = (list_elm_t*)list->root->prev;
  elm->prev->next = list->root;
  list->root->prev = elm->prev;
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
