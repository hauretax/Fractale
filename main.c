/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <hutricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:13:53 by hutricot          #+#    #+#             */
/*   Updated: 2019/03/07 13:52:04 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "usage: ./fractol", 16);
		write(1, "\"julia\" \"mandelbrot\" \"burningship\" ", 42);
		write(1, "\"julia_2\"\n", 11);
		return (0);
	}
	if (!(ft_strcmp("julia", argv[1])))
		ft_hook(1);
	else if (!(ft_strcmp("mandelbrot", argv[1])))
		ft_hook(2);
	else if (!(ft_strcmp("burningship", argv[1])))
		ft_hook(3);
	else if (!(ft_strcmp("julia_2", argv[1])))
		ft_hook(4);
	write(1, "usage: ./fractol", 16);
	write(1, "usage: \"julia\" \"mandelbrot\" \"burningship\" ", 42);
	write(1, "\"julia_2\"\n", 11);
	return (0);
}
