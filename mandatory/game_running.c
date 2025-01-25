/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_running.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitabde <aaitabde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:39:58 by aaitabde          #+#    #+#             */
/*   Updated: 2025/01/24 20:13:55 by aaitabde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int key, t_game	*game_info)
{
	static int	count;

	if (key == MOVE_UP)
		make_move(game_info, -1, 0,&count);
	else if (key == MOVE_DOWN)
		make_move(game_info, 1, 0, &count);
	else if (key == MOVE_LEFT)
		make_move(game_info, 0, -1,&count);
	else if (key == MOVE_RIGHT)
		make_move(game_info, 0, 1, &count);
	else if (key == ESC_KEY)
	{
		free_game(game_info);
		exit(0);
	}
	return (0);
}

void	let_us_play(t_game *game_info)
{
	mlx_key_hook(game_info->w_mlx, handle_keypress, game_info);
	mlx_loop(game_info->mlx);
}
