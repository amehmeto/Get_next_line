/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 07:26:37 by amehmeto          #+#    #+#             */
/*   Updated: 2017/04/28 02:55:07 by amehmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "srcs/libft.h"
# include <fcntl.h>
# include <stdio.h>
# define BUFF_SIZE 30

int		get_next_line(const int fd, char **line);

#endif
