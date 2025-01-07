#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

// WINDOWS DEIFNES
# define WINDOW_HEIGHT 900
# define WINDOW_WIDTH 900
# define TITLE "FRACTOL"

// SETS DEFINES
# define JULIA_STR "julia"
# define MANDELBORT_STR "mandelbort"
# define JULIA 5
# define MANDELBROT 10

# define MAX_ITERATIONS 4242
# define BLACK 0x000000
# define WHITE 0xffffff
# define RED     0xFF0000
# define GREEN   0x00FF00
# define BLUE    0x0000FF
# define YELLOW  0xFFFF00
# define CYAN    0x00FFFF
# define MAGENTA 0xFF00FF
#define LAVENDER   0xE6E6FA
#define SALMON     0xFA8072
#define TURQUOISE  0x40E0D0
#define ORCHID     0xDA70D6
#define CORAL      0xFF7F50
#define GOLDENROD  0xDAA520
#define DEEPSKYBLUE 0x00BFFF
#define INDIGO     0x4B0082
#define TEAL       0x008080
#define OLIVE      0x808000


  
// ERRORS
# define INITFAIL "[!!] CANNOT INITIALIZE FRACTOL\n"
# define INITFAILEN 31
# define DONE "[++] DONE\n"
# define DONELEN 10

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

// MATH
double	scale(double unscaled, double new_min, double new_max,
			double old_min, double old_max);
t_complex	complex_sqrt(t_complex a);
t_complex	complex_sum(t_complex a, t_complex b);


// ARGS
bool	arg_handler(int ac, char **av, t_fractol *p_fractol);
bool	get_julia_cnst(char *str, double *nb);
void	usage();

#endif