/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 07:12:06 by amehmeto          #+#    #+#             */
/*   Updated: 2017/04/27 05:01:38 by amehmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char		*excess, *tmp, *tmp2;
	char			buffer[BUFF_SIZE + 1];
	size_t			eol, i;
	ssize_t			ret;

	tmp2 = NULL;
	tmp = NULL;
	eol = 0;
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		if (!ret)
			return (0);
		else
			printf("ret = %zd\n", ret);
/*		{
			printf("ret = %zu \t %d = EOF\n", ret, EOF);
			kill(getpid(), SIGKILL);
		}*/
		printf("\n___________ ret = %zu ______________________\n\n", ret);
		buffer[ret] = '\0';

		tmp2 = tmp;
		tmp = NULL;

		printf("\033[31mtmp2\033[0m = %s||\n", tmp2);
		printf("\033[33mexcess\033[0m = %s||\n", excess);
		printf("buffer = %s||\n", buffer);

		i = 0;
		while (buffer[i] && buffer[i] != '\n')
			i++;

		if (buffer[i] == '\n')
			eol = i + 1;
		if (!tmp)
			if (!(tmp = (char *)malloc(sizeof(char) * (i + 1))))
				return (-1);
		tmp = ft_strncpy(tmp, buffer, i);
		tmp[i] = '\0';
		if (tmp2)
			tmp = ft_strjoin(tmp2, tmp);
		if (excess)
		{
			tmp = ft_strjoin(excess, tmp);
			excess = NULL;
		}
		printf("\033[31mtmp\033[0m = %s||\n", tmp);



		if (eol)
		{
			eol--;
			*line = tmp;
			printf("\033[32mline\033[0m = %s\n", *line);
			excess = ft_strsub(buffer, (unsigned)eol + 1, (size_t)ret - eol);
			printf("\033[33mexcess\033[0m = %s||\n", excess);
			if (ret < BUFF_SIZE)
				return (0);
			else
				return (1);
		}
	}
	return (0);
}
