/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <hutricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:26:58 by hutricot          #+#    #+#             */
/*   Updated: 2019/03/05 15:35:33 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

static void	mandelbrot(t_struct *s)
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
			ft_mandelbrot(&s->ptr, &s->v, i);
			i[X]++;
		}
		i[Y]++;
	}
}

static void	julia(t_struct *s)
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
			ft_julia(&s->ptr, &s->v, i);
			i[X]++;
		}
		i[Y]++;
	}
}

void		ft_init(t_struct *s)
{
	if (s->v.z == 1)
		julia(s);
	if (s->v.z == 2)
		mandelbrot(s);
	if (s->v.z == 3)
		ft_burningship(s);
	if (s->v.z == 4)
		ft_julia_abs(s);
	mlx_put_image_to_window(s->ptr.mlx, s->ptr.win, s->ptr.img, 0, 0);
}
