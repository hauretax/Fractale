/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <hutricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:05:06 by hutricot          #+#    #+#             */
/*   Updated: 2019/02/20 16:22:23 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

void    zoom_out(t_ptr *ptr, int x, int y) 
{
t_data d;
t_data n;
double distx;
double disty;
        d.x = ((ptr->o[R] - ptr->o[L]) * x / WIDTH + ptr->o[L]);
        distx = (d.x - ptr->o[L]) / ptr->h;
        n.x1 = d.x - distx;
        n.x2 = n.x1 + (ptr->o[R] - ptr->o[L]) / ptr->h;
        ptr->o[L] = n.x1;
        ptr->o[R] = n.x2;

        d.y1 = ptr->o[T];
        d.y2 = ptr->o[B];
        d.y = ((ptr->o[B] - ptr->o[T]) * (HEIGHT - y)  / HEIGHT  + ptr->o[T]);
        disty = (d.y - ptr->o[T]) / ptr->h;
        n.y1 = d.y - disty;
        n.y2 = n.y1 + (d.y2 - d.y1) / ptr->h;
        ptr->o[T] = n.y1;
        ptr->o[B] = n.y2;
}
