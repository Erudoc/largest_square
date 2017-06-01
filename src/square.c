#include "data.h"

int	value(int **map, int i, int j, t_data *max)
{
  int	min;

  if ((i == 0 && j == 0) || i == 0 || j == 0)
    {
      if (max->size < 1)
	{
	  max->size = 1;
	  max->start_x = (j - 1 < 0) ? 0 : j;
	  max->start_y = (i - 1 < 0) ? 0 : i;
	}
      return (1);
    }
  else
    {
      min = map[i][j - 1];
      min = (min > map[i - 1][j]) ? map[i - 1][j] : min;
      min = (min > map[i - 1][j - 1]) ? map[i - 1][j - 1] : min;
      if (max->size < min + 1)
	{
	  max->size = min + 1;
	  max->start_x = j - max->size + 1;
	  max->start_y = i - max->size + 1;
	}
    }
  return (min + 1);
}

void	replace(char **map, t_data max)
{
  int	i;
  int	j;

  i = max.start_y;
  while (i < max.start_y + max.size)
    {
      j = max.start_x;
      while (j < max.start_x + max.size)
	{
	  map[i][j] = 'x';
	  j++;
	}
      i++;
    }
}

void	fill(char *tmp, int **map, char **map_char)
{
  t_data	max;
  int		i;
  int		j;
  int		k;

  i = -1;
  while (tmp[++i] != '\n');
  k = 0;
  max.size = 0;
  while (tmp[++i])
    {
      j = 0;
      while (tmp[i] != '\n' && tmp[i] != '\0')
	{
	  if (tmp[i] == '.')
	    map[k][j] = value(map, k, j, &max);
	  else
	    map[k][j] = 0;
	  map_char[k][j++] = tmp[i++];
	}
      map_char[k][j] = '\n';
      map_char[k][j + 1] = 0;
      k++;
    }
  replace(map_char, max);
}
