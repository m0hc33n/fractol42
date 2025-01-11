#include "../inc/fractol.h"

static int	to_lower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

static bool	cmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (to_lower(*s1) != to_lower(*s2))
			return (false);
		s1++;
		s2++;
	}
	return (true);
}

static bool	get_set(char *arg, int *set)
{
	if (cmp(JULIA_STR, arg))
		*set = JULIA;
	else if (cmp(MANDELBORT_STR, arg))
		*set = MANDELBROT;
	else if (cmp(BURNINGSHIP_STR, arg))
		*set = BURNINGSHIP;
	else
		return (false);
	return (true);
}


bool arg_handler(int ac, char **av, t_fractol *p_fractol)
{
	if (ac == 1)
		return (false);
	else if (ac == 2)
	{
		if (!get_set(av[1], &p_fractol->set))
			return (false);
	}
	else if (ac == 4)
	{
		if (!cmp(JULIA_STR, av[1]))
			return (false);
		p_fractol->set = JULIA;
		if (!get_julia_cnst(av[2], &p_fractol->julia_cr))
			return (false);
		if (!get_julia_cnst(av[3], &p_fractol->julia_ci))
			return (false);
	}
	else
		return (false);
	if (p_fractol->set == JULIA && ac == 2)
	{
		p_fractol->julia_cr = -0.8;
		p_fractol->julia_ci = 0.156;
	}
	return (true);
}

void	usage()
{
	write(STDOUT_FILENO,"Usage:\n" 
        		"\t./fractol <set> [julia_zr] [julia_zi]\n"
            	"\n"
            	"Options:\n"
            	"  <set>			(Required) Specify the set type: julia, mandelbrot or burningship\n"
            	"  [julia_cr]		(Optional) julia Z real part (Default -0.8)\n"
            	"  [julia_ci]		(Optional) julia Z imaginary part (Default 0.156)\n"
            	"\n"
            	"Examples:\n"
            	"\t./fractol julia\n"
				"\t./fractol julia -0.8 0.156\n"
				"\t./fracotl mandelbrot\n"
				"\t./fractol burningship\n", 355);
}
