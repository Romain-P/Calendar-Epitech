/*
** read.c for read.c in /home/hugo.varloud/ADM_calendar_2016/src/util
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 11:01:35 2017 hugo varloud
** Last update Sat Jul  1 11:01:37 2017 hugo varloud
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include "util.h"

static char	*append(char *str, char c)
{
  char		*ap;
  int		i;
  int		j;

  i = (j = 0);
  while (str && str[i] && ++i);
  if (!(ap = malloc(sizeof(char) * (i + (!c ? 1 : 2)))))
    return (NULL);
  while (str && j < i)
    {
      ap[j] = str[j];
      j++;
    }
  if ((ap[j] = c))
    ap[j + 1] = 0;
  if (str)
    free(str);
  return (ap);
}

char	*scan_line(const int file)
{
  char	*str;
  char	buffer[1];
  int	error;

  str = NULL;
  while ((error = read(file, buffer, 1)))
    {
      if (buffer[0] == '\n')
	return (str ? str : append(NULL, 0));
      else if (error == -1 || !(str = append(str, buffer[0])))
	break;
    }
  if (error && str)
    free(str);
  return (error ? NULL : str);
}
