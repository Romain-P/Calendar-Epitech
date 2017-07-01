/*
** util.h for util.h in /home/hugo.varloud/ADM_calendar_2016/inc
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 11:14:17 2017 hugo varloud
** Last update Sat Jul  1 11:14:20 2017 hugo varloud
*/

#ifndef UTIL_H_
# define UTIL_H_

# include <stdbool.h>
# include <stdlib.h>

void	safe_free(void **ptr);

void	tab_free(void ***ptr);

# define FREE(PTR)      (safe_free((void **) &(PTR)))

# define TAB_FREE(PTR)	(tab_free((void ***) &(PTR)))

void	*talloc(size_t s);

void    qqsort(void *base, size_t nitems, size_t size,
	       int (*compar)(const void *a, const void *b));

void	tab_sort(char **tab);

bool	tab_contains(char **tab, const char *str);

int	nbr_parsestring(const char *str);

bool	str_isnumber(const char *str);

char	*str_reverse(char *str);

char	*str_replace(char *str, const char target, const char new);

char	*str_concat(char *a, const char *b, bool free_a);

bool	str_contains(const char *str, const char *charset);

bool	str_equals(const char *a, const char *b);

bool	str_starts(const char *str, const char *charset);

bool	str_ends(const char *str, const char *charset);

int	str_length(const char *str);

int	tab_length(void *tab);

char	*str_dupl(const char *str);

char	*str_dupli(const char *str, int imax);

int	str_countchar(const char *str, const char delimiter);

char	*str_reduce(char *str, const char delimiter);

char	**str_split(char *str, const char delimiter);

bool	print(const char *str);

bool	fprint(const char *str);

char	*scan_line(const int file);

#endif /* !UTIL_H_ */
