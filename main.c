# include "fdf.h"

int		expose_hook(t_env *env)
{

  return(0);
}

int		key_hook(int keycode, t_env *env)
{
	printf("key = %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return(0); 
}

int	main(int argc, char **argv)
{
  t_env		*env;
  t_map		*map;

  if (argc == 2)
    {
      env = (t_env*)malloc(sizeof(t_env));
      if (env == NULL)
	return (NULL);
      map = parse_map(argv, 0);
      env->map = map;
<<<<<<< HEAD
      env->mlx = mlx_init();
      env->mlx_win = mlx_new_window(env->mlx, 1000,  1000, "Kadric");
      draw_pts(env);
      //      draw_line(env);
      mlx_expose_hook(env->mlx_win, expose_hook, env);
      mlx_key_hook(env->mlx_win, key_hook, env);
      mlx_loop(env->mlx);
      return(0);
=======

>>>>>>> 9133a6be655e862f6f93741b92a284f7bc4fb7a5
    }
}
