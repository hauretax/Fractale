/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:23:45 by hutricot          #+#    #+#             */
/*   Updated: 2019/01/19 12:28:18 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *b_l)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = b_l;
	if (tmp == NULL)
		return (0);
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
