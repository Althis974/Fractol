# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/14 14:34:00 by rlossy       #+#   ##    ##    #+#        #
#   Updated: 2018/04/09 12:11:43 by rlossy      ###    #+. /#+    ###.fr     # #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME		=	fractol
LIB_DIR		=	./libft
LIBX_DIR	=	./minilibx_macos
HEADER		=	./includes/
FILENAMES	=	main.c ft_color.c ft_env.c ft_fractal.c ft_set.c ft_trace.c
FILENAMES	+=	ft_keycode.c ft_kcode.c ft_fractal_partwo.c

SOURCES		=	$(addprefix srcs/, $(FILENAMES))
OBJECTS		=	$(addprefix build/, $(FILENAMES:.c=.o)) 

L_FT		=	$(LIB_DIR)
LIB_LNK		=	-L $(L_FT) -l ft
LIB_INC		=	-I $(L_FT)/libft.h


LX_FT		=	$(LIBX_DIR)
LIBX_LNK	=	-L $(LX_FT) -l mlx
LIBX_INC	=	-I $(LX_FT)/mlx.h

FLAGS		=	-Wall -Wextra -Werror -O2
FLAGX		=	-framework OpenGL -framework AppKit

.PHONY: all clean fclean re


all: $(NAME)

clean:
	@echo "\033[31m"
	rm -rf build/
	@$(MAKE) -C $(L_FT) clean

fclean: clean
	@echo "\033[31m"
	rm -f $(NAME)
	@$(MAKE) -C $(L_FT) fclean
	@$(MAKE) -C $(LX_FT) clean

re: 
	@$(MAKE) fclean 
	@$(MAKE) all

build: 
	@echo "\033[35m"
	mkdir build/

$(NAME): $(OBJECTS)
	@$(MAKE) -C $(L_FT)
	@$(MAKE) -C $(LX_FT)
	@echo "\033[32m"
	gcc $(FLAGS) -I $(HEADER) $(OBJECTS) $(LIB_LNK) $(LIBX_LNK) $(FLAGX) -o $@

build/%.o: srcs/%.c | build
	gcc $(FLAGS) $(LIB_INC) -I $(HEADER) -c $< -o $@
