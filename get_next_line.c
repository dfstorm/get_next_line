/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 14:57:11 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/01 18:57:44 by ggenois     ###    #+. /#+    ###.fr     */
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

char	*ft_readfile_once(int fd, int *err)
{
	int		i;
	char	cbuffer[BUFF_SIZE];
	char	*str;
	int		eof;

	eof = 0;
	str = ft_strnew(1);
	if (BUFF_SIZE < 1 || str == NULL)
		return (0);
	while ((i = read(fd, cbuffer, BUFF_SIZE)) > 0)
	{
		eof = 1;
		if ((str = ft_strnew(i + 1)) == NULL)
			return (0);
		str = ft_strncpy(str, cbuffer, i);
		break ;
	}
	if (i < 0)
		(*err) = 1;
	return (eof ? str : NULL);
}

int		get_next_line(const int fd, char **line)
{
	static char		*g_b = "";
	char			*tmp;
	int				i;
	int				err;

	err = 0;
	if (fd < 0)
		return (-1);
	while ((i = ft_finditem(g_b, '\n')) < 0)
	{
		if ((tmp = ft_readfile_once(fd, &err)) == NULL && !err)
		{
			if (g_b == NULL || ft_strlen(g_b) == 0)
				return (0);
			break ;
		}
		if (err == 1)
			return (-1);
		g_b = ft_strjoin_patched(g_b, tmp);
	}
	(*line) = (i ? ft_strdup(ft_strsplit(g_b, '\n')[0]) : ft_strnew(1));
	g_b = (tmp == NULL ? NULL :
		ft_strsub(g_b, i + 1, (ft_strlen(g_b) - i - 1)));
	return (1);
}
