/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:14:36 by aamzil            #+#    #+#             */
/*   Updated: 2019/10/21 19:05:26 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
	{
		if (!(ptr = (char*)malloc(1)))
			return (0);
		ptr[0] = '\0';
		return (ptr);
	}
	if (ft_strlen(s) <= start + len)
		len = ft_strlen(s) - start;
	if (!(ptr = (char*)malloc(len + 1)))
		return (0);
	while (s[start] && i < len)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
