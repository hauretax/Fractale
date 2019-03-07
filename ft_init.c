/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <hutricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:26:58 by hutricot          #+#    #+#             */
/*   Updated: 2019/03/07 13:37:57 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

void		ft_init(t_struct *s)
{
	s->v.x1 = (s->v.o[0]);
	s->v.x2 = (s->v.o[1]);
	s->v.y1 = (s->v.o[2]);
	s->v.y2 = (s->v.o[3]);
	s->v.mx_i = 50 + s->v.acuracy;
	if (s->v.acuracy <= 0)
		s->v.acuracy = 0;
	if (s->v.z == 1)
		julia(s);
	if (s->v.z == 2)
		mandelbrot(s);
	if (s->v.z == 3)
		burningship(s);
	if (s->v.z == 4)
		julia_abs(s);
	mlx_put_image_to_window(s->ptr.mlx, s->ptr.win, s->ptr.img, 0, 0);
}
