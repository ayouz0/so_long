/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitabde <aaitabde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:55:10 by aaitabde          #+#    #+#             */
/*   Updated: 2025/01/31 19:00:10 by aaitabde         ###   ########.fr       */
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
	game_info->map_i.hx += x;
	game_info->map_i.hy += y;
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
	static int direction;

	h = game_info->map_i.h;
	while (h)
	{
		get_next_enemy(game_info, h);
		if (!direction)
			direction = 1;
		if (game_info->map_i.map[game_info->map_i.hy][game_info->map_i.hx + 1] == '1')
			direction = -1;
		else if (game_info->map_i.map[game_info->map_i.hy][game_info->map_i.hx - 1] == '1')
			direction = 1;
		if ((game_info->map_i.map[game_info->map_i.hy][game_info->map_i.hx + 1] == '0' || \
		game_info->map_i.map[game_info->map_i.hy][game_info->map_i.hx + 1] == 'P') && direction == 1)
			move_it(game_info, 0, 1);
		else if ((game_info->map_i.map[game_info->map_i.hy][game_info->map_i.hx - 1] == '0' || \
		game_info->map_i.map[game_info->map_i.hy][game_info->map_i.hx - 1] == 'P') && direction == -1)
		{
			move_it(game_info, 0, -1);
			direction = -1;
		}
		h--;
	}
}


void re_render(t_game *game_info)
{
   	char *frames[7];
	static int frame;
	
	frames[0] = "bonus/assets/player/Player.xpm";
	frames[1] = "bonus/assets/player/Player1.xpm";
	frames[2] = "bonus/assets/player/Player2.xpm";
	frames[3] = "bonus/assets/player/Player3.xpm";
	frames[4] = "bonus/assets/player/Player4.xpm";
	frames[5] = "bonus/assets/player/Player5.xpm";
	frames[6] = "bonus/assets/player/Player6.xpm";
	
	game_info->mlx_i.ps_img = mlx_xpm_file_to_image(game_info->mlx,
													frames[frame],
													&game_info->mlx_i.img_x,
													&game_info->mlx_i.img_y);
	put_image(game_info, game_info->mlx_i.bg_img, game_info->map_i.px, game_info->map_i.py);
	put_image(game_info, game_info->mlx_i.ps_img, game_info->map_i.px, game_info->map_i.py);
	frame = frame +1;
	if (frame == 7)
		frame = 0;
}
int	move_enemy(t_game *game_info)
{
	static int frame = 0;
	static int render_counter = 0;

	if (render_counter == 0)
		re_render(game_info);

	render_counter = (render_counter + 1) % 1500;

	if (frame != 1600)
	{
		frame++;
		return (1);
	}
	attack(game_info);
	frame = 0;
	return (0);
}
