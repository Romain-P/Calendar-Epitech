/*
** tab_contains.c for tab_contains.c in /home/hugo.varloud/ADM_calendar_2016/src/util/str
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 11:08:38 2017 hugo varloud
** Last update Sat Jul  1 11:08:40 2017 hugo varloud
*/

#include "util.h"

bool	tab_contains(char **tab, const char *str)
{
  while (tab && *tab)
    if (str_equals(*tab++, str))
      return (true);
  return (false);
}
