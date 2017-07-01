/*
** str_isnumber.c for str_isnumber.c in /home/hugo.varloud/ADM_calendar_2016/src/util/str
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 11:21:24 2017 hugo varloud
** Last update Sat Jul  1 11:21:25 2017 hugo varloud
*/

#include <stdbool.h>
#include "util.h"

bool	str_isnumber(const char *str)
{
  int	i;

  if (!str)
    return (false);
  i = 0;
  while ((str[i] == '+' || str[i] == '-') && ++i);
  while (str[i++])
    if (!(str[i - 1] >= '0' && str[i - 1] <= '9'))
      return (false);
  return (true);
}
