/*
** free.c for free.c in /home/hugo.varloud/ADM_calendar_2016/src/util
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 11:00:41 2017 hugo varloud
** Last update Sat Jul  1 11:00:42 2017 hugo varloud
*/

#include <stdlib.h>
#include "util.h"

void	safe_free(void **ptr)
{
  if (ptr && *ptr)
    {
      free(*ptr);
      *ptr = NULL;
    }
}

void	tab_free(void ***ptr)
{
  if (ptr && *ptr)
    {
      if (**ptr)
	free(**ptr);
      free(*ptr);
      *ptr = NULL;
    }
}
