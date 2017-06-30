/*
** employe.c for  in /home/romain.pillot/projects/romhug/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Jun 30 17:30:46 2017 romain pillot
** Last update Fri Jun 30 19:25:09 2017 romain pillot
*/

#include "calendar.h"
#include "util.h"

void	employe_new(t_cal *cal, char **args)
{
  t_emp	*emp;

  if (tab_length(args) != 6)
    return ;
  emp = talloc(sizeof(t_emp));
  emp->last = args[1];
  emp->first = args[2];
  emp->pos = args[3];
  emp->city = args[4];
  emp->id = atoi(args[5]);
  array_add(cal->emps, emp);
}

void	employe_del(t_cal *cal, char **args)
{
  int   i;
  t_emp **emps;

  if (tab_length(args) != 2)
    return ;
  emps = cal->emps->values;
  i = -1;
  while (emps && emps[++i])
    {
      if (emps[i]->id == atoi(args[1]))
	{
	  array_rem(cal->emps, emps[i]);
	  break;
	}
    }
}

void	employe_info(t_cal *cal, char **args)
{
  
}
