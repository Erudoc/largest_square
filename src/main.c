#include "data.h"

void	display(char **map, int lines)
{
  int	i;

  i = 0;
  while (i < lines)
    {
      write(1, map[i], strlen(map[i]));
      i++;
    }
}

void	name(char *tmp, int size, int lines)
{
  int	**map;
  char	**map_char;
  int	size2;
  int	i;

  i = 0;
  size2 = size / lines - 1;
  map = malloc(sizeof (int *) * lines);
  map_char = malloc(sizeof (char *) * lines);
  while (i < lines)
    {
      map_char[i] = malloc(sizeof (char) * (size2 + 2));
      map[i++] = malloc(sizeof (int) * (size2 + 2));
    }
  fill(tmp, map, map_char);
  display(map_char, lines);
  i = 0;
  while (i < lines)
    {
      free(map[i]);
      free(map_char[i++]);
    }
  free(map_char);
  free(map);
}

int	error_handler(char *buf, int *data, int lines, char *path)
{
  int	fd;
  int	ret;

  fd = data[0];
  ret = data[0];
  (void) buf;
  if (fd == -1 || ret == -1 || lines <= 0)
    {
      if (fd == -1)
	fprintf(stderr, "Cannot open %s\n", path);
      else if (ret == -1)
	fprintf(stderr, "Cannot read %s\n", path);
      else if (lines <= 0)
	fprintf(stderr, "Wrong map size : %d must be higher than 0\n", lines);
      free(buf);
      close(fd);
      return (-1);
    }
  else
    return (0);

}

int	bsq(char *path, int size)
{
  int	ret[2];
  int	lines;
  char	*buf;

  buf = malloc(sizeof (char) * size + 1);
  ret[0] = open(path, O_RDONLY);
  ret[1] = read(ret[0], buf, size);
  if (error_handler(buf, ret, 1, path))
    return (-1);
  buf[size] = 0;
  lines =  atoi(buf);
  if (error_handler(buf, ret, lines, path))
    return (-1);
  name(buf, size, lines);
  free(buf);
  close(ret[0]);
  return (0);
}

int	main(int ac, char **av)
{
  struct stat	map;

  if (ac == 2)
    {
      stat(av[1], &map);
      return (bsq(av[1], map.st_size));
    }
  else
    {
      fprintf(stderr, "USAGE : %s map\n", av[0]);
      fprintf(stderr, "\tmap : name of file containing the map\n");
      return (-1);
    }
  return (0);
}
