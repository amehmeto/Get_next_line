/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 07:12:06 by amehmeto          #+#    #+#             */
/*   Updated: 2017/05/04 19:25:11 by amehmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*tmp_builder(struct s_struct o, char buffer[BUFF_SIZE + 1],
		char *excess)
{
	if (o.tmp2)
		o.tmp = ft_strjoin(o.tmp2, buffer);
	else if (excess)
		o.tmp = ft_strjoin(excess, buffer);
	else
		o.tmp = ft_strdup(buffer);
	return (o.tmp);
}

static size_t	eol_snitch(struct s_struct *o)
{
	o->i = 0;
	while (o->tmp[o->i] && o->tmp[o->i] != '\n')
		o->i++;
	if (o->tmp[o->i] == '\n')
		o->eol = o->i + 1;
	return (o->i);
}

static char		*excess_storer(char **line, struct s_struct o, char *excess)
{
	o.eol--;
	*line = (o.tmp2) ? o.tmp2 : ft_strdup("\0");
	excess = ft_strsub(o.tmp, (unsigned)o.eol + 1, ft_strlen(o.tmp) - o.eol);
	free(o.tmp);
	if (!ft_strlen(excess))
	{
		free(excess);
		excess = NULL;
	}
	return (excess);
}

static int		after_loop(struct s_struct o, char **line)
{
	if (!o.eol && !o.ret && o.tmp2)
	{
		*line = o.tmp2;
		o.tmp2 = NULL;
		return (1);
	}
	if (!o.ret)
		*line = NULL;
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char				buffer[BUFF_SIZE + 1];
	static char			*excess;
	struct s_struct		o;

	ft_bzero((void *)&o, sizeof(o));
	if (fd < 0 || line == NULL)
		return (-1);
	while ((o.ret = read(fd, buffer, BUFF_SIZE)) || excess)
	{
		if (o.ret == -1)
			return (-1);
		buffer[o.ret] = '\0';
		free(o.tmp);
		o.tmp = tmp_builder(o, buffer, excess);
		o.i = eol_snitch(&o);
		free(o.tmp2);
		o.tmp2 = (o.i) ? ft_strsub(o.tmp, 0, o.i) : NULL;
		if (o.eol)
		{
			excess = excess_storer(line, o, excess);
			return (1);
		}
		excess = NULL;
	}
	return (after_loop(o, line));
}
