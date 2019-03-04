/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <hutricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:25:47 by hutricot          #+#    #+#             */
/*   Updated: 2019/03/04 14:59:38 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

void    zoom(t_value *v, int x, int y) 
{
        t_data d;
        t_data n;
        double distx;
        double disty;
        d.x = ((v->o[R] - v->o[L]) * x / WIDTH + v->o[L]);
        distx = (d.x - v->o[L]) * v->h;
        n.x1 = d.x - distx;
        n.x2 = n.x1 + (v->o[R] - v->o[L]) * v->h;
        v->o[L] = n.x1;
        v->o[R] = n.x2;

        d.y1 = v->o[T];
        d.y2 = v->o[B];
        d.y = ((v->o[B] - v->o[T]) * (HEIGHT - y)  / HEIGHT  + v->o[T]);
        disty = (d.y - v->o[T]) * v->h;
        n.y1 = d.y - disty;
        n.y2 = n.y1 + (d.y2 - d.y1) * v->h;
        v->o[T] = n.y1;
        v->o[B] = n.y2;
}
