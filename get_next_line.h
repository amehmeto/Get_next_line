/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 07:26:37 by amehmeto          #+#    #+#             */
/*   Updated: 2017/05/03 18:49:28 by amehmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# define BUFF_SIZE 61

typedef struct	s_struct
{
	char		*tmp;
	char		*tmp2;
	size_t		eol;
	ssize_t		ret;
}				t_wesh;

int				get_next_line(const int fd, char **line);

#endif
