/*
** str_contains.c for str_contains.c in /home/hugo.varloud/ADM_calendar_2016/src/util/str
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 11:03:48 2017 hugo varloud
** Last update Sat Jul  1 11:03:51 2017 hugo varloud
*/

#include "util.h"

bool	str_contains(const char *str, const char *charset)
{
  int   i;

  i = 0;
  if (!charset || !(*charset))
    return (false);
  while (str && *str)
    if (*str++ == charset[i])
      if (!(charset[++i]))
	return (true);
      else
	continue;
    else
      i= 0;
  return (false);
}
