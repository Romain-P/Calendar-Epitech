/*
** meeting_util.c for  in /home/romain.pillot/projects/romhug/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sat Jul  1 03:09:13 2017 romain pillot
** Last update Sat Jul  1 03:49:23 2017 romain pillot
*/

#include <stdio.h>
#include "calendar.h"
#include "util.h"

void		show_meeting(t_cal *cal, t_meet *meet)
{
  t_emp		**emps;
  int		i;

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