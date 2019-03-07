/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <hutricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 11:41:03 by hutricot          #+#    #+#             */
/*   Updated: 2019/03/07 13:45:26 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

void	*mandelbrot1(void *arg)
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
	pthread_exit(0);
}

void	*mandelbrot2(void *arg)
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
	pthread_exit(0);
}

void	*mandelbrot3(void *arg)
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
	pthread_exit(0);
}

void	*mandelbrot4(void *arg)
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
	pthread_exit(0);
}

void	mandelbrot(t_struct *s)
{
	pthread_t	th[4];
	t_struct	s_m[4];

	s_m[0] = *s;
	s_m[1] = *s;
	s_m[2] = *s;
	s_m[3] = *s;
	if (pthread_create(&th[0], NULL, mandelbrot1, &s_m[0]) < 0)
		exit(0);
	if (pthread_create(&th[1], NULL, mandelbrot2, &s_m[1]) < 0)
		exit(0);
	if (pthread_create(&th[2], NULL, mandelbrot3, &s_m[2]) < 0)
		exit(0);
	if (pthread_create(&th[3], NULL, mandelbrot4, &s_m[3]) < 0)
		exit(0);
	if (pthread_join(th[0], NULL))
		exit(0);
	if (pthread_join(th[1], NULL))
		exit(0);
	if (pthread_join(th[2], NULL))
		exit(0);
	if (pthread_join(th[3], NULL))
		exit(0);
}
