#ifndef __DATA_H__
#define __DATA_H__

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

typedef struct	s_data
{
  int	start_x;
  int	start_y;
  int	size;
}		t_data;

int	value(int **map, int i, int j, t_data *max);
void	replace(char **map, t_data max);
void	fill(char *tmp, int **map, char **map_char);
void	display(char **map, int lines);
void	name(char *tmp, int size, int lines);
int	bsq(char *path, int size);

#endif
