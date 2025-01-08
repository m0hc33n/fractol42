#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <X11/keysym.h>

// WINDOWS DEIFNES
# define WINDOW_HEIGHT 900
# define WINDOW_WIDTH 900
# define TITLE "FRACTOL"

// SETS DEFINES
# define JULIA_STR "julia"
# define MANDELBORT_STR "mandelbrot"
# define JULIA 5
# define MANDELBROT 10

# define MAX_ITERATIONS 4242
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define INDIGO 0x4B0082

// ERRORS
# define INITFAIL "[!!] CANNOT INITIALIZE FRACTOL\n"
# define INITFAILEN 31
# define DONE "[++] DONE\n"
# define DONELEN 10

// EVENTS
# define DESTROYNOTIFY 17
# define STRUCTURENOTIFYMASK (1L<<17)

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
	int			iterations;
	double		julia_ci;
	double		julia_cr;
}	t_fractol;

// FRACTOL MANAGEMENT
bool	init_fractol(t_fractol *p_fractol);
void	terminate_fractol(t_fractol *p_fractol, char *msg, int msg_len);
void	julia(t_fractol *p_fracto, int x, int y);
void	mandelbrot(t_fractol *p_fractol, int x, int y);

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


// ARGS
bool	arg_handler(int ac, char **av, t_fractol *p_fractol);
bool	get_julia_cnst(char *str, double *nb);
void	usage();

#endif