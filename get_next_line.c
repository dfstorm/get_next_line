/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 14:57:11 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/27 17:15:35 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int		ft_finditem(char *haystack, char item)
{
	int	i;

	i = -1;
	while (haystack[++i] != '\0')
		if (haystack[i] == item)
			return (i);
	return (0);
}

char	*ft_readfile_once(int fd)
{
	int		i;
	char	cbuffer[BUFF_SIZE];
	char	*str;

	if (BUFF_SIZE > 0)
		if ((str = ft_memalloc(BUFF_SIZE + 1)) == NULL)
			return (0);
	while ((i = read(fd, cbuffer, BUFF_SIZE)) > 0)
	{
		str = ft_strcpy(str, cbuffer);
		break ;
	}
	return (str);
}

int	get_next_line(const int fd, char **line)
{
	static int		g_ipos = 0;
	static t_data	g_data;
	char			*str;
	char			*tmp;
	int 			i;

	str = ft_memalloc(1);
	// 0- Init du tableau.
	if(g_ipos == 0)
	{
		g_data.str = ft_memalloc(1);
		g_ipos++;
	}


	while ((tmp = ft_readfile_once(fd)) != NULL)
	{
		g_data.str = ft_strjoin(g_data.str, tmp);
		i = ft_finditem(g_data.str, '\n');
		if(i != 0)
		{
			str = ft_memalloc(i + 1);
			str = ft_strsub(g_data.str, 0, i);
			
			ft_putstr(str);
			ft_putnbr(i);
			ft_putnbr(ft_strlen(g_data.str));
			str = ft_strsub(g_data.str, i, ft_strlen(g_data.str));
			ft_putstr("--");
			ft_putstr(str);
			ft_putstr("--");
			break ;
		}

	}

	(*line) = str;

	ft_putstr("\n=== gnl-end ===\n");
	
	return (1);
}
