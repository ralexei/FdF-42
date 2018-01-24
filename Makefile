# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alrusu <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 14:06:22 by alrusu            #+#    #+#              #
#    Updated: 2017/01/26 13:54:46 by alrusu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = fdf.c tools.c transform_bonus.c draw.c process_map.c
FLAGS = -Wall -Wextra -Werror
OFILES = $(SRC:%.c=%.o)
LIB = libft/libft.a

all: $(LIB) $(NAME)

$(NAME): libft/libft.a $(OFILES)
	@gcc $(FLAGS) -o $@ $^ -lmlx -framework OpenGL \
		-framework AppKit -lft -Llibft -lm

$(LIB):
	@make -C libft

%.o: %.c fdf.h keys.h
	@gcc $(FLAGS) -c -o $@ $<

clean:
	@rm -f $(OFILES) fdf.h.gch keys.h.gch
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean
