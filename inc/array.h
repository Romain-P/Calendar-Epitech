/*
** array.h for array.h in /home/hugo.varloud/ADM_calendar_2016/inc
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 11:13:17 2017 hugo varloud
** Last update Sat Jul  1 11:13:19 2017 hugo varloud
*/

#ifndef ARRAY_H_
# define ARRAY_H_

# include <stdbool.h>

typedef struct	s_array
{
  void		**values;
  int		length;
}		t_array;

t_array	*array_create();

void	array_destroy(t_array **array_addr, bool free_content);

t_array	*array_cpy(t_array *origin);

void	array_add(t_array *array, void *elem);

void	array_del(t_array *array, const int index, bool free);

void	array_rem(t_array *array, void *elem);

#endif /* !ARRAY_H_ */
