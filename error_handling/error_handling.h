/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:39:08 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/15 17:50:51 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_H

# define ERROR_HANDLING_H

# include "../cub3d.h"

void    main_error_fun();
void     check_the_map();
void    set_error(char *msg);
void    check_the_resolution();

#endif