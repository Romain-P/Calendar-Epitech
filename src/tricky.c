/*
** tricky.c for tricky.c in /home/hugo.varloud/ADM_calendar_2016/src
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 10:59:22 2017 hugo varloud
** Last update Sat Jul  1 10:59:23 2017 hugo varloud
*/

#include <stdlib.h>
#include "util.h"

void	*talloc(size_t s)
{
  void	*alloc;

  if (!(alloc = malloc(s)))
    exit(EXIT_FAILURE);
  return (alloc);
}

void	qqsort(void *base, size_t nitems, size_t size,
	       int (*compar)(const void *a, const void *b))
{
  if (!base || !nitems || !size || !compar)
    return ;
  qsort(base, nitems, size, compar);
}
