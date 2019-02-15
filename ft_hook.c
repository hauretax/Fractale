/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <hutricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:18:02 by hutricot          #+#    #+#             */
/*   Updated: 2019/02/15 14:34:05 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

static int deal_key(int key, t_ptr *ptr, void (*ft_fractal)(t_ptr *))
{
	mlx_clear_window(ptr->mlx, ptr->win);
	if (key == 53)
		exit (0);
	if (key == 13)
		ptr->o[Y] += 0.1;
	if (key == 0)
		ptr->o[X] += 0.1;
	if (key == 1)
		ptr->o[Y] -= 0.1;
	if (key == 2)
		ptr->o[X] -= 0.1;
	ft_mandelbrot(ptr);
	return (1);
}

static int where(int key, int x, int y,t_ptr *ptr)
{
	    int d_x;
    d_x = x - WIDTH / 2 ;

	if (key == 4)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		ptr->o[X] = (x - WIDTH / 2) * 0.0018518;
		ptr->o[Y] = (y - HEIGHT / 2) * 0.0020833;
		ptr->netter;
		ptr->h *= 0.8;
		ft_mandelbrot(ptr);
	}
	if (key == 5)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		ptr->o[X] = (x + WIDTH / 2) * 0.0018518;
		ptr->o[Y] = (y + HEIGHT / 2) * 0.0020833;
		ptr->netter;
		ptr->h /= 0.8;
		ft_mandelbrot(ptr);
	}
	return (1);
}

void	ft_hook(void (*ft_fractal)(t_ptr *))
{
	t_ptr ptr;

	ptr.o[X] = 0;
	ptr.o[Y] = 0;
	ptr.c_o = 0.6 - (0.6 + 2.1) / 2;
	ptr.z = 0.6 + 2.1;
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
