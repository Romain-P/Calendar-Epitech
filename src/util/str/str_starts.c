/*
** str_starts.c for str_starts.c in /home/hugo.varloud/ADM_calendar_2016/src/util/str
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 11:08:13 2017 hugo varloud
** Last update Sat Jul  1 11:08:15 2017 hugo varloud
*/

#include "util.h"

bool	str_starts(const char *str, const char *charset)
{
  if (!str || !charset)
    return (false);
  while (*charset)
    if (*str++ != *charset++)
      return (false);
  return (true);
}
