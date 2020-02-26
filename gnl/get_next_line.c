/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:46:08 by aamzil            #+#    #+#             */
/*   Updated: 2019/10/30 14:43:56 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		free_buf(char *buf)
{
	buf = my_free(buf, NULL);
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	static char	*rest[1024];
	char		*buf;
	int			n;

	if (fd < 0 || BUFFER_SIZE < 0 || !line || !(buf = malloc(BUFFER_SIZE)))
		return (-1);
	while (1)
	{
		if (has_nl(rest[fd], 1) >= 0)
		{
			if (!((*line) = my_realloc(NULL, rest[fd], has_nl(rest[fd], 1))) ||
				!(rest[fd] = sdp(rest[fd] + has_nl(rest[fd], 1) + 1, rest[fd])))
				return (-1);
			my_free(buf, NULL);
			return (1);
		}
		if ((n = read(fd, buf, BUFFER_SIZE)) <= 0)
		{
			if (!((*line) = helper_fun(line, rest[fd], buf)))
				return (-1);
			return (!(rest[fd] = my_free(buf, rest[fd])) && (*line)[0] ? 0 : n);
		}
		if (!(rest[fd] = my_realloc(rest[fd], buf, n)))
			return (free_buf(buf));
	}
}
