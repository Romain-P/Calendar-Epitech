/*
** sortbye.c for sortbye.c in /home/hugo.varloud/ADM_calendar_2016/src
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 10:58:32 2017 hugo varloud
** Last update Sat Jul  1 10:30:48 2017 romain pillot
*/

#include <string.h>
#include "calendar.h"

int	sort_by_name(const void *a, const void *b)
{
  t_emp	*ax;
  t_emp	*bx;
  int	res;

  ax = *(t_emp **) a;
  bx = *(t_emp **) b;
  return ((res = strcmp(ax->first, bx->first)) ? res :
	  (res = strcmp(ax->last, bx->last)) ? res :
	  ax->id - bx->id);
}

int	sort_by_id(const void *a, const void *b)
{
  
  return (0);
}

int	sort_by_forename(const void *a, const void *b)
{
  t_emp	*ax;
  t_emp	*bx;
  int	res;

  ax = *(t_emp **) a;
  bx = *(t_emp **) b;
  return ((res = strcmp(ax->last, bx->last)) ? res :
	  (res = strcmp(ax->first, bx->first)) ? res :
	  ax->id - bx->id);
}

int	sort_by_job(const void *a, const void *b)
{
  return (0);
}

int	sort_by_zip(const void *a, const void *b)
{
  return (0);
}
