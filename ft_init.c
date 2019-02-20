/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <hutricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:26:58 by hutricot          #+#    #+#             */
/*   Updated: 2019/02/20 19:34:16 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

void	ft_init(t_ptr *ptr)
{
	int 	i[2];
	t_value v;

	v.x1 = ( ptr->o[0]);
	v.x2 = ( ptr->o[1]);
	v.y1 = ( ptr->o[2]);
	v.y2 = ( ptr->o[3]);
	v.mx_i = 50 + ptr->acuracy;
	i[Y] = 0;
	while (i[Y] < HEIGHT)
	{
		i[X] = 0;
		while (i[X] < WIDTH)
		{
			ft_mandelbrot(ptr, &v, i);
			i[X]++;
		}
		i[Y]++;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
}
