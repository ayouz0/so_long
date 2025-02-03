/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitabde <aaitabde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:06:55 by aaitabde          #+#    #+#             */
/*   Updated: 2025/02/03 14:03:33 by aaitabde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_sides(t_game *game_info, int x, int y)
{
	if (x == 0 && y != 0 && y != game_info->map_i.height - 1)
		put_image(game_info, game_info->mlx_i.lw_img, x, y);
	else if (y == 0 && x == 0)
		put_image(game_info, game_info->mlx_i.tlw_img, x, y);
	else if (y == 0 && x != 0 && x != game_info->map_i.width - 1)
		put_image(game_info, game_info->mlx_i.tw_img, x, y);
	else if (y == game_info->map_i.height - 1 && x == 0)
		put_image(game_info, game_info->mlx_i.blw_img, x, y);
	else if (x == game_info->map_i.width - 1 && y == 0)
		put_image(game_info, game_info->mlx_i.trw_img, x, y);
	else if (y == game_info->map_i.height - 1 && x != 0 && \
		x != game_info->map_i.width - 1)
		put_image(game_info, game_info->mlx_i.bw_img, x, y);
	else if (x == game_info->map_i.width - 1 && y != 0 && \
		y != game_info->map_i.height - 1)
		put_image(game_info, game_info->mlx_i.rw_img, x, y);
	else if (y == game_info->map_i.height - 1 && \
		x == game_info->map_i.width - 1)
		put_image(game_info, game_info->mlx_i.brw_img, x, y);
}

void	put_to_window(t_game *game_info, int y, int x)
{
	char	to_put;

	to_put = game_info->map_i.map[y][x];
	if (to_put == '1' && x != 0 && y != 0 && x != game_info->map_i.width - 1 \
	&& y != game_info->map_i.height - 1)
	{
		if (game_info->map_i.map[y - 1][x] != '1' || y == 1)
			put_image(game_info, game_info->mlx_i.d_img, x, y);
		else
			put_image(game_info, game_info->mlx_i.wi_img, x, y);
	}
	else if (to_put == '1')
		put_sides(game_info, x, y);
	else if (to_put == 'C')
		put_image(game_info, game_info->mlx_i.c_img, x, y);
	else if (to_put == 'P')
		put_image(game_info, game_info->mlx_i.p_img, x, y);
	else if (to_put == 'E')
		put_image(game_info, game_info->mlx_i.e_img, x, y);
	else if (to_put == 'H')
		put_image(game_info, game_info->mlx_i.h_img, x, y);
}

void	prep_map(t_game *game_info)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= game_info->map_i.height)
	{
		while (x <= game_info->map_i.width)
		{
			put_image(game_info, game_info->mlx_i.bg_img, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	init_map(t_game *game_info)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	prep_map(game_info);
	while (y < game_info->map_i.height)
	{
		while (game_info->map_i.map[y][x])
		{
			put_to_window(game_info, y, x);
			x++;
		}
		x = 0;
		y++;
	}
}
