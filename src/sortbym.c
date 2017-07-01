/*
** sortbym.c for sortbym.c in /home/hugo.varloud/ADM_calendar_2016/src
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 10:58:53 2017 hugo varloud
** Last update Sat Jul  1 11:12:58 2017 romain pillot
*/

#include <string.h>
#include "calendar.h"

int		sort_by_date(const void *a, const void *b)
{
  t_meet	*ax;
  t_meet	*bx;
  int		res;

  ax = *(t_meet **) a;
  bx = *(t_meet **) b;
  return ((res = strcmp(ax->date, bx->date)) ? res :
	  ax->id - bx->id);
}

int	sort_by_zip_alt(const void *a, const void *b)
{
  t_meet        *ax;
  t_meet        *bx;
  int           res;

  ax = *(t_meet **) a;
  bx = *(t_meet **) b;
  return (!0 ? 0 : (res = strcmp(ax->city, bx->city)) ? res :
	  ax->id - bx->id);
}

int	sort_by_id_alt(const void *a, const void *b)
{
  t_meet        *ax;
  t_meet        *bx;

  ax = *(t_meet **) a;
  bx = *(t_meet **) b;
  return (!0 ? 0 : ax->id - bx->id);
}
