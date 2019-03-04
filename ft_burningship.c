/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burningship.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <hutricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:02:49 by hutricot          #+#    #+#             */
/*   Updated: 2019/03/04 19:05:14 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "h.h"
#include "math.h"

static void	ft_calcul(t_value *v, int *i2)
{
	while (v->z_r * v->z_r + v->z_i * v->z_i < 4 && *i2 < v->mx_i)
	{
		v->tmp = v->z_r;
		v->z_r = v->z_r * v->z_r - v->z_i * v->z_i + v->c_r;
		v->z_i = fabs(2 * v->tmp * v->z_i + v->c_i);
		(*i2)++;
	}
}

void    ft_burningship2(t_ptr *ptr, t_value *v, int i[2])
{
	int i2;

	v->c_r = v->x1 + i[X] * (v->x2 - v->x1) / WIDTH;
	v->c_i = v->y1 + i[Y] * (v->y2 - v->y1) / HEIGHT;
	v->z_r = 0;
	v->z_i = 0;
	i2 = 0;
	ft_calcul(v, &i2);
	if (i2 == v->mx_i)
		ptr->con[i[Y] * WIDTH + i[X]] = 0x000000;
	else
		ptr->con[i[Y] * WIDTH + i[X]] = 0xFF00FF / i2;
}

void    ft_burningship(t_struct *s)
{
	int		i[2];

	s->v.x1 = (s->v.o[0]);
	s->v.x2 = (s->v.o[1]);
	s->v.y1 = (s->v.o[2]);
	s->v.y2 = (s->v.o[3]);
	s->v.mx_i = 50 + s->v.acuracy;
	if (s->v.acuracy <= 0)
		s->v.acuracy = 0;
	i[Y] = 0;
	while (i[Y] < HEIGHT)
	{
		i[X] = 0;
		while (i[X] < WIDTH)
		{
			ft_burningship2(&s->ptr, &s->v, i);
			i[X]++;
		}
		i[Y]++;
	}
}