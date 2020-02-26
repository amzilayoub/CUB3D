# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 12:18:11 by aamzil            #+#    #+#              #
#    Updated: 2020/02/25 20:43:42 by aamzil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=cub3D

SRC=	*.c					\
		bitmap/*.c			\
		error_handling/*.c	\
		libft/*.c			\
		gnl/*.c				\
		read_cub_file/*.c	\
		sprite/*.c			\
		
		
SRCB=	cub3D


all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -g $(SRC) -I /usr/local/include/ -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(SRCB)

fclean: clean
	rm -f $(NAME)

re: fclean all