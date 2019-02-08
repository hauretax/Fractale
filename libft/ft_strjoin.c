/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 10:49:48 by hutricot          #+#    #+#             */
/*   Updated: 2018/11/14 13:50:20 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		y;
	char	*sr;

	if (s1 == 0 || s2 == 0)
		return (0);
	if ((sr = malloc(ft_strlen((char *)s1) + 1 + ft_strlen((char *)s2 + 1)
		+ 1 * sizeof(char))) == 0)
		return (0);
	i = 0;
	y = 0;
	while (s1[i])
		sr[y++] = *s1++;
	i = 0;
	while (s2[i])
		sr[y++] = *s2++;
	sr[y] = '\0';
	return (sr);
}
