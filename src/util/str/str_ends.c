/*
** str_ends.c for str_ends.c in /home/hugo.varloud/ADM_calendar_2016/src/util/str
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 11:05:31 2017 hugo varloud
** Last update Sat Jul  1 11:05:32 2017 hugo varloud
*/

#include "util.h"

bool	str_ends(char const *str, char const *charset)
{
  int	len;

  if ((len = str_length(str) - str_length(charset)) < 0)
    return (false);
  return (str_equals(str + len, charset));
}
