/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <hutricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 13:37:48 by hutricot          #+#    #+#             */
/*   Updated: 2019/03/05 13:56:23 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

void ft_exit(t_struct *s)
{
    mlx_destroy_image(s->ptr.mlx, s->ptr.img);
    exit(0);
}