#include "../inc/fractol.h"

void	julia(t_fractol *p_fractol, int x, int y)
{
	int     	color;
	int			iter;
    t_complex	z;
	t_complex	c;

	c.xr = p_fractol->julia_cr;
	c.yi = p_fractol->julia_ci;
    z.xr = (scale((double)x, -2, 2, 0, WINDOW_WIDTH) * p_fractol->zoom)+ p_fractol->shift_x;
	z.yi = (scale((double)y, 2, -2, 0, WINDOW_HEIGHT) * p_fractol->zoom) + p_fractol->shift_y;
	iter = 0;
	while (iter < p_fractol->iterations)
	{
		z = complex_sum(complex_sqrt(z), c);
		if (z.xr * z.xr + z.yi * z.yi > 4.0)
		{
			color = scale(iter, BLACK, WHITE, 0, p_fractol->iterations);
			put_pixel_to_img(p_fractol, x, y, color);
			return ;
		}
		iter++;
	}
    put_pixel_to_img(p_fractol, x, y, INDIGO);
}
