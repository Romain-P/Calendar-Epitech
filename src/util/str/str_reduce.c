/*
** str_reduce.c for str_reduce.c in /home/hugo.varloud/ADM_calendar_2016/src/util/str
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 11:06:20 2017 hugo varloud
** Last update Sat Jul  1 11:06:22 2017 hugo varloud
*/

#include "util.h"

char    *str_reduce(char *str, const char c)
{
  int   i;
  int   j;
  bool	ignore;

  i = (j = 0);
  ignore = false;
  while (str && str[i])
    {
      ignore = str[i] == '\"' ? !ignore : ignore;
      if (ignore || (c ? str[i] != c : str[i] != ' ' && str[i] != '\t'))
	{
	  if (!ignore && i && j && (c ? str[i - 1] == c :
			 str[i - 1] == ' ' || str[i - 1] == '\t'))
	    str[j++] = c ? c : ' ';
	  str[j++] = str[i++];
	}
      else
	i++;
    }
  if (str)
    str[j] = 0;
  return (str);
}
