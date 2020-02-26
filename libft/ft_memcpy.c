/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 21:16:13 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/19 14:58:44 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;
	size_t			i;
	size_t			len;

	len = 0;
	i = -1;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst == src)
		return (dst);
	pdst = (unsigned char*)dst;
	psrc = (unsigned char*)src;
	if (!ft_memcmp(dst, src, n))
		return (dst);
	if (!n)
		return (dst);
	while (++i < n)
		pdst[i] = psrc[i];
	return (dst);
}
