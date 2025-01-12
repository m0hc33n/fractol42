#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <X11/keysym.h>

// WINDOWS DEIFNES
# define WINDOW_HEIGHT 400
# define WINDOW_WIDTH 400
# define TITLE "FRACTOL"

// SETS DEFINES
# define JULIA_STR "julia"
# define MANDELBORT_STR "mandelbrot"
# define BURNINGSHIP_STR "burningship"
# define JULIA 0
# define MANDELBROT 1
# define BURNINGSHIP 2

// COLORS
# define BLACK 0x00000000
# define WHITE 0xFFFFFFFF

// ERRORS
# define INITFAIL "[!!] CANNOT INITIALIZE FRACTOL\n"
# define INITFAILEN 31
# define DONE "[++] DONE\n"
# define DONELEN 10

// EVENTS
# define DESTROYNOTIFY 17
# define STRUCTURENOTIFYMASK (1L<<17)
# define MOUSE -1
# define KEY -2
# define SHIFT_FACTOR 0.05
# define ZOOMIN_FACTOR 0.5
# define ZOOMOUT_FACTOR 1.5

// ARROWS
# define LEFT 'L'
# define RIGHT 'R'
# define DOWN 'D'
# define UP 'U'

typedef struct s_complex
{
	double	xr;
	double	yi;
} t_complex;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;	
	int		line_length;
	int		endian;
}	t_img;


typedef struct s_fractol
{
	void		*p_mlx;
	void		*p_win;
	t_img		img;
	int			set;
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	int			iterations;
	double		julia_ci;
	double		julia_cr;
	int			color;
}	t_fractol;

// FRACTOL MANAGEMENT
bool	init_fractol(t_fractol *p_fractol);
void	terminate_fractol(t_fractol *p_fractol, char *msg, int msg_len);
int		julia(t_fractol *p_fracto, t_complex p);
int		mandelbrot(t_fractol *p_fractol, t_complex p);
int		burningship(t_fractol *p_fractol, t_complex p);

// FRACTOL
void	fractol(t_fractol *p_fractol);

// IMG
void	put_pixel_to_img(t_fractol *p_fractol, int x, int y, int color);

// HOOKS
int		x_exit(t_fractol *p_fractol);
int		key_hook(int keycode, t_fractol *p_fractol);
int		mouse_hook(int keycode, int x, int y ,t_fractol *p_fractol);

// MATH
double		scale(double unscaled, double new_min, double new_max,
			double old_min, double old_max);
t_complex	complex_sqrt(t_complex a);
t_complex	complex_sum(t_complex a, t_complex b);
double		fabs(double val);


// ARGS
bool	arg_handler(int ac, char **av, t_fractol *p_fractol);
bool	get_julia_cnst(char *str, double *nb);
void	usage();

#endif