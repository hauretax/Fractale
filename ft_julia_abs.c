/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia_abs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <hutricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:56:14 by hutricot          #+#    #+#             */
/*   Updated: 2019/03/07 14:07:37 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"
#include <math.h>

void		ft_julia_abs(t_struct *s)
{
	int		i2;
	t_value	*v;

	s->v.c_r = s->v.c[X];
	s->v.c_i = s->v.c[Y];
	s->v.z_r = s->v.x1 + s->v.i[X] * (s->v.x2 - s->v.x1) / WIDTH;
	s->v.z_i = s->v.y1 + s->v.i[Y] * (s->v.y2 - s->v.y1) / HEIGHT;
	s->v.z_i = s->v.y2 - s->v.z_i + s->v.y1;
	i2 = 0;
	v = &s->v;
	while (v->z_r * v->z_r + v->z_i * v->z_i < 4 && i2 < v->mx_i)
	{
		v->tmp = v->z_r;
		v->z_r = fabs(powf(v->z_r, v->po) - powf(v->z_i, v->po)) + v->c_r;
		v->z_i = fabs(2 * v->tmp * v->z_i + v->c_i);
		(i2)++;
	}
	if (i2 == s->v.mx_i)
		s->ptr.con[s->v.i[Y] * WIDTH + s->v.i[X]] = 0x000000;
	else
		s->ptr.con[s->v.i[Y] * WIDTH + s->v.i[X]] = 0x01DF3A / (i2 + 1);
}
