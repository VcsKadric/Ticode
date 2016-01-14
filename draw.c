# include "fdf.h"

void	draw_line(t_env *env, t_point pt1, t_point pt2);
void	draw_col(t_env	*env, t_point pt1, t_point pt2);

void	draw_pts(t_env *env)
{
  int	i;
  int	j;
  int startx;
  int starty;
  t_point pt1;
  t_point pt2;
  
  startx = 20;
  starty = 20;
  i = 0;
  while (env->map->lines[i])
    {
      j = 0;
      while (env->map->lines[i]->pts[j])
	{
	  pt1 = *env->map->lines[i]->pts[j];//
	  if (env->map->lines[i]->pts[j + 1])
	    pt2 = *env->map->lines[i]->pts[j + 1];//
	  else
	    pt2 = *env->map->lines[i]->pts[j];
	  printf("pt1.y = %f\n", pt1.y);
	  printf("pt2.y = %f\n", pt2.y);
	  printf("pt1.x = %f\n", pt1.x);
	  printf("pt2.x = %f\n", pt2.x);
	  mlx_pixel_put(env->mlx, env->mlx_win,
			(env->map->lines[i]->pts[j]->x + startx) * startx,
	  		(i + starty) * starty, 0xFFFFFF);
	  draw_line(env, pt1, pt2);
	  j++;
	}
      draw_col(env, pt1, pt2);
      i++;
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

void	draw_col(t_env	*env, t_point pt1, t_point pt2)
{
  double	lx;
  double	ly;

  lx = pt1.x + 20;
  ly = pt1.y + 20;
  
  while (ly <= pt2.y + 20)
    {
      mlx_pixel_put(env->mlx, env->mlx_win, lx * 20, ly * 20, 0xFFFFFF);
      ly = ly + 0.01;
    }
}
