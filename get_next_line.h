/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 13:44:14 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 16:43:54 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _GNL_H
# define _GNL_H

# define BUFF_SIZE 32



int get_next_line(const int fd, char **line);

#endif