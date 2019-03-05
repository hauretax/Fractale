/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <hutricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:13:53 by hutricot          #+#    #+#             */
/*   Updated: 2019/03/05 15:32:51 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	if (!(ft_strcmp("julia", argv[1])))
		ft_hook(1);
	else if (!(ft_strcmp("mandelbrot", argv[1])))
		ft_hook(2);
	else if (!(ft_strcmp("burningship", argv[1])))
		ft_hook(3);
	else if (!(ft_strcmp("julia_2", argv[1])))
		ft_hook(4);
	return (0);
}
