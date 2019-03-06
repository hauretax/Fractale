/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <hutricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:56:14 by hutricot          #+#    #+#             */
/*   Updated: 2019/03/06 17:53:53 by hutricot         ###   ########.fr       */
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

void *mandelbrot1(void *arg)
{
	t_struct *s;

	s = (t_struct *)arg;
		s->v.i[X] = 0;
		while (s->v.i[X] < WIDTH)
		{
			ft_mandelbrot(s);
			s->v.i[X]++;
		}
	pthread_exit (0);
}

void	mandelbrot(t_struct *s)
{
	pthread_t th[HEIGHT];
	t_struct *s_m[HEIGHT];
	int i;
	
	i = 0;
	while (i < 4)
	{
		s_m[i] = s;
		i++;
	}
	s->v.x1 = (s->v.o[0]);
	s->v.x2 = (s->v.o[1]);
	s->v.y1 = (s->v.o[2]);
	s->v.y2 = (s->v.o[3]);
	s->v.mx_i = 50 + s->v.acuracy;
	if (s->v.acuracy <= 0)
		s->v.acuracy = 0;

	i = 0;
	s->v.i[Y] = 0;
	while (s->v.i[Y] < HEIGHT)
	{
		if (pthread_create (&th[i], NULL, mandelbrot1, s_m[i]) < 0)
			exit(0);
		s->v.i[Y]++;
		i++;
		if (i == 4)
			{
				i = 0;
				while (i < 4)
				{
					pthread_join (th[i], NULL);
					i++;
				}
				i = 0;
			}
	}
	i = 0;
		
	while (i < 4)
	{
		pthread_join (th[i], NULL);
		i++;
	}
}