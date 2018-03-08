/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 10:50:01 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/08 17:36:07 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	*s1;
	int		x;
	int		fd1;

	if (argc > 1)
	{
		fd1 = open(argv[1], O_RDONLY);
		while (1)
		{
			x = get_next_line(fd1, &s1);
			if (x < 1)
			{
				break ;
			}
			ft_putstr(s1);
			ft_putstr("\n");
			free(s1);
		}
	}
	return (0);
}
