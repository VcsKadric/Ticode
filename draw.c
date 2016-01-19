# include "fdf.h"

void	draw_line(t_env *env, t_point pt1, t_point pt2);
void	draw_col(t_env	*env, t_point pt1, t_point pt2, t_point pt3);

void	draw_pts(t_env *env)
{
  int	i;
  int	j;
  int startx;
  int starty;
  t_point pt1;
  t_point pt2;
  t_point pt3;
  t_point pt4;
  
  startx = 20;
  starty = 20;
  printf("nb_lines = %d\n", env->map->len);
  while (env->map->lines[i])
    {
      j = 0;
      pt3 = *env->map->lines[i]->pts[j];
      if (env->map->lines[i + 1])
	pt4= *env->map->lines[i + 1]->pts[j];
      else
	pt4 = *env->map->lines[i]->pts[j];
      printf("nb_lines = %d\n", env->map->len);
      while (env->map->lines[i]->pts[j])
	{

	  pt1 = *env->map->lines[i]->pts[j];//
	  if (env->map->lines[i]->pts[j + 1])
	    pt2 = *env->map->lines[i]->pts[j + 1];//
	  else
	    pt2 = *env->map->lines[i]->pts[j];
	  mlx_pixel_put(env->mlx, env->mlx_win,
			(env->map->lines[i]->pts[j]->x + startx) * startx,
	  		(i + starty) * starty, 0xFFFFFF);
	  draw_line(env, pt1, pt2);
	  draw_col(env, pt3, pt4, pt1);
	  j++;
	  printf("nb_lines(j) = %d\n", env->map->len);
	}
      i++;
      printf("ICI");
    }
}

void	draw_line(t_env	*env, t_point pt1, t_point pt2)
{
  double	lx;
  double	ly;

  lx = pt1.x + 20;
  ly = pt1.y + 20;

  while (lx <= pt2.x + 20)
    {
      mlx_pixel_put(env->mlx, env->mlx_win, lx * 20, ly * 20, 0xFFFFFF);
      lx = lx + 0.01;
    }
}

void	draw_col(t_env	*env, t_point pt1, t_point pt2, t_point pt3)
{
  double	lx;
  double	ly;

  lx = pt3.x + 20;
  ly = pt1.y + 20;
  
  while (ly <= pt2.y + 20)
    {
      mlx_pixel_put(env->mlx, env->mlx_win, lx * 20, ly * 20, 0xFFFFFF);
      ly = ly + 0.01;
    }
}
