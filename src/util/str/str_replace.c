/*
** str_replace.c for str_replace.c in /home/hugo.varloud/ADM_calendar_2016/src/util/str
** 
** Made by hugo varloud
** Login   <hugo.varloud@epitech.net>
** 
** Started on  Sat Jul  1 11:06:56 2017 hugo varloud
** Last update Sat Jul  1 11:06:58 2017 hugo varloud
*/

char	*str_replace(char *str, const char target, const char new)
{
  int	i;

  i = -1;
  while (str[++i])
    if (str[i] == target)
      str[i] = new;
  return (str);
}
