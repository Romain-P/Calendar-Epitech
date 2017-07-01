/*
** str_concat.c for str_concat.c in /home/hugo.varloud/ADM_calendar_2016/src/util/str
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 11:03:16 2017 hugo varloud
** Last update Sat Jul  1 11:03:18 2017 hugo varloud
*/

#include <stdlib.h>
#include "util.h"

char	*str_concat(char *a, const char *b, bool free_a)
{
  char	*concat;
  char	*hold;
  char	*hold_a;

  if (!(hold = (concat = malloc(sizeof(char) * (str_length(a) +
						str_length(b) + 1)))))
    return (NULL);
  hold_a = a;
  while (a && *a)
    *concat++ = *a++;
  while (b && *b)
    *concat++ = *b++;
  *concat = 0;
  if (free_a && hold_a)
    free(hold_a);
  return (hold);
}
