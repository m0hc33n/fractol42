#include "../inc/fractol.h"

static	void	init_struct(t_fractol *p_fractol)
{
	p_fractol->shift_x = 0.0;
	p_fractol->shift_y = 0.0;
	p_fractol->zoom  = 1.0;
	p_fractol->iterations = 1111;
}

static void	init_hooks(t_fractol *p_fractol)
{
	mlx_key_hook(p_fractol->p_win, key_hook, p_fractol);
	mlx_mouse_hook(p_fractol->p_win, mouse_hook, p_fractol);
	mlx_hook(p_fractol->p_win, DESTROYNOTIFY, STRUCTURENOTIFYMASK, x_exit, p_fractol);
}

bool	init_fractol(t_fractol *p_fractol)
{
	p_fractol->p_mlx = mlx_init();
	if (!p_fractol->p_mlx)
		return (false);
	p_fractol->p_win = mlx_new_window(p_fractol->p_mlx, WINDOW_HEIGHT, WINDOW_WIDTH, TITLE);
	if (!p_fractol->p_win)
		return (false);
	p_fractol->img.img = mlx_new_image(p_fractol->p_mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!p_fractol->img.img)
		return (false);
	p_fractol->img.addr = mlx_get_data_addr(p_fractol->img.img, &p_fractol->img.bits_per_pixel,
	 					&p_fractol->img.line_length, &p_fractol->img.endian);
	if (!p_fractol->img.addr)
		return (false);
	init_struct(p_fractol);
	init_hooks(p_fractol);
	return (true);
}

void terminate_fractol(t_fractol *p_fractol, char *msg, int msg_len)
{
	if (p_fractol)
	{
		if (p_fractol->p_mlx)
		{
			if (p_fractol->img.img)	
				mlx_destroy_image(p_fractol->p_mlx, p_fractol->img.img);
			if (p_fractol->p_win)
				mlx_destroy_window(p_fractol->p_mlx, p_fractol->p_win);
			mlx_loop_end(p_fractol->p_mlx);
			mlx_destroy_display(p_fractol->p_mlx);
			free(p_fractol->p_mlx);
		}
		free(p_fractol);
	}
	write(STDOUT_FILENO, msg, msg_len);
	if (msg)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
