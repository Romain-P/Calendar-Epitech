/*
** str_length.c for str_lenght.c in /home/hugo.varloud/ADM_calendar_2016/src/util/str
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 11:21:51 2017 hugo varloud
** Last update Sat Jul  1 11:21:52 2017 hugo varloud
*/

#include "util.h"

int     str_length(const char *str)
{
  int	i;

  i = 0;
  while (str && str[i] && ++i);
  return (i);
}

int	tab_length(void  *ptr)
{
  int	i;
  void	**tab;

  tab = (void **) ptr;
  i = 0;
  while (tab && tab[i] && ++i);
  return (i);
}
