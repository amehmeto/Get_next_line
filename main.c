/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 19:49:00 by amehmeto          #+#    #+#             */
/*   Updated: 2017/04/26 21:45:03 by amehmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*line; 

	if (ac != 2)
	{
		ft_putstr("usage: ./gnl source_file\n");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_putstr("open error\n");

	line = NULL;
	get_next_line(fd, &line);
	//printf("n# of char in line = %zu\n", ft_strlen(line));
	printf("%s\n", line);
	get_next_line(fd, &line);
	//printf("n# of char in line = %zu\n", ft_strlen(line));
	printf("%s", line);

	if (close(fd) == -1)
		ft_putstr("close error\n");
	return (0);
}
