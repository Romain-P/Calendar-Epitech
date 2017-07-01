/*
** employe.c for employe.c in /home/hugo.varloud/ADM_calendar_2016/src
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 10:55:45 2017 hugo varloud
** Last update Sat Jul  1 10:30:18 2017 romain pillot
*/

#include <stdio.h>
#include "calendar.h"
#include "util.h"

void	employe_new(t_cal *cal, char **args)
{
  t_emp	*emp;

  if (tab_length(args) != 6 ||
      find_emp((t_emp **) cal->emps->values, atoi(args[5])))
    return ;
  emp = talloc(sizeof(t_emp));
  emp->last = args[1];
  emp->first = args[2];
  emp->pos = args[3];
  emp->city = args[4];
  emp->id = atoi(args[5]);
  emp->meets = array_create();
  array_add(cal->emps, emp);
}

void	employe_del(t_cal *cal, char **args)
{
  int   i;
  int	j;
  t_emp **emps;

  if (tab_length(args) != 2)
    return ;
  emps = (t_emp **) cal->emps->values;
  i = -1;
  while (emps && emps[++i])
    {
      if (emps[i]->id == atoi(args[1]))
	{
	  j = -1;
	  while (++j < emps[i]->meets->length)
	    array_rem(((t_meet *) emps[i]->meets->values[j])->emps, emps[i]);
	  array_rem(cal->emps, emps[i]);
	  break;
	}
    }
}

t_array		*array_cpy(t_array *origin)
{
  t_array	*copy;
  int		i;

  copy = array_create();
  i = -1;
  while (++i < origin->length)
    array_add(copy, origin->values[i]);
  return (copy);
}

static void	show_employe(t_cal *cal, t_emp *emp)
{
  int		i;
  int		j;
  t_meet	**meets;
  t_emp		**emps;

  printf("******************************\n");
  printf("%s %s\n", emp->first, emp->last);
  printf("position:  %s\ncity:  %s\n", emp->pos, emp->city);
  meets = (t_meet **) array_cpy(emp->meets)->values;
  qqsort(meets, tab_length(meets), sizeof(t_meet *), &sort_by_date);
  i = -1;
  while (meets && meets[++i])
    {
      if (meets[i]->emps->length <= 1)
	continue;
      printf("meeting on %s, %s, with ", meets[i]->date, meets[i]->city);
      emps = (t_emp **) array_cpy(meets[i]->emps)->values;
      qqsort(emps, tab_length(emps), sizeof(t_emp *), &sort_by_forename);
      j = -1;
      while (emps && emps[++j])
	if (emps[j] != emp)
	  printf(!j || (emps[j - 1] == emp && j == 1) ? "%s %s" : ", %s %s",
		 emps[j]->first, emps[j]->last);
      printf("\n");
    }
}

void		employe_info(t_cal *cal, char **args)
{
  int		i;
  int		j;
  t_array	*emps;
  t_emp		*found;

  if (tab_length(args) < 2 || !(emps = array_create()))
    return ;
  i = -1;
  while (g_esort[++i].name)
    if (str_equals(g_esort[i].name, args[1]))
      {
	j = 1;
	while (args[++j])
	  if ((found = find_emp((t_emp **) cal->emps->values, atoi(args[j]))))
	    array_add(emps, found);
	if (!emps->length)
	  emps = array_cpy(cal->emps);
	qqsort(emps->values, emps->length, sizeof(t_emp *), g_esort[i].sort);
        j = -1;
	while (++j < emps->length)
	  show_employe(cal, (t_emp *) emps->values[j]);
	break;
      }
}
