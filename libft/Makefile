# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hutricot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 18:46:03 by hutricot          #+#    #+#              #
#    Updated: 2019/02/06 11:15:31 by hutricot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

CFLAGS = -Wall -Wextra  -I ./

S =		ft_strlen.c \
		ft_strdup.c \
		ft_error.c \
		ft_swap.c \
		ft_strcpy.c \
		ft_strstr.c \
		ft_strjoin.c \
		ft_putstr.c	\
		ft_get_line.c \
		ft_bzero.c \
		ft_atoi.c \
		ft_lstadd_b.c \
		ft_lstnew.c \
		ft_memcpy.c \
		ft_freelst.c \
		ft_lstsize.c

S_O = $(S:.c=.o)


all: $(NAME)
$(NAME) : $(S_O) 
	ar rc $(NAME) $(S_O)

clean :
	rm -f $(S_O)

fclean : clean
	rm -f $(NAME)

re : fclean all
