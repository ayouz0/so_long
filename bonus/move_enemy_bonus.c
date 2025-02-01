/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitabde <aaitabde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:55:10 by aaitabde          #+#    #+#             */
/*   Updated: 2025/02/01 19:19:23 by aaitabde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	attack(t_game *game_info)
{
	int			h;
	static int	direction;

	h = game_info->map_i.h;
	while (h)
	{
		get_next_enemy(game_info, h);
		if (!direction)
			direction = 1;
		if (game_info->map_i.map[game_info->map_i.hy] \
		[game_info->map_i.hx + 1] == '1')
			direction = -1;
		else if (game_info->map_i.map[game_info->map_i.hy] \
		[game_info->map_i.hx - 1] == '1')
			direction = 1;
		norm_func_ifs(game_info, direction);
		h--;
	}
}

void	re_render(t_game *game_info)
{
	char		*frames[7];
	static int	frame;

	frames[0] = "bonus/assets/player/Player.xpm";
	frames[1] = "bonus/assets/player/Player1.xpm";
	frames[2] = "bonus/assets/player/Player2.xpm";
	frames[3] = "bonus/assets/player/Player3.xpm";
	frames[4] = "bonus/assets/player/Player4.xpm";
	frames[5] = "bonus/assets/player/Player5.xpm";
	frames[6] = "bonus/assets/player/Player6.xpm";
	game_info->mlx_i.ps_img = mlx_xpm_file_to_image(game_info->mlx, \
	frames[frame], &game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	put_image(game_info, game_info->mlx_i.bg_img, game_info->map_i.px, \
	game_info->map_i.py);
	if (game_info->map_i.px == game_info->map_i.ex && game_info->map_i.py \
	== game_info->map_i.ey)
		put_image(game_info, game_info->mlx_i.e_img, game_info->map_i.px, \
	game_info->map_i.py);
	put_image(game_info, game_info->mlx_i.ps_img, game_info->map_i.px, \
	game_info->map_i.py);
	frame = frame +1;
	if (frame == 7)
		frame = 0;
}

int	move_enemy(t_game *game_info)
{
	static int	frame;
	static int	render_counter;

	if (render_counter == 0)
		re_render(game_info);
	render_counter = (render_counter + 1) % 1000;
	if (frame != 1600)
	{
		frame++;
		return (1);
	}
	attack(game_info);
	frame = 0;
	return (0);
}
