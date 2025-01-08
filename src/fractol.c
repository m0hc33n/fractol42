#include "../inc/fractol.h"

static void	calc_fractal(t_fractol *p_fractol, int x, int y)
{
	if (p_fractol->set == JULIA)
		julia(p_fractol, x, y);
	else if (p_fractol->set == MANDELBROT)
	 	mandelbrot(p_fractol, x, y);
	else if (p_fractol->set == BURNINGSHIP)
		burningship(p_fractol, x, y);
}

void	fractol(t_fractol *p_fractol)
{
	int		x;
	int		y;

	mlx_clear_window(p_fractol->p_mlx, p_fractol->p_win);
	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
		{
			calc_fractal(p_fractol, x, y);
		}
	}
	mlx_put_image_to_window(p_fractol->p_mlx, p_fractol->p_win, p_fractol->img.img, 0, 0);
}
