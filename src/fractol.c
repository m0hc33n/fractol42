#include "../inc/fractol.h"

static void	draw_pixel(t_fractol *p_fractol, int x, int y)
{
	int			iter;
	int			color;
	t_complex	p;

	p.xr = scale((double)x, p_fractol->x_min, p_fractol->x_max, 0, WINDOW_WIDTH);
	p.yi = scale((double)y, p_fractol->y_min, p_fractol->y_max, 0, WINDOW_HEIGHT);
	if (p_fractol->set == JULIA)
		iter = julia(p_fractol, p);
	else if (p_fractol->set == MANDELBROT)
	 	iter = mandelbrot(p_fractol, p);
	else if (p_fractol->set == BURNINGSHIP)
		iter = burningship(p_fractol, p);
	if (iter == p_fractol->iterations)
		color = p_fractol->color;
	else
        color = scale(iter, BLACK, WHITE, 0, p_fractol->iterations);
	put_pixel_to_img(p_fractol, x, y, color);
}

void	fractol(t_fractol *p_fractol)
{
	int			x;
	int			y;

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
	mlx_put_image_to_window(p_fractol->p_mlx, p_fractol->p_win, p_fractol->img.img, 0, 0);
}
