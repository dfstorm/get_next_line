/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 15:10:17 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/08 17:32:29 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char	*ft_get_buffer_chunck(int fd, int *status)
{
	char	*str;
	char	*tmp;
	int		i;

	str = NULL;
	tmp = ft_strnew(BUFF_SIZE);
	i = read(fd, tmp, BUFF_SIZE);
	if (i > 0)
	{
		str = ft_strnew(i);
		str = ft_strcpy(str, tmp);
	}
	if (i == 0)
		(*status) = 0;
	if (i < 0)
		(*status) = -1;
	free(tmp);
	return (str);
}

void	append_chunk(int fd, void **str, int *status)
{
	char	*s1;
	char	*tmp;

	s1 = ft_get_buffer_chunck(fd, status);
	if (s1 != NULL)
	{
		tmp = (*str);
		(*str) = ft_strjoin((*str), s1);
		free(tmp);
	}
	free(s1);
}

void	read_last_line(int a, int *i, int *e)
{
	if (a > 0 && (*e) == 0)
	{
		(*i) = a;
		(*e) = 1;
	}
}

t_list	*align_me(t_list **g_b_ref, int fd, int mode)
{
	t_list			*lst;

	lst = (*g_b_ref);
	while (lst)
	{
		if (lst->content_size == (size_t)fd && mode == 0)
			return (lst);
		if (lst->content_size == (size_t)fd && mode == 1)
		{
			free(lst->content);
			lst->content = NULL;
		}
		lst = lst->next;
	}
	free(lst);
	lst = NULL;
	if (mode == 0)
	{
		lst = ft_lstnew(NULL, sizeof(char));
		lst->content_size = (size_t)fd;
		ft_lstadd(g_b_ref, lst);
	}
	return (lst);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*g_b_ref;
	t_list			*g_b;
	t_list			*tmp;
	int				e;
	int				i;

	if (fd < 0 || line == NULL)
		return (-1);
	e = 1;
	g_b = align_me(&g_b_ref, fd, 0);
	if (g_b->content == NULL)
		g_b->content = ft_strnew(0);
	while ((i = ft_strfindchar(g_b->content, '\n')) < 0 && e == 1)
		append_chunk(fd, &g_b->content, &e);
	read_last_line(ft_strlen(g_b->content), &i, &e);
	(*line) = (i > 0 ? ft_strsub(g_b->content, 0, i) : ft_strnew(0));
	tmp = g_b->content;
	g_b->content = ft_strsub((char*)g_b->content, i + 1,
		((ft_strlen((char*)g_b->content) - i)));
	free(tmp);
	if (e != 1)
		g_b = align_me(&g_b_ref, fd, 1);
	return (e);
}
