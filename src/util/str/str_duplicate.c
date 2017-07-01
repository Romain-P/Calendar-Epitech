/*
** str_duplicate.c for str_duplicate.c in /home/hugo.varloud/ADM_calendar_2016/src/util/str
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 11:04:52 2017 hugo varloud
** Last update Sat Jul  1 11:04:53 2017 hugo varloud
*/

#include <stdlib.h>
#include "util.h"

char	*str_dupl(const char *str)
{
  char  *new;
  char  *hold;

  if (!(hold = (new = malloc(sizeof(char) * (str_length(str) + 1)))))
    return (NULL);
  while (*str)
    *new++ = *str++;
  *new = 0;
  return (hold);
}

char	*str_dupli(const char *str, int len)
{
  char  *new;
  int	i;

  if (!(new = malloc(sizeof(char) * (len + 1))))
    return (NULL);
  new[len] = 0;
  i = -1;
  while (++i < len)
    new[i] = str[i];
  return (new);
}
