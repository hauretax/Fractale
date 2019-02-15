/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <hutricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:56:14 by hutricot          #+#    #+#             */
/*   Updated: 2019/02/15 14:21:16 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"


static void	ft_calcul(t_value *v, int *i2)
{
	while(v->z_r * v->z_r + v->z_i * v->z_i < 4 && *i2 < v->mx_i)
	{
		v->tmp = v->z_r;
		v->z_r = v->z_r * v->z_r - v->z_i * v->z_i + v->c_r;
		v->z_i =2 * v->tmp * v->z_i + v->c_i;
		(*i2)++;
	}
}

static void	ft_iter(t_ptr *ptr, t_value *v, int i[2])
{
	int i2;

	v->c_r = i[X]/v->zoom_x+v->x1;
	v->c_i = i[Y]/v->zoom_y+v->y1;
	v->z_r = 0;
	v->z_i = 0;
	i2 = 0;
	ft_calcul(v, &i2);
	if (i2 == v->mx_i)
		ptr->con[i[Y] * WIDTH + i[X]] = 0xFF0000;
	else
		ptr->con[i[Y] * WIDTH + i[X]] = 0x000000;
}

void	ft_mandelbrot(t_ptr *ptr)
{
	int 	i[2];
	t_value v;

 	v.x1 = (-2.1 - ptr->o[X]) * ptr->h;
    v.x2 = (0.6 - ptr->o[X]) * ptr->h;
    v.y1 = (-1.2 - ptr->o[Y]) * ptr->h;
    v.y2 = (1.2 - ptr->o[Y]) * ptr->h;
	v.mx_i = 50 + ptr->netter;
	v.zoom_x = WIDTH / (v.x2 - v.x1);
	v.zoom_y = HEIGHT / (v.y2  - v.y1);
	i[Y] = 0;
	while (i[Y] < HEIGHT)
	{
		i[X] = 0;
		while (i[X] < WIDTH)
		{
			ft_iter(ptr, &v, i);
			i[X]++;
		}
		i[Y]++;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
}
