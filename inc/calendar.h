/*
** calendar.h for  in /home/romain.pillot/projects/romhug
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Jun 30 22:49:08 2017 romain pillot
** Last update Sat Jul  1 03:38:27 2017 romain pillot
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
  t_array	*meets;
}		t_emp;

typedef struct	s_meet
{
  int		id;
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

typedef struct	s_sort
{
  char const	*name;
  int		(*sort)(const void *a, const void *b);
}		t_sort;

extern const t_sort	g_esort[];

extern const t_sort	g_msort[];

bool	array_contains(t_array *array, void *ptr);

void	check_meetings(t_cal *cal);

void	show_meeting(t_cal *cal, t_meet *meet);

t_emp	*find_emp(t_emp **emps, int id);

t_meet	*find_meet(t_meet **meets, int id);

t_array	*array_cpy(t_array *array);

bool	valid_date(char *date);

void	employe_new(t_cal *cal, char **args);

void	employe_del(t_cal *cal, char **args);

void	employe_info(t_cal *cal, char **args);

void	meeting_new(t_cal *cal, char **args);

void	meeting_del(t_cal *cal, char **args);

void	meeting_invite(t_cal *cal, char **args);

void	meeting_exclude(t_cal *cal, char **args);

void	meeting_info(t_cal *cal, char **args);

int     sort_by_date(const void *a, const void *b);

int     sort_by_zip(const void *a, const void *b);

int	sort_by_zip_alt(const void *a, const void *b);

int     sort_by_id(const void *a, const void *b);

int     sort_by_name(const void *a, const void *b);

int     sort_by_forename(const void *a, const void *b);

int     sort_by_job(const void *a, const void *b);

int     sort_by_zip(const void *a, const void *b);

int     sort_by_id(const void *a, const void *b);

int	sort_by_id_alt(const void *a, const void *b);

#endif /* !CALENDAR_H_ */
