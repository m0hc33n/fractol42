#include "../inc/fractol.h"

int main(int ac, char **av)
{
	t_fractol	*p_fractol;

	p_fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (!p_fractol)
		return (false);
	if (!arg_handler(ac, av, p_fractol))
		return (terminate_fractol(p_fractol, NULL, 0), usage(), -2);
	if (!init_fractol(p_fractol))
	{
		terminate_fractol(p_fractol, INITFAIL, INITFAILEN);
		return (-1);
	}
	fractol(p_fractol);
	mlx_loop(p_fractol->p_mlx);
	return (0);
}
