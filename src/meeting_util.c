/*
** meeting_util.c for meeting_util.c in /home/hugo.varloud/ADM_calendar_2016/src
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 10:58:02 2017 hugo varloud
** Last update Sat Jul  1 10:58:04 2017 hugo varloud
*/

#include <stdio.h>
#include "calendar.h"
#include "util.h"

void		show_meeting(t_cal *cal, t_meet *meet)
{
  t_emp		**emps;
  int		i;

  if (meet->emps->length <= 1)
    return ;
  printf("******************************\nMEETING\n");
  printf("date:  %s\n", meet->date);
  printf("place:  %s\n", meet->city);
  printf("with ");
  emps = (t_emp **) array_cpy(meet->emps)->values;
  qqsort(emps, meet->emps->length, sizeof(t_emp *), &sort_by_name);
  i = -1;
  while (emps && emps[++i])
    printf(!i ? "%s %s" : ", %s %s", emps[i]->first, emps[i]->last);
  printf("\n");
}

/* delete useless meetings (1 ppl) */
void		check_meetings(t_cal *cal)
{
  int		i;
  int		j;
  t_meet	**meets;
  t_meet	*found;
  t_emp		**emps;

  meets = (t_meet **) cal->meets->values;
  j = -1;
  while (meets && meets[++j])
    {
      if ((found = meets[j])->emps->length <= 1)
	{
	  emps = (t_emp **) found->emps->values;
	  i = -1;
	  while (emps && emps[++i])
	    array_rem(emps[i]->meets, found);
	  array_rem(cal->meets, found);
	}
    }
}
