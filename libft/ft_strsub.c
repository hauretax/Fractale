/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 10:51:34 by hutricot          #+#    #+#             */
/*   Updated: 2019/01/17 15:14:24 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sr;
	int		i;

	i = 0;
	if (s == 0)
		return (0);
	if ((sr = malloc((len + 1) * sizeof(char))) == 0)
		return (0);
	while (len > 0 && s[start])
	{
		sr[i] = s[start];
		len--;
		i++;
		start++;
	}
	sr[i] = '\0';
	return (sr);
}
