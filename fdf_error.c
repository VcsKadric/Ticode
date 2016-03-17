#include "fdf.h"

void	fdf_exit(void)
{
	exit(1);
}

void	fdf_malloc_error(void)
{
	ft_putstr_fd("malloc error\n", 2);
	fdf_exit();
}

void	fdf_map_error(void)
{
	ft_putstr_fd("map error\n", 2);
	fdf_exit();
}

void	fdf_arg_error(void)
{
	ft_putstr_fd("Un seul argument pris en compte.\n", 2);
	fdf_exit();
}
