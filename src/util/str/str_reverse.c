/*
** str_reverse.c for str_reverse.c in /home/hugo.varloud/ADM_calendar_2016/src/util/str
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 11:07:19 2017 hugo varloud
** Last update Sat Jul  1 11:07:21 2017 hugo varloud
*/

#include "util.h"

char	*str_reverse(char *str)
{
  int	a;
  int	b;
  int	mid;
  char	tmp;

  a = (b = 0);
  while (str && str[b] && ++b);
  mid = (--b) / 2 + 1;
  while (str && a != mid)
    {
      tmp = str[a];
      str[a++] = str[b];
      str[b--] = tmp;
    }
  return (str);
}
