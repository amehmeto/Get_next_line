/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 19:49:00 by amehmeto          #+#    #+#             */
/*   Updated: 2017/04/29 05:28:10 by amehmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd, a;
	char	*line; 

/*	if (ac != 2)
	{
		ft_putstr("usage: ./gnl source_file\n");
		return (0);
	}*/
	(void)ac;
	(void)av;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_putstr("open error\n");

	a = 1;
	line = NULL;
	while (a > 0)
	{
		a = get_next_line(fd, &line);
		printf("%s###gnl = %d\n", line, a);
	}
	printf("%s###gnl = %d\n", line, get_next_line(fd, &line));
	printf("%s###gnl = %d\n", line, get_next_line(fd, &line));

	if (close(fd) == -1)
		ft_putstr("close error\n");
	return (0);
}
