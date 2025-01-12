#include "../inc/fractol.h"

static void	draw_pixel(t_fractol *p_fractol, int x, int y)
{
	int			iter;
	int			color;
	t_complex	p;

	p.xr = (p_fractol->x_max - p_fractol->x_min)
		* (double)x / WINDOW_WIDTH + p_fractol->x_min;
	p.yi = (p_fractol->y_max - p_fractol->y_min)
		* (double)y / WINDOW_HEIGHT + p_fractol->y_min;
	if (p_fractol->set == JULIA)
		iter = julia(p_fractol, p);
	else if (p_fractol->set == MANDELBROT)
		iter = mandelbrot(p_fractol, p);
	else if (p_fractol->set == BURNINGSHIP)
		iter = burningship(p_fractol, p);
	if (iter == p_fractol->iterations)
		color = p_fractol->color;
	else
		color = WHITE * (double)iter / p_fractol->iterations;
	put_pixel_to_img(p_fractol, x, y, color);
}

void	fractol(t_fractol *p_fractol)
{
	int	x;
	int	y;

	mlx_clear_window(p_fractol->p_mlx, p_fractol->p_win);
	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
		{
			draw_pixel(p_fractol, x, y);
		}
	}
	mlx_put_image_to_window(p_fractol->p_mlx, p_fractol->p_win,
		p_fractol->img.img, 0, 0);
}
