/*
** list.c for list.c in /home/hugo.varloud/ADM_calendar_2016/src/util
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 11:01:00 2017 hugo varloud
** Last update Sat Jul  1 11:01:01 2017 hugo varloud
*/

#include <stdlib.h>
#include "list.h"

t_list		*list_create()
{
  t_list	*list;

  if (!(list = malloc(sizeof(t_list))))
    return (NULL);
  list->size = 0;
  list->first = NULL;
  list->last = NULL;
  return (list);
}

t_elem		*list_add(t_list *list, void *data)
{
  t_elem	*elem;

  if (!(elem = malloc(sizeof(t_elem))))
    return (NULL);
  elem->get = data;
  elem->next = NULL;
  elem->previous = list->last;
  if (list->last)
    {
      list->last->next = elem;
      list->last = elem;
    }
  else
    {
      list->first = elem;
      list->last = elem;
    }
  list->size++;
  return (elem);
}

void		*list_dremove(t_list *list, void **data)
{
  t_elem	*elem;

  elem = list->first;
  while (elem)
    if (elem->get == *data || !(elem = elem->next))
      break;
  return (elem ? list_eremove(list, elem) : NULL);
}

void		*list_eremove(t_list *list, t_elem *elem)
{
  void		*data;

  if (elem->previous)
    elem->previous->next = elem->next;
  else
    list->first = elem->next;
  if (elem->next)
    elem->next->previous = elem->previous;
  else
    list->last = elem->previous;
  data = elem->get;
  free(elem);
  list->size--;
  return (data);
}

void		list_removeall(t_list *list, bool free_data)
{
  t_elem        *elem;
  t_elem	*next;
  void		*data;

  elem = list->first;
  while (elem)
    {
      next = elem->next;
      data = list_eremove(list, elem);
      if (free_data && data)
	free(data);
      elem = next;
    }
}
