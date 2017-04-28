/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 07:12:06 by amehmeto          #+#    #+#             */
/*   Updated: 2017/04/28 03:02:09 by amehmeto         ###   ########.fr       */
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

	if (fd < 0 || line == NULL)
		return (-1);

	while ((ret = read(fd, buffer, BUFF_SIZE)) || excess)
	{
//		printf("\n_________________ ret = %zu ______________________\n\n", ret);
		buffer[ret] = '\0';

//		printf("\033[31mtmp2\033[0m = %s||\n", tmp2);
//		printf("\033[33mexcess\033[0m = %s||\n", excess);
//		printf("\nbuffer = %s||\n", buffer);


		if (tmp2)
			tmp = ft_strjoin(tmp2, buffer);
		else if (excess)
			tmp = ft_strjoin(excess, buffer);
		else
			tmp = ft_strdup(buffer);

//		printf("tmp = %s||\n\n", tmp);

		i = 0;
		while (tmp[i] && tmp[i] != '\n')
			i++;
		if (tmp[i] == '\n')
			eol = i + 1;
		
		tmp2 = (i) ? ft_strsub(tmp, 0, i) : NULL;

//		printf("\033[31mtmp2\033[0m = %s||\n", tmp2);



		if (eol)
		{
			eol--;
			*line = (tmp2) ? tmp2 : "\n";
//			printf("\033[32mline\033[0m = %s||\n\n", *line);
//			printf("tmp = %s||\n", tmp);

			excess = ft_strsub(tmp, (unsigned)eol + 1, ft_strlen(tmp) - eol);
			if (!ft_strlen(excess))
				excess = NULL;

//			printf("\033[33mexcess\033[0m = %s||\n", excess);
			if (ret < BUFF_SIZE && !excess)
				return (0);
			else
				return (1);
		}
	}
	if (ret == -1)
		return (-1);
	return (0);
}
