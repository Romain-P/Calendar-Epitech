/*
** print.c for print.c in /home/hugo.varloud/ADM_calendar_2016/src/util
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 11:01:14 2017 hugo varloud
** Last update Sat Jul  1 11:01:16 2017 hugo varloud
*/

#include <stdio.h>
#include <unistd.h>
#include "util.h"

static bool	private_print(const int channel, const char *str)
{
  int		len;

  len = 0;
  while (str && str[len] && ++len);
  return (len ? write(channel, str, len) : false);
}

bool	print(const char *str)
{
  return (private_print(STDOUT_FILENO, str));
}

bool	fprint(const char *str)
{
  return (private_print(STDERR_FILENO, str));
}
