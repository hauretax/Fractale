/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:38:03 by hutricot          #+#    #+#             */
/*   Updated: 2019/02/06 11:15:39 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 1

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_error(int e);
void				ft_swap(int *a, int *b);
void				ft_freelst(t_list **alst);
int					ft_lstsize(t_list *b_l);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_lstadd_b(t_list **b_l, t_list *new);
t_list				*ft_lstnew(void const *content, size_t content_size);
int					ft_atoi(const char *str);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *sr);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *str);
char				*ft_strstr(const char *str, const char *to_find);
void				ft_putstr(char const *str);
int					ft_get_line(const int fd, char **line);

#endif
