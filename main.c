/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 10:50:01 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 16:28:05 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	**str;
	int		fd;
	int		rsp;
	int		i;

	str = NULL;
	i = 0;
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		rsp = get_next_line(fd, str);
		while ((rsp = get_next_line(fd, str)) == 1)
			printf("%s\n", str[i++]);
		if (rsp == 0)
			ft_putstr("\n did and done!");
		if (rep == -1)
			ft_putstr("\n shit happen");
	}
	ft_putstr("\n");
	return (0);
}
