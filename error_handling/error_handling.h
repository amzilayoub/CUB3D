/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:39:08 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/25 11:13:32 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_H

# define ERROR_HANDLING_H

# include "../cub3d.h"

void	main_error_fun();
void	check_the_map();
void	set_error(char *msg);
void	check_the_resolution();
void	check_textures();
void	error_and_exit();
void	check_nb_arg(int nb);

#endif
