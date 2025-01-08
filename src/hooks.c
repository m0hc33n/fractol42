#include "../inc/fractol.h"

static bool	is_code_valid(int keycode, int event)
{
	if (event == MOUSE)
	{
		if (keycode != 5 && keycode != 4)
			return (false);
	}
	else if (event == KEY)
		if (keycode != XK_Escape && keycode != XK_Left
			&& keycode != XK_Right && keycode != XK_Up
			&& keycode != XK_Down && keycode != XK_minus
			&& keycode != XK_0)
			return (false);
	return (true);
}

int	key_hook(int keycode, t_fractol *p_fractol)
{
	if (!is_code_valid(keycode, KEY))
	 	return (0);
	if (keycode == XK_Escape)
		terminate_fractol(p_fractol, NULL, 0);
	if (keycode == XK_Left)
		p_fractol->shift_x -= (0.5 * p_fractol->zoom);
	else if (keycode == XK_Right)
		p_fractol->shift_x += (0.5 * p_fractol->zoom);
	else if (keycode == XK_Up)
		p_fractol->shift_y -= (0.5 * p_fractol->zoom);
	else if (keycode == XK_Down)
		p_fractol->shift_y += (0.5 * p_fractol->zoom);
	else if (keycode == XK_0)
	{
		if (p_fractol->iterations < INT32_MAX - 10)
			p_fractol->iterations += 10;
	}
	else if (keycode == XK_minus)
		if (p_fractol->iterations > 10)
			p_fractol->iterations -= 10;
	fractol(p_fractol);
	return (0);
}

int	mouse_hook(int keycode, int x, int y ,t_fractol *p_fractol)
{
	(void)x;
	(void)y;
	if (!is_code_valid(keycode, MOUSE))
	 	return (0);
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