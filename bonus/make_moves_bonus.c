/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitabde <aaitabde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:41:18 by aaitabde          #+#    #+#             */
/*   Updated: 2025/02/03 14:55:23 by aaitabde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	exit_handeling(t_game *game_info, int x, int y)
{
	int	px;
	int	py;

	px = game_info->map_i.px;
	py = game_info->map_i.py;
	if (!game_info->map_i.c)
	{
		put_image(game_info, game_info->mlx_i.p_img, (px + x), (py + y));
		put_image(game_info, game_info->mlx_i.bg_img, px, py);
		free_game(game_info);
		write(1, "YOU WIN ✅!\n", 13);
		exit(0);
	}
	else
	{
		game_info->map_i.map[py][px] = '0';
		game_info->map_i.map[py + y][px + x] = 'P';
		put_image(game_info, game_info->mlx_i.p_img, (px + x), (py + y));
		put_image(game_info, game_info->mlx_i.bg_img, px, py);
	}
	game_info->map_i.px += x;
	game_info->map_i.py += y;
}

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

int	check_advancement(t_game *game_info, int y, int x, int *count)
{
	int	px;
	int	py;

	px = game_info->map_i.px;
	py = game_info->map_i.py;
	if (game_info->map_i.map[py + y][px + x] == 'C')
	{
		norm_func_move(game_info, y, x);
		game_info->map_i.px += x;
		game_info->map_i.py += y;
		game_info->map_i.c--;
		update_moves(count, game_info);
		return (1);
	}
	else if (game_info->map_i.map[py + y][px + x] == 'E')
	{
		write(1, "\a", 1);
		(update_moves(count, game_info), exit_handeling(game_info, x, y));
		return (1);
	}
	return (0);
}

void	move_player(t_game *game_info, int x, int y)
{
	int	px;
	int	py;

	px = game_info->map_i.px;
	py = game_info->map_i.py;
	put_image(game_info, game_info->mlx_i.bg_img, (px + x), (py + y));
	put_image(game_info, game_info->mlx_i.p_img, (px + x), (py + y));
	put_image(game_info, game_info->mlx_i.bg_img, px, py);
}

void	make_move(t_game *game_info, int y, int x, int *count)
{
	int	px;
	int	py;

	px = game_info->map_i.px;
	py = game_info->map_i.py;
	if (check_advancement(game_info, y, x, count))
		return ;
	else if (game_info->map_i.map[py + y][px + x] != '1')
	{
		if (game_info->map_i.map[py + y][px + x] == 'H')
			(write(1, "Hisoka you bastard!\a\n", 22), exit(1), \
			destroy_mlx(game_info));
		move_player(game_info, x, y);
		if (px == game_info->map_i.ex && py == game_info->map_i.ey)
		{
			replace(game_info, y, x, 'E');
			put_image(game_info, game_info->mlx_i.e_img, px, py);
		}
		else
			replace(game_info, y, x, '0');
		game_info->map_i.px += x;
		game_info->map_i.py += y;
		update_moves(count, game_info);
	}
}
