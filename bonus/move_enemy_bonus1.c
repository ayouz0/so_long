/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitabde <aaitabde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:01:20 by aaitabde          #+#    #+#             */
/*   Updated: 2025/02/01 19:20:30 by aaitabde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	norm_func_mv(t_game *game_info, int y, int x)
{
	game_info->map_i.map[game_info->map_i.hy + y] \
	[game_info->map_i.hx + x] = 'H';
	game_info->map_i.map[game_info->map_i.hy] \
	[game_info->map_i.hx] = '0';
	put_image(game_info, game_info->mlx_i.h_img, \
	game_info->map_i.hx + x, game_info->map_i.hy + y);
	put_image(game_info, game_info->mlx_i.bg_img, \
	game_info->map_i.hx, game_info->map_i.hy);
	game_info->map_i.hx += x;
	game_info->map_i.hy += y;
}

void	move_it(t_game *game_info, int y, int x, int direction)
{
	int	i;

	i = 0;
	if (game_info->map_i.map[game_info->map_i.hy + y] \
	[game_info->map_i.hx + x] == 'H')
		return ;
	if (direction == 1)
		game_info->mlx_i.h_img = mlx_xpm_file_to_image(game_info->mlx, \
					"bonus/assets/enemy.xpm", &game_info->mlx_i.img_x, \
					&game_info->mlx_i.img_y);
	if (direction == -1)
		game_info->mlx_i.h_img = mlx_xpm_file_to_image(game_info->mlx, \
					"bonus/assets/enemyl.xpm", &game_info->mlx_i.img_x, \
					&game_info->mlx_i.img_y);
	norm_func_mv(game_info, y, x);
	if (game_info->map_i.hy == game_info->map_i.py \
	&& game_info->map_i.hx == game_info->map_i.px)
	{
		while (i < game_info->map_i.height)
			free(game_info->map_i.map[i++]);
		free(game_info->map_i.map);
		destroy_mlx(game_info);
		(write(1, "Hisoka you bastard!\a\n", 22), exit(1));
	}
}

void	get_next_enemy(t_game *game_info, int h)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game_info->map_i.height)
	{
		while (x < game_info->map_i.width)
		{
			if (game_info->map_i.map[y][x] == 'H')
			{
				if (h < game_info->map_i.h)
					h++;
				else
					break ;
			}
			x++;
		}
		if (game_info->map_i.map[y][x] == 'H')
			break ;
		x = 0;
		y++;
	}
	game_info->map_i.hx = x;
	game_info->map_i.hy = y;
}

void	norm_func_ifs(t_game *game_info, int direction)
{
	if ((game_info->map_i.map[game_info->map_i.hy] \
	[game_info->map_i.hx + 1] == '0' || \
	game_info->map_i.map[game_info->map_i.hy] \
	[game_info->map_i.hx + 1] == 'P') && direction == 1)
		move_it(game_info, 0, 1, direction);
	else if ((game_info->map_i.map[game_info->map_i.hy] \
	[game_info->map_i.hx - 1] == '0' || \
	game_info->map_i.map[game_info->map_i.hy] \
	[game_info->map_i.hx - 1] == 'P') && direction == -1)
	{
		move_it(game_info, 0, -1, direction);
		direction = -1;
	}
}

void	replace(t_game *game_info, int y, int x, char repl)
{
	int	px;
	int	py;

	px = game_info->map_i.px;
	py = game_info->map_i.py;
	game_info->map_i.map[py][px] = repl;
	game_info->map_i.map[py + y][px + x] = 'P';
}
