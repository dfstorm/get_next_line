/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 10:50:01 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/27 17:12:34 by ggenois     ###    #+. /#+    ###.fr     */
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

	str = NULL;
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		
		get_next_line(fd, &str);
		ft_putstr(str);
		ft_putstr("\n");
		get_next_line(fd, &str);
		ft_putstr(str);ft_putstr("\n");
		get_next_line(fd, &str);
		ft_putstr(str);ft_putstr("\n");
		get_next_line(fd, &str);
		ft_putstr(str);ft_putstr("\n");
		get_next_line(fd, &str);
		ft_putstr(str);ft_putstr("\n");
	}
	ft_putstr("\n");
	return (0);
}
