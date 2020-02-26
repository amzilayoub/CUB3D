/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:21:33 by aamzil            #+#    #+#             */
/*   Updated: 2019/10/21 20:03:46 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	c_w(char const *s, char c)
{
	int i;
	int count;

	i = -1;
	count = 1;
	if (!s[0])
		return (0);
	while (s[++i])
	{
		if (s[i] && s[i] == c && s[i + 1] != c)
			count++;
	}
	if (s[0] == c)
		count--;
	if (s[i - 1] == c)
		count--;
	return (count);
}

static char	**freemem(char **array)
{
	int i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
	return (NULL);
}

static int	l_n_s(const char *s, char c)
{
	int i;
	int len;

	i = -1;
	len = 0;
	while (s[++i] && s[i] != c)
		len++;
	return (len);
}

char		**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		is_char;
	int		j;

	if (!s || !(array = (char**)malloc(sizeof(char*) * (c_w(s, c) + 1))))
		return (NULL);
	j = -1;
	i = -1;
	is_char = 1;
	while (s[++i])
	{
		if (!is_char && s[i] == c && s[i + 1] != c && s[i + 1])
			is_char = 1;
		if (is_char && s[i] != c)
		{
			if (!(array[++j] = ft_substr(s + i, 0, l_n_s(s + i, c))))
				return (freemem(array));
			is_char = 0;
		}
	}
	array[++j] = 0;
	return (array);
}
