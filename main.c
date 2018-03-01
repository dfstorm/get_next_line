/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 10:50:01 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/01 19:07:54 by ggenois     ###    #+. /#+    ###.fr     */
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
		while ((i = get_next_line(fd, &str)) > 0)
		{
			ft_putstr("From main: ");
			ft_putstr(str);
			ft_putstr("\n");
			free(str);
			x++;
		}
		ft_putstr("\n Lines: ");
		ft_putnbr(x);
	}
	sleep(150);
	
	return (0);
}
