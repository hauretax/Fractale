/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <hutricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:18:02 by hutricot          #+#    #+#             */
/*   Updated: 2019/03/06 13:42:28 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

static int	deal_key(int key, t_struct *s)
{
	mlx_clear_window(s->ptr.mlx, s->ptr.win);
	if (key == 13)
		s->v.o[B] -= 0.1;
	if (key == 13)
		s->v.o[T] -= 0.1;
	if (key == 0)
		s->v.o[L] += 0.1;
	if (key == 0)
		s->v.o[R] += 0.1;
	if (key == 1)
		s->v.o[T] += 0.1;
	if (key == 1)
		s->v.o[B] += 0.1;
	if (key == 2)
		s->v.o[L] -= 0.1;
	if (key == 2)
		s->v.o[R] -= 0.1;
	if (key == 69)
		s->v.acuracy += 50;
	if (key == 78)
		s->v.acuracy -= 50;
	deal_key_2(key, s);
	ft_init(s);
	return (1);
}

static int	where(int key, int x, int y, t_struct *s)
{
	if (key == 4)
	{
		mlx_clear_window(s->ptr.mlx, s->ptr.win);
		if (s->v.c_z == 2)
			s->v.h = 1 / 1.10;
		s->v.c_z = 1;
		s->v.h /= 1.10;
		zoom(&s->v, x, y);
		ft_init(s);
	}
	if (key == 1)
		s->v.lock = s->v.lock == 1 ? 2 : 1;
	if (key == 5)
	{
		mlx_clear_window(s->ptr.mlx, s->ptr.win);
		if (s->v.c_z == 1)
			s->v.h = 1 * 1.10;
		s->v.c_z = 2;
		s->v.h *= 1.10;
		zoom(&s->v, x, y);
		ft_init(s);
	}
	return (1);
}

static int	ft_mouss_moov(int x, int y, t_struct *s)
{
	if (s->v.lock == 1)
	{
		mlx_clear_window(s->ptr.mlx, s->ptr.win);
		s->v.c[X] = (s->v.o[R] - s->v.o[L]) * x / WIDTH + s->v.o[L];
		s->v.c[Y] = (s->v.o[B] - s->v.o[T]) * (HEIGHT - y) / HEIGHT + s->v.o[T];
		ft_init(s);
	}
	return (0);
}

static void	init(t_value *v, int z)
{
	if (z == 2 || z == 4)
	{
		v->o[L] = -2.1;
		v->o[R] = 0.6;
		v->o[T] = -1.2;
		v->o[B] = 1.2;
		v->c_o = 0.75;
	}
	if (z == 1)
	{
		v->o[L] = -1.1;
		v->o[R] = 1;
		v->o[T] = -1.2;
		v->o[B] = 1.2;
		v->c_o = 0.75;
	}
	if (z == 3)
	{
		v->o[L] = -2;
		v->o[R] = 1.5;
		v->o[T] = -1.5;
		v->o[B] = 1.5;
	}
}

void		ft_hook(int z)
{
	t_value		v;
	t_ptr		ptr;
	t_struct	s;

	init(&v, z);
	v.z = z;
	v.lock = 1;
	v.po = 2;
	v.h = 1;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WIDTH, HEIGHT, "tu as vu ma fractol ?");
	ptr.img = mlx_new_image(ptr.mlx, WIDTH, HEIGHT);
	ptr.con = (int *)mlx_get_data_addr(ptr.img, &(ptr.b), &(ptr.s), &(ptr.v));
	s.ptr = ptr;
	s.v = v;
	ft_init(&s);
	mlx_mouse_hook(ptr.win, where, (void *)&s);
	mlx_hook(ptr.win, 6, 0, &ft_mouss_moov, &s);
	mlx_hook(ptr.win, 2, 0, &deal_key, (void *)&s);
	mlx_loop(ptr.mlx);
}
