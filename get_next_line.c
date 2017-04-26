/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 07:12:06 by amehmeto          #+#    #+#             */
/*   Updated: 2017/04/26 21:43:58 by amehmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	static char		*excess, *tmp, *tmp2;
	size_t		eol, i;
	ssize_t		ret;

	tmp2 = NULL;
	tmp = NULL;
	eol = 0;
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		i = 0;
	//	printf("\n___________ ret = %zu ______________________\n\n", ret);
		buffer[ret] = 0;

		tmp2 = tmp;
		tmp = NULL;

	//	printf("\033[31mtmp\033[0m = %s||\n", tmp2);
	//	printf("\033[33mexcess\033[0m = %s||\n", excess);
	//	printf("buffer = %s||\n", buffer);



		while (buffer[i] && buffer[i] != '\n')
			i++;

		if (buffer[i] == '\n')
			eol = i;
		if (!tmp)
			if (!(tmp = (char *)malloc(sizeof(char) * i)))
				return (-1);
		tmp = ft_strncpy(tmp, buffer, i);
		if (tmp2)
			tmp = ft_strjoin(tmp2, tmp);
		if (excess)
		{
			tmp = ft_strjoin(excess, tmp);
			excess = NULL;
		}
	//	printf("\033[31mtmp\033[0m = %s||\n", tmp);



		if (eol)
		{
			*line = tmp;
	//		printf("\033[32mline\033[0m = %s\n", *line);
			if (!(excess = (char *)malloc(sizeof(char) * ((size_t)ret - eol))))
				return (-1);
			excess = ft_strsub(buffer, (unsigned)eol + 1, (size_t)ret - eol);
			excess[ret] = '\0';
	//		printf("\033[33mexcess\033[0m = %s||\n", excess);
			return (1);
		}
	}
	return (-1);
}
