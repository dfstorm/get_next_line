/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 14:57:11 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/27 23:20:41 by ggenois     ###    #+. /#+    ###.fr     */
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

	str = ft_memalloc(1);
	if (BUFF_SIZE < 1 || str == NULL)
		return (0);
	while ((i = read(fd, cbuffer, BUFF_SIZE)) > 0)
	{
		if ((str = ft_memalloc(i + 1)) == NULL)
			return (0);
		str = ft_strncpy(str, cbuffer, i);
		break ;
	}
	return (str);
}

void	doclnup(char **tmp, char **g_bread, int *i)
{
	(*tmp) = NULL;
	free(*tmp);
	(*g_bread) = NULL;
	free((*g_bread));
	(*i) = 0;
	free(i);
}

char	*ft_strjoin_patched(char *s1, char *s2)
{
	int		x;
	char	*sx;

	x = ft_strlen(s1) + ft_strlen(s2) + 1;
	sx = ft_memalloc(x);
	x = 0;
	while (s1[x] != '\0')
	{
		sx[x] = s1[x];
		x++;
	}
	while (s2[x - ft_strlen(s1)] != '\0')
	{
		sx[x] = s2[x - ft_strlen(s1)];
		x++;
	}
	sx[x] = '\0';
	return (sx);
}

int	get_next_line(const int fd, char **line)
{
	static char		*g_bread = "";
	char			*tmp;
	int				i;
	static int		istop = 0;

	if (istop == 1)
		return (0);

	i = ft_finditem(g_bread, '\n');
	if (i >= 0)
	{
		if (i == 0)
			(*line) = ft_memalloc(1);
		else
			(*line) = ft_strdup(ft_strsplit(g_bread, '\n')[0]);
		g_bread = ft_strsub(g_bread, i + 1, (ft_strlen(g_bread) - i) - 1);
		return (1);
	}
	else
	{
		while (1)
		{
			tmp = ft_readfile_once(fd);
			if (tmp == 0)
				return (-1);
			g_bread = ft_strjoin_patched(g_bread, tmp);
			i = ft_finditem(g_bread, '\n');
			if (i >= 0)
			{
				if (i == 0)
					(*line) = ft_memalloc(1);
				else
					(*line) = ft_strdup(ft_strsplit(g_bread, '\n')[0]);
				g_bread = ft_strsub(g_bread, i + 1, (ft_strlen(g_bread) - i) - 1);
				return (1);
			}
			else if (tmp[0] == '\0')
				(*line) = ft_strsub(g_bread, 1, (ft_strlen(g_bread) - 1));


			if (tmp[0] == '\0')
			{
				istop = 1;
				return (1);
			}
		}
	}
	doclnup(&tmp, &g_bread, &i);
	return (-1);
}
