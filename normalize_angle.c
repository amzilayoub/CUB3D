/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:57:05 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/25 11:28:11 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	normalize_angle(float angle)
{
	float degree_angle;

	degree_angle = (angle * 360) / (2 * M_PI);
	degree_angle = (int)degree_angle % (360);
	if (degree_angle < 0)
		degree_angle = degree_angle + (360);
	return (RAD(degree_angle));
}
