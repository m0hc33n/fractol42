#include "../inc/fractol.h"

static bool	is_code_valid(int keycode, int event)
{
	if (event == MOUSE)
	{
		if (keycode != 5 && keycode != 4)
			return (false);
	}
	else if (event == KEY)
		if (keycode != XK_Escape && keycode != XK_Left && keycode != XK_Right
			&& keycode != XK_Up && keycode != XK_Down && keycode != XK_minus
			&& keycode != XK_space && keycode != XK_r)
			return (false);
	return (true);
}

void	zoom(t_fractol *p_fractol, double zoom)
{
	double	center_r;
	double	center_i;

	center_r = (p_fractol->x_max + p_fractol->x_min) / 2;
	center_i = (p_fractol->y_max + p_fractol->y_min) / 2;
	p_fractol->x_max = center_r + (p_fractol->x_max - center_r) * zoom;
	p_fractol->x_min = center_r + (p_fractol->x_min - center_r) * zoom;
	p_fractol->y_max = center_i + (p_fractol->y_max - center_i) * zoom;
	p_fractol->y_min = center_i + (p_fractol->y_min - center_i) * zoom;
}

static void	shift(t_fractol *p_fractol, double scale_factor, char direction)
{
	double	width;
	double	height;

	width = p_fractol->x_max - p_fractol->x_min;
	height = p_fractol->y_max - p_fractol->y_min;
	if (direction == RIGHT)
	{
		p_fractol->x_min += width * scale_factor;
		p_fractol->x_max += width * scale_factor;
	}
	else if (direction == LEFT)
	{
		p_fractol->x_min -= width * scale_factor;
		p_fractol->x_max -= width * scale_factor;
	}
	else if (direction == UP)
	{
		p_fractol->y_min += height * scale_factor;
		p_fractol->y_max += height * scale_factor;
	}
	else if (direction == DOWN)
	{
		p_fractol->y_min -= height * scale_factor;
		p_fractol->y_max -= height * scale_factor;
	}
}

int	key_hook(int keycode, t_fractol *p_fractol)
{
	if (!is_code_valid(keycode, KEY))
		return (0);
	if (keycode == XK_Escape)
		terminate_fractol(p_fractol, NULL, 0);
	if (keycode == XK_Left)
		shift(p_fractol, SHIFT_FACTOR, LEFT);
	else if (keycode == XK_Right)
		shift(p_fractol, SHIFT_FACTOR, RIGHT);
	else if (keycode == XK_Up)
		shift(p_fractol, SHIFT_FACTOR, DOWN);
	else if (keycode == XK_Down)
		shift(p_fractol, SHIFT_FACTOR, UP);
	else if (keycode == XK_space)
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

int	mouse_hook(int keycode, int x, int y, t_fractol *p_fractol)
{
	if (!is_code_valid(keycode, MOUSE))
		return (0);
	if (keycode == 5)
		zoom(p_fractol, ZOOMOUT_FACTOR);
	else if (keycode == 4)
	{
		zoom(p_fractol, ZOOMIN_FACTOR);
		x -= WINDOW_WIDTH / 2;
		y -= WINDOW_HEIGHT / 2;
		if (x < 0)
			shift(p_fractol, (double)x * -1 / WINDOW_WIDTH, LEFT);
		else if (x > 0)
			shift(p_fractol, (double)x / WINDOW_WIDTH, RIGHT);
		if (y < 0)
			shift(p_fractol, (double)y * -1 / WINDOW_HEIGHT, DOWN);
		else if (y > 0)
			shift(p_fractol, (double)y / WINDOW_HEIGHT, UP);
	}
	fractol(p_fractol);
	return (0);
}

int	x_exit(t_fractol *p_fractol)
{
	terminate_fractol(p_fractol, NULL, 0);
	return (0);
}
