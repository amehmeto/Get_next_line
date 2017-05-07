/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 03:00:13 by amehmeto          #+#    #+#             */
/*   Updated: 2017/05/07 03:07:31 by amehmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	argc += 0;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	printf("ret = %d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	return (0);
}
