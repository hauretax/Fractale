/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:13:53 by hutricot          #+#    #+#             */
/*   Updated: 2019/02/08 16:15:54 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

void	ft_mandelbrot(t_ptr *ptr)
{
	int	mx_i;
	int i[2];
	float zoom_x;
	float zoom_y;
	float x1;
	float x2;
	float y1;
	float y2;
	float c_r;
	float c_i;
	float z_r;
	float z_i;
	float i2;
	float tmp;

	x1 = - 2.1;
	x2 = 0.6;
	y1 = -1.2;
	y2 = 1.2;
	mx_i = 500;

	zoom_x = WIDTH / (x2 - x1);
	zoom_y = HEIGHT / (y2  - y1);

	i[Y] = 0;
	while (i[Y] < HEIGHT)
	{
	i[X] = 0;
		while (i[X] < WIDTH)
		{
			c_r = i[X]/zoom_x+x1;
			c_i = i[Y]/zoom_y+y1;
			z_r = 0;
			z_i = 0;
			i2 = 0;

			while(z_r * z_r + z_i * z_i < 4 && i2 < mx_i)
			{
				tmp = z_r;
				z_r = z_r*z_r - z_i*z_i + c_r;
				z_i =2 * tmp * z_i + c_i;
				i2++;
			}
			if (i2 == mx_i)
				ptr->con[i[Y] * WIDTH + i[X]] = 0xFF0000;
			i[X]++;
		}
		i[Y]++;
	}
}

int main(void)
{
	t_ptr ptr;

	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WIDTH, HEIGHT, "tas vus ma fractol ?");
	ptr.img = mlx_new_image(ptr.mlx, WIDTH, HEIGHT);
	ptr.con = (int *)mlx_get_data_addr(ptr.img, &(ptr.b), &(ptr.s), &(ptr.v));
	int x;
	int y;

	x = WIDTH/2*-1;
	y = HEIGHT/2;
	while (x < WIDTH/2)
		ptr.con[y * WIDTH + x++ + WIDTH / 2] = 0x00FF00;
	y = HEIGHT/2*-1;
	x = WIDTH/2;
	while (y < HEIGHT/2)
		ptr.con[((y++) + HEIGHT / 2) * WIDTH + x] = 0x0000FF;
	ft_mandelbrot(&ptr);
	mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.img, -10, -10);
	mlx_destroy_image(ptr.mlx, ptr.img);
	mlx_loop(ptr.mlx);
	return (0);
}
