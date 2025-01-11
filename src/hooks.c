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
			&& keycode != XK_0 && keycode != XK_r)
			return (false);
	return (true);
}

void	zoom(t_fractol *p_fractol, double zoom)
{
	double	center_r;
	double	center_i;

	center_r = p_fractol->x_min - p_fractol->x_max;
	center_i = p_fractol->y_max - p_fractol->y_min;
	p_fractol->x_max = p_fractol->x_max + (center_r - zoom * center_r) / 2;
	p_fractol->x_min = p_fractol->x_max + zoom * center_r;
	p_fractol->y_min = p_fractol->y_min + (center_i - zoom * center_i) / 2;
	p_fractol->y_max = p_fractol->y_min + zoom * center_i;

}

static void	shift(t_fractol *f, double distance, char direction)
{
	double	center_r;
	double	center_i;

	center_r = f->x_max - f->x_min;
	center_i = f->y_max - f->y_min;
	if (direction == RIGHT)
	{
		f->x_min +=  center_r * distance;
		f->x_max +=  center_r * distance;
	}
	else if (direction == LEFT)
	{
		f->x_min -=  center_r * distance;
		f->x_max -=  center_r * distance;
	}
	else if (direction == UP)
	{
		f->y_min +=  center_i * distance;
		f->y_max +=  center_i * distance;
	}
	else if (direction == DOWN)
	{
		f->y_min -=  center_i * distance;
		f->y_max -=  center_i * distance;
	}

}

int	key_hook(int keycode, t_fractol *p_fractol)
{
	if (!is_code_valid(keycode, KEY))
	 	return (0);
	if (keycode == XK_Escape)
		terminate_fractol(p_fractol, NULL, 0);
	if (keycode == XK_Left)
		shift(p_fractol, 0.05, LEFT);
	else if (keycode == XK_Right)
		shift(p_fractol, 0.05, RIGHT);	
	else if (keycode == XK_Up)
		shift(p_fractol, 0.05, DOWN);
	else if (keycode == XK_Down)
		shift(p_fractol, 0.05, UP);
	else if (keycode == XK_0)
	{
		if (p_fractol->iterations < INT32_MAX - 50)
			p_fractol->iterations += 50;
	}
	else if (keycode == XK_minus)
		if (p_fractol->iterations > 50)
			p_fractol->iterations -= 50;
	fractol(p_fractol);
	return (0);
}

int	mouse_hook(int keycode, int x, int y ,t_fractol *p_fractol)
{
	if (!is_code_valid(keycode, MOUSE))
	 	return (0);
	if (keycode == 5)
		zoom(p_fractol, 2);
	else if (keycode == 4)
	{
		zoom(p_fractol, 0.5);
		x -= WINDOW_WIDTH / 2;
		y -= WINDOW_HEIGHT / 2;
		if (x < 0)
			shift(p_fractol, (double)x * -1 / WINDOW_WIDTH, LEFT);
		else if (x > 0)
			shift(p_fractol, (double)x / WINDOW_WIDTH, RIGHT);
		if (y < 0)
			shift(p_fractol, (double)y * -1 / WINDOW_HEIGHT, DOWN);
		else if (y > 0)
			shift (p_fractol, (double)y / WINDOW_HEIGHT, UP);
	}
	fractol(p_fractol);
	return (0);
}

int	x_exit(t_fractol *p_fractol)
{
	terminate_fractol(p_fractol, NULL, 0);
	return (0);
}
