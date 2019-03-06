/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <hutricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:56:14 by hutricot          #+#    #+#             */
/*   Updated: 2019/03/06 18:28:20 by hutricot         ###   ########.fr       */
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
	s->v.i[Y] = 0;
	while (s->v.i[Y] < HEIGHT)
	{
		s->v.i[X] = 0;
		while (s->v.i[X] < WIDTH)
		{
			ft_mandelbrot(s);
			s->v.i[X] += 4;
		}
		s->v.i[Y]++;
	}
	pthread_exit (0);
}

void *mandelbrot2(void *arg)
{
	t_struct *s;

	s = (t_struct *)arg;
	s->v.i[Y] = 0;
	while (s->v.i[Y] < HEIGHT)
	{
		s->v.i[X] = 1;
		while (s->v.i[X] < WIDTH)
		{
			ft_mandelbrot(s);
			s->v.i[X] += 4;
		}
		s->v.i[Y]++;
	}
	pthread_exit (0);
}

void *mandelbrot3(void *arg)
{
	t_struct *s;

	s = (t_struct *)arg;
	s->v.i[Y] = 0;
	while (s->v.i[Y] < HEIGHT)
	{
		s->v.i[X] = 2;
		while (s->v.i[X] < WIDTH)
		{
			ft_mandelbrot(s);
			s->v.i[X] += 4;
		}
		s->v.i[Y]++;
	}
	pthread_exit (0);
}

void *mandelbrot4(void *arg)
{
	t_struct *s;

	s = (t_struct *)arg;
	s->v.i[Y] = 0;
	while (s->v.i[Y] < HEIGHT)
	{
		s->v.i[X] = 3;
		while (s->v.i[X] < WIDTH)
		{
			ft_mandelbrot(s);
			s->v.i[X] += 4;
		}
		s->v.i[Y]++;
	}
	pthread_exit (0);
}

void	mandelbrot(t_struct *s)
{
	pthread_t th[4];
	t_struct s_m[4];

	s->v.x1 = (s->v.o[0]);
	s->v.x2 = (s->v.o[1]);
	s->v.y1 = (s->v.o[2]);
	s->v.y2 = (s->v.o[3]);
	s->v.mx_i = 1000 + s->v.acuracy;
	if (s->v.acuracy <= 0)
		s->v.acuracy = 0;
	s_m[0] = *s;
	s_m[1] = *s;
	s_m[2] = *s;
	s_m[3] = *s;

		
		if (pthread_create (&th[0], NULL, mandelbrot1, &s_m[0]) < 0)
			exit(0);
		if (pthread_create (&th[1], NULL, mandelbrot2, &s_m[1]) < 0)
			exit(0);
		if (pthread_create (&th[2], NULL, mandelbrot3, &s_m[2]) < 0)
			exit(0);
		if (pthread_create (&th[3], NULL, mandelbrot4, &s_m[3]) < 0)
			exit(0);
		
		
		pthread_join (th[0], NULL);
		pthread_join (th[1], NULL);
		pthread_join (th[2], NULL);
		pthread_join (th[3], NULL);
}