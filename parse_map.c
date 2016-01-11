# include "fdf.h"

int	get_nbr(char *str)
{
  int	i;
  int	res;
  int	neg;

  i = 0;
  res = 0;
  neg = 1;
  while (ft_isspace(str[i]))
    i++;
  if (str[i] == '-')
    neg = -1;
  if (str[i] == '+' || str[i] == '-')
    i++;
  while ((str[i] >= '0') && (str[i] <= '9'))
    {
      res = res * 10 + str[i] - '0';
      i++;
    }
  return (res * neg);  
}
int	line_numbers(char *str, int nb_line, t_point ***tab_point)
{
  char		**tab_str;
  int		nb;
  t_point	*point;

  tab_str = ft_strsplit(str, ' ');
  nb = 0;
  while (tab_str[nb])
    nb++;
  if(!(*tab_point = (t_point**)malloc(sizeof(t_point) * nb)))
    return (NULL);
  nb = 0;
  while (tab_str[nb])
    {
      if(!(point = (t_point*)malloc(sizeof(t_point))))
	return (NULL);					/*remplacer NULL par fonction malloc_err*/
      point->x = nb;
      point->y = nb_line;
      point->z = get_nbr(tab_str[nb]);
      (*tab_point)[nb] = point;
      nb++;
    }
  return (nb);
}

int	nb_line_map(char *str, int fd)
{
  char	buf;
  int	nb_lines;
  int	ret;

  nb_lines = 0;
  fd = open(str, O_RDONLY);
  while ((ret = read(fd, &buf, 1)) > 0)
    {
      if (buf == '\n')
	nb_lines++;
    }
  close(fd);
  return (nb_lines);
}

t_map	*parse_map(char **argv, int fd)
{
  t_map		*map;
  t_line	*line;
  t_point	**tab_point;
  char		*str;
  int		nb_line;
  int	i;
  int	j;
  j = 0;
  i = 0;
  nb_line = 0;
  if (!(map = (t_map*)malloc(sizeof(t_map))))
    return (NULL);
  if (!(map->lines = (t_line**)malloc(sizeof(t_line) * nb_line_map(argv[1], fd) + 1)))
    return (NULL);
  printf("retour nb_line_map = %d\n", nb_line_map(argv[1], fd));
  map->len = nb_line;
  printf("map->len = %d\n",map->len);
  if ((fd = open(argv[1], O_RDONLY)) > 0)
    {
      while (i <= nb_line_map(argv[1], fd))//((get_next_line(fd, &str)) > 0)
	{
	  if (!(line = (t_line*)malloc(sizeof(t_line))))
	    return (NULL);
	  get_next_line(fd, &str);
	  line->len = line_numbers(str, nb_line, &tab_point);//nombre de donnees dans str
	  line->pts = tab_point;
	  map->lines[nb_line] = line;
	  nb_line++;
	  i++;
	}
      map->len = nb_line;
      printf("nb_line = %d\n", nb_line);
      printf(" line->len = %d\n",line->len);
      printf("map->len = %d\n",map->len);
      i = 0;
      while(map->lines[i])
	{
	  j = 0;
	  printf("---------------------------\n---------------------------\n");
	  while(map->lines[i]->pts[j])
	    {
	      printf("tab_ptz = %f\n", map->lines[i]->pts[j]->z);
	      printf("tab_pty = %f\n",map->lines[i]->pts[j]->y);
	      printf("tab_ptx = %f\n", map->lines[i]->pts[j]->x);
	      printf("---------------------------\n");
	      j++;
	    }
	  i++;
	}
    }
  return(map);
}
