/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <hutricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:18:02 by hutricot          #+#    #+#             */
/*   Updated: 2019/02/20 19:19:23 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

static int deal_key(int key, t_ptr *ptr, void (*ft_fractal)(t_ptr *))
{
	mlx_clear_window(ptr->mlx, ptr->win);
	if (key == 53)
		exit (0);
	if (key == 13)
		ptr->o[B] -= 0.1;
	if (key == 13)
		ptr->o[T] -= 0.1;
	if (key == 0)
		ptr->o[L] += 0.1;
	if (key == 0)
		ptr->o[R] += 0.1;
	if (key == 1)
		ptr->o[T] += 0.1;
	if (key == 1)
		ptr->o[B] += 0.1;
	if (key == 2)
		ptr->o[L] -= 0.1;
	if (key == 2)
		ptr->o[R] -= 0.1;
	if (key == 69)
		ptr->acuracy += 50;
	if (key == 78)
		ptr->acuracy -= 50;
	ft_mandelbrot(ptr);
	return (1);
}

static int where(int key, int x, int y,t_ptr *ptr)
{
	if (key == 4 || key ==  1)
	{
		mlx_clear_window(ptr->mlx, ptr->win	);
        ptr->h *= 0.90;
		zoom(ptr, x, y);
		ft_mandelbrot(ptr);
	}
	if (key == 5 || key == 2)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		ptr->h *= 1.10;
		zoom(ptr, x, y);
		ft_mandelbrot(ptr);
	}
	printf("%f\n", ptr->h);
	return (1);
}

void	ft_hook(void (*ft_fractal)(t_ptr *))
{
	t_ptr ptr;

	ptr.o[L] = -2.1;
	ptr.o[R] = 0.6;
	ptr.o[T] = -1.2;
	ptr.o[B] = 1.2;
	ptr.c_o = 0.75;
	ptr.h = 1;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WIDTH, HEIGHT, "tas vus ma fractol ?");
	ptr.img = mlx_new_image(ptr.mlx, WIDTH, HEIGHT);
	ptr.con = (int *)mlx_get_data_addr(ptr.img, &(ptr.b), &(ptr.s), &(ptr.v));
	ft_fractal(&ptr);
	mlx_mouse_hook(ptr.win, where, (void *)&ptr);
	mlx_key_hook(ptr.win, deal_key, (void *)&ptr);
	mlx_loop(ptr.mlx);
}
