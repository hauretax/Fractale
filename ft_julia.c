/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <hutricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:56:14 by hutricot          #+#    #+#             */
/*   Updated: 2019/02/21 13:23:25 by hutricot         ###   ########.fr       */
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

void	ft_julia(t_ptr *ptr, t_value *v, int i[2])
{
	int i2;

	v->c_r = 0.258;
	v->c_i = 0.01;
	v->z_r = v->x1 + i[X] * (v->x2 - v->x1) / WIDTH;
	v->z_i = v->y1 + i[Y] * (v->y2 - v->y1) / HEIGHT;
	v->z_i = v->y2 - v->z_i + v->y1;
	i2 = 0;
	ft_calcul(v, &i2);
	if (i2 == v->mx_i)
		ptr->con[i[Y] * WIDTH + i[X]] = 0x000000;
	else
		ptr->con[i[Y] * WIDTH + i[X]] = 0x00FFFF / (i2 + 1);
}