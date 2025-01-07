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
	if (cmp("5", arg) || cmp(JULIA_STR, arg))
		*set = 5;
	else if (cmp("10", arg) || cmp(MANDELBORT_STR, arg))
		*set = 10;
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
		if (!cmp("5", av[1]) && !cmp(JULIA_STR, av[1]))
			return (false);
		p_fractol->set = 5;
		if (!get_julia_cnst(av[2], &p_fractol->julia_cr))
			return (false);
		if (!get_julia_cnst(av[3], &p_fractol->julia_ci))
			return (false);
	}
	else
		return (false);
	if (p_fractol->set == JULIA && ac == 2)
	{
		p_fractol->julia_cr =  -0.7;
		p_fractol->julia_ci = 0.27015;
	}
	return (true);
}

void	usage()
{
	write(STDOUT_FILENO,"Usage:\n" 
               "\t./fractol <set> [julia_zr] [julia_zi]\n"
               "\n"
               "Options:\n"
               "  <set>				Specify the set type: [5 | julia], [10 | mandelbrot]\n"
               "  <julia_cr>		(Optional) Z real part (if set is julia)\n"
               "  <julia_ci>		(Optional) Z imaginary part (if set is julia)\n"
               "\n"
               "Examples:\n"
               "\t./fracotl 5\n"
               "\t./fractol julia 1.5 -0.5\n"
			   "\t./fractol mandelbort\n", 307);
}