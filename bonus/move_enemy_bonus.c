/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitabde <aaitabde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:55:10 by aaitabde          #+#    #+#             */
/*   Updated: 2025/01/31 15:26:22 by aaitabde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_it(t_game *game_info, int y, int x)
{
	int i;
	i = 0;
	if (game_info->map_i.map[game_info->map_i.hy + y][game_info->map_i.hx + x] == 'H')
		return ;
	game_info->map_i.map[game_info->map_i.hy + y][game_info->map_i.hx + x] = 'H';
	game_info->map_i.map[game_info->map_i.hy][game_info->map_i.hx] = '0';
	put_image(game_info, game_info->mlx_i.h_img, game_info->map_i.hx + x, game_info->map_i.hy + y);
	put_image(game_info, game_info->mlx_i.bg_img, game_info->map_i.hx, game_info->map_i.hy);
	if (game_info->map_i.hy == game_info->map_i.py \
		&& game_info->map_i.hx == game_info->map_i.px)
	{
		while (i < game_info->map_i.height)
			free(game_info->map_i.map[i++]);
		free(game_info->map_i.map);
		destroy_mlx(game_info);
		write(1, "Hisoka you bastard!\a\n", 22);
		exit(1);
	}
}

void	get_next_enemy(t_game *game_info, int h)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	while (y < game_info->map_i.height)
	{
		while (x < game_info->map_i.width)
		{
			if (game_info->map_i.map[y][x] == 'H')
			{
				printf("h == %d\n", game_info->map_i.h);
				if (h < game_info->map_i.h)
					h++;
				else
					break;
			}
			x++;
		}
		if (game_info->map_i.map[y][x] == 'H')
				break;
		x = 0;
		y++;
	}
	game_info->map_i.hx = x;
	game_info->map_i.hy = y;
}
void	attack(t_game *game_info)
{
	int h;
	static int frame;
	if (frame != 4600)
	{
		frame++;
		return ;
	}
	h = game_info->map_i.h;
	while (h)
	{
		get_next_enemy(game_info, h);
		 if ((game_info->map_i.map[game_info->map_i.hy][game_info->map_i.hx + 1] == '0' || \
		game_info->map_i.map[game_info->map_i.hy][game_info->map_i.hx + 1] == 'P') && (game_info->map_i.map[game_info->map_i.hy][game_info->map_i.hx - 1] != 'P'))
			move_it(game_info, 0 ,1);
		else if ((game_info->map_i.map[game_info->map_i.hy][game_info->map_i.hx - 1] == '0' || \
		game_info->map_i.map[game_info->map_i.hy][game_info->map_i.hx - 1] == 'P'))
			move_it(game_info, 0 ,-1);
		h--;
	}
	printf("-----------------------------------\n");
	// printf("hx == %d\n", game_info->map_i.hx);
	printf("hy == %d\n", game_info->map_i.hy);
	printf("-----------------------------------\n");
	frame = 0;
}

int	move_enemy(t_game *game_info)
{
	attack(game_info);
	return (0);
}
