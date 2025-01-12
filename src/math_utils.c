#include "../inc/fractol.h"

double	scale(double unscaled, double new_min, double new_max, double old_min,
		double old_max)
{
	return ((new_max - new_min) * (unscaled - old_min) / (old_max - old_min)
		+ new_min);
}

t_complex	complex_sum(t_complex a, t_complex b)
{
	return ((t_complex){a.xr + b.xr, a.yi + b.yi});
}

t_complex	complex_sqrt(t_complex a)
{
	return ((t_complex){a.xr * a.xr - a.yi * a.yi, 2 * a.xr * a.yi});
}

double	fabs(double val)
{
	if (val < 0)
		return (-val);
	return (val);
}
