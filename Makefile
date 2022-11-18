NAME = cub3d.exe

MANDATORY	=	main_cub3d.c \
				src/get_str.c \
				src/get_str_2.c \
				src/init.c \
				src/move.c \
				src/parse.c \
				src/check.c \
				src/check_2.c \
				src/n_e_w_s.c \
				src/key_manager.c \
				src/utils.c \
				src/destroy.c \
				src/create.c \
				src/put.c \
				gnl/get_next_line.c \
				gnl/get_next_line_utils.c

OBJ = $(MANDATORY:.c=.o)

CC = gcc

INC = -I./includes

FLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C ./libft
		$(MAKE) -C ./minilibx
		cp libft/libft.a .
		$(CC) $(FLAGS) $(INC) $(MANDATORY) -fsanitize=address -g3 libft.a -o $(NAME) -L minilibx -lmlx -framework OpenGL -framework AppKit

clean:
	$(MAKE) clean -C ./libft
	rm -rf *.o
	rm -rf src/*.o

fclean: clean
	$(MAKE) fclean -C ./libft
	$(MAKE) clean -C ./minilibx
	rm -rf a.out
	rm -rf a.out.dSYM
	rm -rf *.a
	rm -rf cub3d.exe.dSYM
	rm -rf cub3d.exe

re: fclean all

.PHONY:	all clean fclean bonus re
