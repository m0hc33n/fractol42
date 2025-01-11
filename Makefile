CC 	   = cc 
CFLAGS = -Wall -Wextra -Werror -Iinc

OBJ_DIR = obj

MLXPATH = mlx/
MLX = mlx/libmlx_Linux.a
MLXFLAGS = -lXext -lX11

FRACTOL_HDR = inc/fractol.h
FRACTOL_SRC = src/main.c src/arg_handler.c src/arg_handler_utils.c \
			  src/fractol.c src/fractol_lifecycle.c \
			  src/julia.c src/mandelbrot.c src/burningship.c \
			  src/hooks.c \
			  src/image_utils.c src/math_utils.c
FRACTOL = fractol

OBJ = $(patsubst src/%.c,$(OBJD)/%.o,$(FRACTOL_SRC))
OBJD = obj

all : $(FRACTOL)

$(FRACTOL) : $(OBJD) $(OBJ) $(MLX) 
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLXFLAGS) -o $@

$(MLX) :
	make -C $(MLXPATH)

$(OBJD) :
	mkdir -p $(OBJD)

$(OBJD)/%.o : src/%.c $(FRACTOL_HDR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ) : $(HDR)

clean :
	rm -rf $(OBJ_DIR)
	make clean -C $(MLXPATH)

fclean : clean
	rm -f $(FRACTOL)

re : fclean all

.PHONY : clean
