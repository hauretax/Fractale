/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <hutricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 12:52:07 by hutricot          #+#    #+#             */
/*   Updated: 2019/02/20 19:15:08 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_H
# define H_H
# include <unistd.h>
# define WIDTH 1080
# define HEIGHT 960
# define Y 1
# define X 0
# define L 0
# define R 1
# define T 2
# define B 3
# include "mlx.h"
#include <stdlib.h>

typedef struct	s_ptr
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*con;
	int		b;
	int		s;
	int		acuracy;
	int		v;
	double	c_o;
	double	z;
	long double z1;
	double	o[4];
	double	h;
}				t_ptr;

typedef struct	s_value
{
	int		mx_i;
	double x1;
	double x2;
	double y1;
	double y2;
	double c_r;
	double c_i;
	double z_r;
	double z_i;
	double tmp;
}				t_value;

typedef struct s_data
{
	double x;
	double y;
	double x1;
	double y1;
	double x2;
	double y2;
}				t_data;

void	ft_mandelbrot(t_ptr *ptr);
void	ft_hook(void (*ft_fractal)(t_ptr *));
void	zoom(t_ptr *ptr, int x, int y);

#endif
