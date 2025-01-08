#include "../inc/fractol.h"

int	key_hook(int keycode, t_fractol *p_fractol)
{
	if (keycode == XK_Escape)
		terminate_fractol(p_fractol, NULL, 0);
	if (keycode == XK_Left)
		p_fractol->shift_x -= 0.5 * p_fractol->zoom;
	else if (keycode == XK_Right)
		p_fractol->shift_x += 0.5 * p_fractol->zoom;
	else if (keycode == XK_Up)
		p_fractol->shift_y -= 0.5 * p_fractol->zoom;
	else if (keycode == XK_Down)
		p_fractol->shift_y += 0.5 * p_fractol->zoom;
	else if (keycode == XK_0	)
	{
		if (p_fractol->iterations < INT32_MAX - 100)
			p_fractol->iterations += 100;
	}
	else if (keycode == XK_minus)
		if (p_fractol->iterations > 100)
			p_fractol->iterations -= 100;
	fractol(p_fractol);
	return (0);
}

int	mouse_hook(int keycode, int x, int y ,t_fractol *p_fractol)
{
	(void)x;
	(void)y;
	if (keycode == 5)
		p_fractol->zoom *= 1.9;
	else if (keycode == 4)
		p_fractol->zoom *= 0.9;
	fractol(p_fractol);
	return (0);	
}

int	x_exit(t_fractol *p_fractol)
{
	terminate_fractol(p_fractol, NULL, 0);
	return (0);
}