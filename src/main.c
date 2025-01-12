#include "../inc/fractol.h"

static void	print_control(void)
{
	write(STDOUT_FILENO,
		"\n\t\t#### CONTROL MENU #####\n\n"
		"\t\t[ARROWS KEYS]	: Shift image\n"
		"\t\t[SPACE]		: Shift Color\n"
		"\t\t[SCROLL-UP]	: Zoom OUT\n"
		"\t\t[SCROLL-DW]	: Zoom IN\n",
		132);
}

int	main(int ac, char **av)
{
	t_fractol	*p_fractol;

	p_fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (!p_fractol)
		return (false);
	if (!arg_handler(ac, av, p_fractol))
		return (usage(), terminate_fractol(p_fractol, NULL, 0), -2);
	if (!init_fractol(p_fractol))
	{
		terminate_fractol(p_fractol, INITFAIL, INITFAILEN);
		return (-1);
	}
	fractol(p_fractol);
	print_control();
	mlx_loop(p_fractol->p_mlx);
	return (0);
}
