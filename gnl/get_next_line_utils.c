/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:29:44 by aamzil            #+#    #+#             */
/*   Updated: 2019/10/30 14:43:52 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*my_realloc(char *dst, char *src, int len)
{
	int		malloc_len;
	char	*tmp;
	int		i;
	int		j;

	j = -1;
	i = -1;
	malloc_len = (has_nl(src, 0) < len) ? has_nl(src, 0) : len;
	malloc_len += has_nl(dst, 0);
	if (!(tmp = (char*)malloc(malloc_len + 1)))
		return (0);
	while (dst && dst[++i])
		tmp[i] = dst[i];
	i = (dst) ? i : 0;
	while (src && src[++j] && j < len)
		tmp[i++] = src[j];
	tmp[i] = '\0';
	if (dst && len)
		dst = my_free(dst, NULL);
	return (tmp);
}

char	*my_free(char *buf, char *rest)
{
	if (buf)
	{
		free(buf);
		buf = NULL;
	}
	if (rest)
	{
		free(rest);
		rest = NULL;
	}
	return (NULL);
}

int		has_nl(char *s, int new_line)
{
	int i;

	i = -1;
	if (!s && !new_line)
		return (0);
	else if (!s)
		return (-1);
	while (s[++i])
		if (s[i] == '\n' && new_line)
			return (i);
	return ((new_line) ? -1 : i);
}

char	*sdp(char *s1, char *right_s)
{
	int		lensrc;
	char	*ptr;
	int		i;

	i = -1;
	lensrc = has_nl(s1, 0);
	if (!(ptr = (char*)malloc(lensrc + 1)))
		return (0);
	while (s1[++i])
		ptr[i] = s1[i];
	ptr[i] = '\0';
	right_s = my_free(right_s, NULL);
	return (ptr);
}

char	*helper_fun(char **line, char *rest, char *buf)
{
	if (!((*line) = my_realloc(rest, "", 0)))
	{
		my_free(buf, rest);
		return (0);
	}
	return (*line);
}
