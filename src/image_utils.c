#include "../inc/fractol.h"

void	put_pixel_to_img(t_fractol *p_fractol, int x, int y, int color)
{
	char	*pixel;

	pixel = p_fractol->img.addr + (y * p_fractol->img.line_length + x
			* (p_fractol->img.bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}
