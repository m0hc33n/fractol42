# include "../inc/fractol.h"

int	burningship(t_fractol *p_fractol, t_complex c)
{
	t_complex	z;
	int			iter;

	z.xr = 0;
	z.yi = 0;
	iter = 0;
	while (iter < p_fractol->iterations)
	{
		z.xr = fabs(z.xr);
		z.yi = fabs(z.yi);
		z = complex_sum(complex_sqrt(z), c);
		if (z.xr * z.xr + z.yi * z.yi > 4.0)
			break ;

		iter++;
	}
	return (iter);
}
