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

int		get_next_line(const int fd, char **line)
{
	static char		*g_b = NULL;
	char			*tmp;
	int				e;
	int				i;

	e = 1;
	if (g_b == NULL)
		g_b = ft_strnew(0);
	while ((i = ))
	tmp = ft_get_buffer_chunck(fd, &e);
	free(tmp);
	if((*line)) {}
	free(g_b);
	return (0);

}
