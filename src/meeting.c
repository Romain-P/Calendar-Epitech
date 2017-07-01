/*
** meeting.c for meeting.c in /home/hugo.varloud/ADM_calendar_2016/src
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 10:57:38 2017 hugo varloud
** Last update Sat Jul  1 10:12:46 2017 romain pillot
*/

#include "calendar.h"
#include "util.h"

void		meeting_new(t_cal *cal, char **args)
{
  t_meet	*meet;
  int		i;
  t_emp		*found;

  if (tab_length(args) < 4 || !valid_date(args[2]) ||
      find_meet((t_meet **) cal->meets->values, atoi(args[3])))
    return ;
  meet = talloc(sizeof(t_meet));
  meet->city = args[1];
  meet->date = args[2];
  meet->id = atoi(args[3]);
  meet->emps = array_create();
  i = 3;
  while (args[++i])
    if ((found = find_emp((t_emp **) cal->emps->values, atoi(args[i]))) &&
	!array_contains(meet->emps, found))
      {
	array_add(meet->emps, found);
	if (!array_contains(found->meets, meet))
	  array_add(found->meets, meet);
      }
  array_add(cal->meets, meet);
}

void		meeting_del(t_cal *cal, char **args)
{
  int		i;
  int		j;
  t_emp		**emps;
  t_meet	*found;

  j = 0;
  while (args[++j])
    {
      if (!(found = find_meet((t_meet **) cal->meets->values, atoi(args[j]))))
	continue;
      emps = (t_emp **) found->emps->values;
      i = -1;
      while (emps && emps[++i])
	array_rem(emps[i]->meets, found);
      array_rem(cal->meets, found);
    }
}

void		meeting_invite(t_cal *cal, char **args)
{
  int		i;
  t_meet	*found;
  t_emp		**emps;
  t_emp		*emp;

  if (tab_length(args) < 2 ||
      !(found = find_meet((t_meet **) cal->meets->values, atoi(args[1]))))
    return ;
  i = 1;
  while (args[++i])
    {
      if (!(emp = find_emp((t_emp **) cal->emps->values, atoi(args[i]))))
	continue;
      if (!array_contains(emp->meets, found))
	array_add(emp->meets, found);
      if (!array_contains(found->emps, emp))
	array_add(found->emps, emp);
    }
}

void		meeting_exclude(t_cal *cal, char **args)
{
  int		i;
  t_meet	*found;
  t_emp		**emps;
  t_emp		*emp;

  if (tab_length(args) < 2 ||
      !(found = find_meet((t_meet **) cal->meets->values, atoi(args[1]))))
    return ;
  i = 1;
  while (args[++i])
    {
      if (!(emp = find_emp((t_emp **) cal->emps->values, atoi(args[i]))))
	continue;
      array_rem(emp->meets, found);
      array_rem(found->emps, emp);
    }
}

void		meeting_info(t_cal *cal, char **args)
{
  int		i;
  int		j;
  t_array	*meets;
  t_meet	*found;

  if (tab_length(args) < 2 || !(meets = array_create()))
    return ;
  i = -1;
  while (g_msort[++i].name)
    if (str_equals(g_msort[i].name, args[1]))
      {
	j = 1;
	while (args[++j])
	  if ((found = find_meet((t_meet **) cal->meets->values, atoi(args[j]))))
	    array_add(meets, found);
	if (!meets->length)
	  meets = array_cpy(cal->meets);
	qqsort(meets->values, meets->length, sizeof(t_meet *), g_msort[i].sort);
	j = -1;
	while (++j < meets->length)
	  show_meeting(cal, (t_meet *) meets->values[j]);
	break;
      }
}
