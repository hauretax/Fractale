/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <hutricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:18:02 by hutricot          #+#    #+#             */
/*   Updated: 2019/03/04 15:00:00 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

static int deal_key(int key, t_struct *s)
{
	mlx_clear_window(s->ptr.mlx, s->ptr.win);
	if (key == 53)
		exit (0);
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
	ft_init(s);
	return (1);
}

static int where(int key, int x, int y,t_struct *s)
{
	if (key == 4 || key ==  1)
	{
		mlx_clear_window(s->ptr.mlx, s->ptr.win	);
        s->v.h /= 1.10;
		zoom(&s->v, x, y);
		ft_init(s);
	}
	if (key == 5 || key == 2)
	{
		mlx_clear_window(s->ptr.mlx, s->ptr.win);
		s->v.h *= 1.10;
		zoom(&s->v, x, y);
		ft_init(s);
	}
	printf("%f\n", s->v.h);
	return (1);
}

void	ft_hook(int z)
{
	t_value		v;
	t_ptr		ptr;
	t_struct	s;

	v.o[L] = -2.1;
	v.o[R] = 0.6;
	v.o[T] = -1.2;
	v.o[B] = 1.2;
	v.c_o = 0.75;
	v.z = z;
	v.h = 1;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WIDTH, HEIGHT, "tas vus ma fractol ?");
	ptr.img = mlx_new_image(ptr.mlx, WIDTH, HEIGHT);
	ptr.con = (int *)mlx_get_data_addr(ptr.img, &(ptr.b), &(ptr.s), &(ptr.v));
	s.ptr = ptr;
	s.v = v;
	ft_init(&s);
	mlx_mouse_hook(ptr.win, where, (void *)&s);
	mlx_key_hook(ptr.win, deal_key, (void *)&s);
	mlx_loop(ptr.mlx);
}
