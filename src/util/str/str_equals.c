/*
** str_equals.c for str_equals.c in /home/hugo.varloud/ADM_calendar_2016/src/util/str
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 11:20:16 2017 hugo varloud
** Last update Sat Jul  1 11:20:18 2017 hugo varloud
*/

#include "util.h"

bool	str_equals(const char *a, const char *b)
{
  if (!a || !b)
    return (!a && !b);
  while (*a || *b)
    if (*a++ != *b++)
      return (false);
  return (true);
}
