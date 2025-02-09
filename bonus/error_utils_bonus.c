/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitabde <aaitabde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:08:36 by aaitabde          #+#    #+#             */
/*   Updated: 2025/01/28 10:16:09 by aaitabde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_error(char *str, int exit_stat)
{
	write(2, str, ft_strlen(str));
	if (exit_stat)
		exit(1);
}

void	print_errno(char *str)
{
	perror(str);
	exit(1);
}
