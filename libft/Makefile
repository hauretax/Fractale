# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hutricot <hutricot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 18:46:03 by hutricot          #+#    #+#              #
#    Updated: 2019/03/04 11:43:32 by hutricot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

CFLAGS = -Wall -Wextra  -I ./

S =		ft_strcmp.c \

S_O = $(S:.c=.o)


all: $(NAME)
$(NAME) : $(S_O) 
	ar rc $(NAME) $(S_O)

clean :
	rm -f $(S_O)

fclean : clean
	rm -f $(NAME)

re : fclean all
