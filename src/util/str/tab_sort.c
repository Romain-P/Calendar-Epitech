/*
** tab_sort.c for tab_sort.c in /home/hugo.varloud/ADM_calendar_2016/src/util/str
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 11:08:59 2017 hugo varloud
** Last update Sat Jul  1 11:09:02 2017 hugo varloud
*/

#include "util.h"

void	tab_sort(char **tab)
{
  int	i;
  int	j;
  char	*tmp;
  bool	changed;

  i = -1;
  changed = false;
  while (tab && tab[++i] && (j = -1))
    while (i && tab[i - 1][++j] && tab[i][j])
      if (tab[i - 1][j] > tab[i][j] ||
	  (tab[i][j] == tab[i -1][j] && !tab[i][j + 1]))
	{
	  tmp = tab[i - 1];
	  tab[i - 1] = tab[i];
	  tab[i] = tmp;
	  changed = true;
	  break;
	}
      else if (tab[i][j] != tab[i - 1][j])
	break;
  if (changed)
    tab_sort(tab);
}
