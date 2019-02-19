/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <hutricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:25:47 by hutricot          #+#    #+#             */
/*   Updated: 2019/02/19 17:21:13 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

void    zoom_in(t_ptr *ptr, int x, int y) 
{
 t_data d;
 t_data n;
double distx;
double disty;
        d.x1 = -2.1;
        d.x2 = 0.6;
        d.x = ((ptr->o[1] - ptr->o[0]) * x / WIDTH + ptr->o[0]);
        distx = (d.x - ptr->o[0]) * ptr->h;
        n.x1 = d.x - distx;
        n.x2 = n.x1 + (d.x2 - d.x1) * ptr->h;
        ptr->o[0] = n.x1;
        ptr->o[1] = n.x2;
        d.y1 = -1.2;
        d.y2 = 1.2;
        d.y = ((ptr->o[3] - ptr->o[2]) * y / HEIGHT  + ptr->o[2]) * -1;
        disty = (d.y - ptr->o[2]) * ptr->h;
        n.y1 = d.y - disty;
        n.y2 = n.y1 + (d.y2 - d.y1) * ptr->h;
        ptr->o[2] = n.y1;
        ptr->o[3] = n.y2;
}
