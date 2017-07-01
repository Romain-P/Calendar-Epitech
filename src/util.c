/*
** util.c for  in /home/romain.pillot/projects/romhug/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sat Jul  1 00:31:28 2017 romain pillot
** Last update Sat Jul  1 02:47:41 2017 romain pillot
*/

#include "calendar.h"
#include "util.h"

t_emp	*find_emp(t_emp **emps, int id)
{
  int	i;

  i = -1;
  while (emps && emps[++i])
    if (emps[i]->id == id)
      return (emps[i]);
  return (NULL);
}

t_meet	*find_meet(t_meet **meets, int id)
{
  int	i;

  i = -1;
  while (meets && meets[++i])
    if (meets[i]->id == id)
      return (meets[i]);
  return (NULL);
}

static bool	digit(char c)
{
  return (c >= '0' && c <= '9');
}

bool	valid_date(char *date)
{return (date &&
	 digit(date[0]) &&
	 digit(date[1]) &&
	 date[2] == '/' &&
	 digit(date[3]) &&
	 digit(date[4]) &&
	 date[5] == '/' &&
	 digit(date[6]) &&
	 digit(date[7]) &&
	 digit(date[8]) &&
	 digit(date[9]) &&
	 !date[10]);
}

bool	array_contains(t_array *array, void *ptr)
{
  int	i;

  i = -1;
  while (++i < array->length)
    if (array->values[i] == ptr)
      return (true);
  return (false);
}
