/*
** str_countchar.c for str_countchar.c in /home/hugo.varloud/ADM_calendar_2016/src/util/str
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 11:04:17 2017 hugo varloud
** Last update Sat Jul  1 11:04:18 2017 hugo varloud
*/

#include "util.h"

int     str_countchar(const char *str, const char c)
{
  int   i;
  int   j;

  i = (j = 0);
  while (str && str[i] && ++i)
    if (str[i] == c)
      j++;
  return (j);
}
