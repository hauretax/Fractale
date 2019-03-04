/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <hutricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:13:53 by hutricot          #+#    #+#             */
/*   Updated: 2019/03/04 12:00:04 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"
#include "libft/libft.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	return (0);
	if (ft_strcmp("julia", argv[1]))
		ft_hook(1);
	if (ft_strcmp("mandelbrot", argv[1]))
		ft_hook(2);
	return (0);
}
