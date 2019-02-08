/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:18:32 by hutricot          #+#    #+#             */
/*   Updated: 2019/01/18 15:18:41 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_free(char *s1, char *s2)
{
	if (s1 != NULL)
	{
		free(s1);
		s1 = NULL;
	}
	if (s2 != NULL)
	{
		free(s2);
		s2 = NULL;
	}
	return (0);
}

static char	*ft_strjoin_f(char *s1, char *s2)
{
	char *str;

	if (s1 == NULL)
	{
		if ((str = ft_strdup(s2)) == 0)
			return (0);
		return (str);
	}
	else
	{
		if ((str = ft_strjoin(s1, s2)) == 0)
			return (0);
		ft_free(s1, NULL);
		return (str);
	}
}

int			ft_get_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (read(fd, buf, 0) || BUFF_SIZE <= 0 || !line)
		return (-1);
	*line = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if ((*line = ft_strjoin_f(*line, buf)) == NULL)
			return (ft_free(*line, NULL));
		if (ft_strstr(buf, "\n"))
			break ;
	}
	if (ret == 0)
		return (0);
	return (1);
}
