/*
** util.h for  in /home/romain.pillot/projects/ghoulc/inc
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue May 23 14:02:04 2017 romain pillot
** Last update Fri Jun 30 17:59:21 2017 romain pillot
*/

#ifndef CALENDAR_H_
# define CALENDAR_H_

# include "array.h"

typedef struct	s_emp
{
  int		id;
  char		*first;
  char		*last;
  char		*pos;
  char		*city;
}		t_emp;


typedef struct	s_meet
{
  char		*date;
  char		*city;
  t_array	*emps;
}		t_meet;

typedef struct	s_cal
{
  t_array	*emps;
  t_array	*meets;
}		t_cal;

typedef struct	s_func
{
  char const	*label;
  void		(*func)(t_cal *cal, char **args);
}		t_func;

void	employe_new(t_cal *cal, char **args);

void	employe_del(t_cal *cal, char **args);

void	employe_info(t_cal *cal, char **args);

void	meeting_new(t_cal *cal, char **args);

void	meeting_del(t_cal *cal, char **args);

void	meeting_invite(t_cal *cal, char **args);

void	meeting_exclude(t_cal *cal, char **args);

void	meeting_info(t_cal *cal, char **args);

#endif /* !CALENDAR_H_ */
