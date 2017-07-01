/*
** tricky.c for  in /home/romain.pillot/projects/romhug/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Jun 30 17:01:24 2017 romain pillot
** Last update Sat Jul  1 01:17:43 2017 romain pillot
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
