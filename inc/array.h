/*
** util.h for  in /home/romain.pillot/projects/ghoulc/inc
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue May 23 14:02:04 2017 romain pillot
** Last update Fri Jun 30 23:38:20 2017 romain pillot
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
