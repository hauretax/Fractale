/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 12:52:07 by hutricot          #+#    #+#             */
/*   Updated: 2019/02/08 16:08:54 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_H
# define H_H
# include <unistd.h>
# define WIDTH 1400
# define HEIGHT 1000
# define Y 1
# define X 0
# include "mlx.h"

typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*con;
	int		b;
	int		s;
	int		v;
}				t_ptr;

#endif
