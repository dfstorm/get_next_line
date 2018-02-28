/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 10:50:01 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 23:34:48 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	*str;
	int		fd;
	int		i;
	int		x;

	str = NULL;
	x = 0;
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		close(fd);
		while ((i = get_next_line(fd, &str)) > 0)
		{
			ft_putstr("From main: ");
			ft_putstr(str);
			ft_putstr("\n");
			x++;
		}
		ft_putstr("\n Lines: ");
		ft_putnbr(x);
	}
	return (0);
}
