#include "../inc/fractol.h"

void	mandelbrot(t_fractol *p_fractol, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			color;
	int			iter;

	z.xr = 0;
	z.yi = 0;
	c.xr = scale((double)x, -2, 2, 0, WINDOW_WIDTH);
	c.yi = scale((double)y, 2, -2, 0, WINDOW_HEIGHT);
	iter = 0;
	while (iter < MAX_ITERATIONS)
	{
		z = complex_sum(complex_sqrt(z), c);
		if (z.xr * z.xr + z.yi * z.yi > 4.0)
		{
			color = scale(iter, BLACK, WHITE, 0, MAX_ITERATIONS);
			put_pixel_to_img(p_fractol, x, y, color);
			return ;
		}
		iter++;
	}
	put_pixel_to_img(p_fractol, x, y, INDIGO);
}
