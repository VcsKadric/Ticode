# include "fdf.h"

int	main(int argc, char **argv)
{
  t_env		*env;
  t_map		*map;

  if (argc == 2)
    {
      env = (t_env*)malloc(sizeof(t_env));
      if (env == NULL)
	return (NULL);
      map = parse_map(argv[1], 0);
      env->map = map;
    }
}
