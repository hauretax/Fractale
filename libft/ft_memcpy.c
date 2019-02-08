/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:34:19 by hutricot          #+#    #+#             */
/*   Updated: 2018/11/12 13:26:38 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ssrc;
	unsigned char	*ddest;
	size_t			i;

	i = 0;
	ssrc = (unsigned char *)src;
	ddest = (unsigned char *)dest;
	if (n == 0)
		return (dest);
	while (i < n)
	{
		ddest[i] = ssrc[i];
		i++;
	}
	return (ddest);
}
