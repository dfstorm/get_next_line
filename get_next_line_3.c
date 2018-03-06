/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_3.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 15:10:17 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 17:09:54 by ggenois     ###    #+. /#+    ###.fr     */
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

int		get_next_line(const int fd, char **line)
{
	static char		*g_b = NULL;
	char			*stmp;
	int				i;
	int				j;
	char			*tmp;

	i = 1;
	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (g_b == NULL)
		g_b = ft_strdup("");
	while ((j = ft_finditem(g_b, '\n')) < 0)
	{
		stmp = ft_get_buffer_chunck(fd, &i);
		if (i == 1)
		{
			tmp = g_b;
			g_b = ft_strjoin(g_b, stmp);
			free(tmp);
		}
		else
		{
			free(stmp);
			break ;
		}
		free(stmp);
	}
	if (i == 0 && ft_strlen(g_b) > 0)
	{
		j = ft_strlen(g_b);
		i = 1;
	}
	(*line) = (j > 0 ? ft_strsub(g_b, 0, j) : ft_strnew(0));
	tmp = g_b;
	g_b = ft_strsub(g_b, j + 1, (ft_strlen(g_b) - (j + 1)));
	free(tmp);
	if (i == -1)
		free(g_b);
	return (i);
}
