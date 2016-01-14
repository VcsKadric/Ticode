# include "fdf.h"

int		key_hook(int keycode, t_env *env)
{
	printf("key = %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return(0); 
}
