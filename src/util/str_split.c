/*
** str_split.c for str_split.c in /home/hugo.varloud/ADM_calendar_2016/src/util/str
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 11:07:41 2017 hugo varloud
** Last update Sat Jul  1 11:07:43 2017 hugo varloud
*/

#include <stdlib.h>
#include "util.h"

char    **str_split(char *str, const char delimiter)
{
  char  **tab;
  char  *hold;
  int   i;
  int   j;
  int   k;
  bool	ignore;

  i = -1;
  hold = str;
  if (!(tab = malloc(sizeof(char *) * ((str_countchar(str, delimiter) + 2)))))
    return (NULL);
  k = 0;
  ignore = false;
  while (str[++i])
    {
      ignore = str[i] == '"' ? !ignore : ignore;
      if (!ignore && (str[(j = i)] == delimiter || !(str[(j = i + 1)])))
	{
	  tab[k++] = hold;
	  hold = str + j + 1;
	  str[j] = 0;
	}
    }
  tab[k] = 0;
  return (tab);
}
