/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <hutricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:56:14 by hutricot          #+#    #+#             */
/*   Updated: 2019/03/07 13:39:11 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

static void	ft_calcul(t_value *v, int *i2)
{
	while (v->z_r * v->z_r + v->z_i * v->z_i < 4 && *i2 < v->mx_i)
	{
		v->tmp = v->z_r;
		v->z_r = v->z_r * v->z_r - v->z_i * v->z_i + v->c_r;
		v->z_i = 2 * v->tmp * v->z_i + v->c_i;
		(*i2)++;
	}
}

void		ft_mandelbrot(t_struct *s)
{
	int i2;

	s->v.c_r = s->v.x1 + s->v.i[X] * (s->v.x2 - s->v.x1) / WIDTH;
	s->v.c_i = s->v.y1 + s->v.i[Y] * (s->v.y2 - s->v.y1) / HEIGHT;
	s->v.c_i = s->v.y2 - s->v.c_i + s->v.y1;
	s->v.z_r = 0;
	s->v.z_i = 0;
	i2 = 0;
	ft_calcul(&s->v, &i2);
	if (i2 == s->v.mx_i)
		s->ptr.con[s->v.i[Y] * WIDTH + s->v.i[X]] = 0x000000;
	else
		s->ptr.con[s->v.i[Y] * WIDTH + s->v.i[X]] = 0xFF00FF / i2;
}