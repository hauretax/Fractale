/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:01:12 by hutricot          #+#    #+#             */
/*   Updated: 2018/11/16 15:27:45 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *sr)
{
	int			i;
	char		*s;
	char		*src;

	src = (char *)sr;
	i = 0;
	while (src[i])
		i++;
	if ((s = malloc(i + 1 * sizeof(char))) == 0)
		return (NULL);
	i = 0;
	while (src[i])
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
