#include "../inc/fractol.h"

// static int calc_julia(t_fractol *p_fractol, double zr, double zi)
// {
//     int		n;
// 	double	tmp;

// 	n = 0;
// 	while (n < MAX_ITERATIONS)
// 	{
// 		if ((zi * zi + zr * zr) > 4.0)
// 			break ;
// 		tmp = 2 * zr * zi + p_fractol->julia_ci;
// 		zr = zr * zr - zi * zi + p_fractol->julia_cr;
// 		zi = tmp;
// 		n++;
// 	}
// 	return (n);
// }

void	julia(t_fractol *p_fractol, int x, int y)
{
	int     	color;
	int			iter;
    t_complex	z;
	t_complex	c;

	c.xr = p_fractol->julia_cr;
	c.yi = p_fractol->julia_ci;
    z.xr = scale((double)x, -2, 2, 0, WINDOW_WIDTH);
	z.yi = scale((double)y, -2, 2, 0, WINDOW_HEIGHT);
    //iter = calc_julia(p_fractol, z.xr, z.yi);
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
	//color = scale(iter, BLACK, WHITE, 0, MAX_ITERATIONS);
    //if (iter == MAX_ITERATIONS)
     //   put_pixel_to_img(p_fractol, x, y, BLACK);
    //else
       	put_pixel_to_img(p_fractol, x, y, INDIGO);
}
