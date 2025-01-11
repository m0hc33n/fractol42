#include "../inc/fractol.h"

int	julia(t_fractol *p_fractol, t_complex z)
{
	int			iter;
	t_complex	c;

	c.xr = p_fractol->julia_cr;
	c.yi = p_fractol->julia_ci;
	iter = 0;
	while (iter < p_fractol->iterations)
	{
		z = complex_sum(complex_sqrt(z), c);
		if (z.xr * z.xr + z.yi * z.yi > 4.0)
			break ;
		iter++;
	}
	return (iter);
}
