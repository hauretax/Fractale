# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hutricot <hutricot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 15:13:34 by hutricot          #+#    #+#              #
#    Updated: 2019/03/04 18:38:34 by hutricot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fractol \

FLAGS = -Wall -Wextra

SRC = \
	main.c \
	ft_mandelbrot.c \
	ft_hook.c \
	zoom.c \
	ft_init.c \
	ft_julia.c \
	ft_burningship.c \
	  
OBJ = $(SRC:.c=.o)

INC = h.h


all: $(NAME)

$(NAME) : $(INC) $(OBJ) $(SRC)
	make -C libft
	gcc $(FLAGS) -c $(SRC) -I$(INC)
	gcc $(FLAGS) -o $(NAME) libft/libft.a $(OBJ) -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGl -framework AppKit 

test : all
	./$(NAME) julia
	
clean :
	rm -f $(OBJ)
	make clean -C libft

fclean : clean
	rm -f $(NAME)
	rm -f libft/libft.a

re : fclean all

