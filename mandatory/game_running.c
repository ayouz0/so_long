/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_running.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitabde <aaitabde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:39:58 by aaitabde          #+#    #+#             */
/*   Updated: 2025/01/27 23:39:43 by aaitabde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_image(t_game *game_info, void *img)
{
	if (img)
		mlx_destroy_image(game_info->mlx, img);
}

void	destroy_mlx(t_game *game_info)
{
	destroy_image(game_info, game_info->mlx_i.p_img);
	destroy_image(game_info, game_info->mlx_i.d_img);
	destroy_image(game_info, game_info->mlx_i.bg_img);
	destroy_image(game_info, game_info->mlx_i.c_img);
	destroy_image(game_info, game_info->mlx_i.e_img);
	destroy_image(game_info, game_info->mlx_i.wi_img);
	destroy_image(game_info, game_info->mlx_i.trw_img);
	destroy_image(game_info, game_info->mlx_i.tlw_img);
	destroy_image(game_info, game_info->mlx_i.blw_img);
	destroy_image(game_info, game_info->mlx_i.brw_img);
	destroy_image(game_info, game_info->mlx_i.rw_img);
	destroy_image(game_info, game_info->mlx_i.lw_img);
	destroy_image(game_info, game_info->mlx_i.tw_img);
	destroy_image(game_info, game_info->mlx_i.bw_img);
	mlx_clear_window(game_info->mlx, game_info->w_mlx);
	mlx_destroy_window(game_info->mlx, game_info->w_mlx);
}

int	handle_keypress(int key, t_game	*game_info)
{
	static int	count;

	if (key == MOVE_UP)
		make_move(game_info, -1, 0, &count);
	else if (key == MOVE_DOWN)
		make_move(game_info, 1, 0, &count);
	else if (key == MOVE_LEFT)
		make_move(game_info, 0, -1, &count);
	else if (key == MOVE_RIGHT)
		make_move(game_info, 0, 1, &count);
	else if (key == ESC_KEY)
	{
		destroy_mlx(game_info);
		free_game(game_info);
		exit (0);
	}
	return (0);
}

int	exit_game(t_game *game_info)
{
	free_game(game_info);
	exit(1);
	return (0);
}

void	let_us_play(t_game *game_info)
{
	mlx_hook(game_info->w_mlx, 2, 0, handle_keypress, game_info);
	mlx_hook(game_info->w_mlx, 17, 0, exit_game, game_info);
	mlx_loop(game_info->mlx);
	mlx_destroy_window(game_info->mlx, game_info->w_mlx);
}
