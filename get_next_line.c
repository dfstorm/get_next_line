/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 14:57:11 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 21:56:54 by ggenois     ###    #+. /#+    ###.fr     */
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

char	*ft_readfile_once(int fd)
{
	int		i;
	char	cbuffer[BUFF_SIZE];
	char	*str;

	str = ft_strnew(1);
	if (BUFF_SIZE < 1 || str == NULL)
		return (0);
	while ((i = read(fd, cbuffer, BUFF_SIZE)) > 0)
	{
		if ((str = ft_strnew(i + 1)) == NULL)
			return (0);
		str = ft_strncpy(str, cbuffer, i);
		break ;
	}
	return (str);
}

char	*ft_strjoin_patched(char *s1, char *s2)
{
	int		x;
	char	*sx;

	x = (int)(ft_strlen(s1) + ft_strlen(s2));
	sx = ft_strnew(x);
	x = -1;
	if (s1 > 0)
		while (s1[++x] != '\0')
			sx[x] = s1[x];
	while (s2[x - ft_strlen(s1)] != '\0')
	{
		sx[x] = s2[x - ft_strlen(s1)];
		x++;
	}
	sx[x] = '\0';
	return (sx);
}

int		get_next_line(const int fd, char **line)
{
	static char		*g_b = "";
	char			*tmp;
	int				i;

	while (1)
	{
		if ((i = ft_finditem(g_b, '\n')) >= 0)
		{
			(*line) = (i ? ft_strdup(ft_strsplit(g_b, '\n')[0]) : ft_strnew(1));
			g_b = ft_strsub(g_b, i + 1, (ft_strlen(g_b) - i - 1));
			return (1);
		}
		if ((tmp = ft_readfile_once(fd)) == 0)
			return (-1);
		if (tmp[0] == '\0')
		{
			(*line) = g_b;
			return (0);
		}
		g_b = ft_strjoin_patched(g_b, tmp);
		free(tmp);
	}
	my_malloc_cleanup();
	return (0);
}
