/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 15:10:17 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 17:29:44 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int		ft_finditem(char *haystack, char item)
{
	int	i;

	i = -1;
	if (haystack)
		while (haystack[++i])
			if (haystack[i] == item)
				return (i);
	return (-1);
}

char	*ft_get_buffer_chunck(int fd, int *status)
{
	char	*str;
	char	*tmp;
	int		i;

	str = ft_strnew(BUFF_SIZE);
	tmp = ft_strnew(BUFF_SIZE);
	i = read(fd, tmp, BUFF_SIZE);
	if (i > 0)
		str = ft_strcpy(str, tmp);
	if (i == 0)
		(*status) = 0;
	if (i < 0)
		(*status) = -1;
	free(tmp);
	return (str);
}

void	append_chunk(int fd, char **str, int *status)
{
	char	*s1;
	char	*tmp;

	s1 = ft_get_buffer_chunck(fd, status);
	tmp = (*str);
	(*str) = ft_strjoin((*str), s1);
	free(tmp);
	free(s1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*g_b = NULL;
	char			*tmp;
	int				e;
	int				i;

	e = 1;
	if (g_b == NULL)
		g_b = ft_strnew(0);
	while ((i = ft_finditem(g_b, '\n')) < 0 && e == 1)
		append_chunk(fd, &g_b, &e);
	(*line) = (i > 0 ? ft_strsub(g_b, 0, i) : NULL);
	tmp = g_b;
	g_b = ft_strsub(g_b, i + 1, ((ft_strlen(g_b) - i)));
	free(tmp);
	if(e != 1)
		free(g_b);
	return (e);
}
