/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitabde <aaitabde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:59:36 by aaitabde          #+#    #+#             */
/*   Updated: 2025/02/03 14:59:37 by aaitabde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	norm_func_move(t_game *game_info, int y, int x)
{
	int	px;
	int	py;

	px = game_info->map_i.px;
	py = game_info->map_i.py;
	if (px == game_info->map_i.ex && py == game_info->map_i.ey)
	{
		game_info->map_i.map[py][px] = 'E';
		game_info->map_i.map[py + y][px + x] = 'P';
		put_image(game_info, game_info->mlx_i.bg_img, px + x, py + y);
		put_image(game_info, game_info->mlx_i.p_img, px + x, py + y);
		put_image(game_info, game_info->mlx_i.bg_img, px, py);
		put_image(game_info, game_info->mlx_i.e_img, px, py);
	}
	else
	{
		game_info->map_i.map[py][px] = '0';
		game_info->map_i.map[py + y][px + x] = 'P';
		put_image(game_info, game_info->mlx_i.bg_img, px + x, py + y);
		put_image(game_info, game_info->mlx_i.p_img, px + x, py + y);
		put_image(game_info, game_info->mlx_i.bg_img, px, py);
	}
}
