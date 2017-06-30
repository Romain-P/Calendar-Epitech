/*
** main.c for  in /home/romain.pillot/projects/romhug/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Jun 30 15:30:35 2017 romain pillot
** Last update Fri Jun 30 18:40:29 2017 romain pillot
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "calendar.h"
#include "util.h"

static t_func const	g_funcs[] =
{
  {"new_employee", &employe_new},
  {"fire", &employe_del},
  {"info_employees", &employe_info},
  {"new_meeting", &meeting_new},
  {"cancel", &meeting_del},
  {"invite", &meeting_invite},
  {"exclude", &meeting_exclude},
  {"info_meetings", &meeting_info},
  {NULL, NULL}
};

t_func const	g_esort[] =
{
  {"sortByName", &sort_by_name},
  {"sortByForname", &sort_by_forename},
  {"sortByJob", &sort_by_job},
  {"sortByZip", &sort_by_zip},
  {"sortById", &sort_by_id},
  {NULL, NULL}
};

t_func const	g_msort[] =
{
  {"sortByDate", &sort_by_date},
  {"sortByZip", &sort_by_zip},
  {"sortById", &sort_by_id}
};

int	main(int ac, char **args)
{
  char	*str;
  t_cal	*cal;
  int	i;

  cal = talloc(sizeof(t_cal));
  cal->emps = array_create();
  cal->meets = array_create();
  while ((str = scan_line(STDIN_FILENO)) &&
	 !str_starts(str, "END"))
    {
      i = -1;
      while (g_funcs[++i].label)
	{
	  if (str_starts(str, str_concat(str_dupl(g_funcs[i].label), " ", false)))
	    g_funcs[i].func(cal, str_split(str_dupl(str), ' '));
	  FREE(str);
	}
    }
  return (EXIT_SUCCESS);
}
