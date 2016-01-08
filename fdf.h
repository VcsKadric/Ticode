#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "../../libft/includes/libft.h"

typedef struct	s_point
{
  double x;
  double y;
  double z;
}		t_point;

typedef struct	s_line
{
  t_point	**pts;
  int		len;
}		t_line;

typedef struct	s_map
{
  t_line	**lines;
  int		len;
}		t_map;

typedef struct	s_env
{
  void	*mlx;
  void	*mlx_win;
  t_map	*map;
}		t_env;

t_map		*parse_map(char *argv, int fd);
#endif
