/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitabde <aaitabde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:06:55 by aaitabde          #+#    #+#             */
/*   Updated: 2025/01/24 20:11:17 by aaitabde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_imgs(t_game *game_info)
{
	game_info->mlx_i.bg_img = mlx_xpm_file_to_image(game_info->mlx, "mandatory/assets/ground_assets/Grass.xpm", \
								&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	game_info->mlx_i.wi_img =  mlx_xpm_file_to_image(game_info->mlx, "mandatory/assets/ground_assets/Walls/InternalWall.xpm", \
								&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	game_info->mlx_i.e_img = mlx_xpm_file_to_image(game_info->mlx, "mandatory/assets/player_assets/Exit.xpm", \
								&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	game_info->mlx_i.tw_img = mlx_xpm_file_to_image(game_info->mlx, "mandatory/assets/ground_assets/Walls/TopWall.xpm", \
								&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	game_info->mlx_i.bw_img = mlx_xpm_file_to_image(game_info->mlx, "mandatory/assets/ground_assets/Walls/BottomWall.xpm", \
								&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	game_info->mlx_i.rw_img = mlx_xpm_file_to_image(game_info->mlx, "mandatory/assets/ground_assets/Walls/RightWall.xpm", \
								&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	game_info->mlx_i.lw_img = mlx_xpm_file_to_image(game_info->mlx, "mandatory/assets/ground_assets/Walls/LeftWall.xpm", \
								&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	game_info->mlx_i.trw_img = mlx_xpm_file_to_image(game_info->mlx, "mandatory/assets/ground_assets/Walls/WallTopRight.xpm", \
								&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	game_info->mlx_i.tlw_img = mlx_xpm_file_to_image(game_info->mlx, "mandatory/assets/ground_assets/Walls/WallTopLeft.xpm", \
								&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	game_info->mlx_i.brw_img = mlx_xpm_file_to_image(game_info->mlx, "mandatory/assets/ground_assets/walls/WallBottomRight.xpm", \
								&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	game_info->mlx_i.blw_img = mlx_xpm_file_to_image(game_info->mlx, "mandatory/assets/ground_assets/Walls/WallBottomLeft.xpm", \
								&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	game_info->mlx_i.c_img = mlx_xpm_file_to_image(game_info->mlx, "mandatory/assets/player_assets/Flag.xpm", \
								&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	game_info->mlx_i.p_img = mlx_xpm_file_to_image(game_info->mlx, "mandatory/assets/player_assets/Player.xpm", \
								&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
}

void	put_sides(t_game *game_info, int x, int y)
{
	if (x == 0 && y != 0 && y != game_info->map_i.height - 1)
		mlx_put_image_to_window(game_info->mlx, game_info->w_mlx, game_info->mlx_i.lw_img, x * 48, y * 48);
	else if (y == 0 && x == 0)
		mlx_put_image_to_window(game_info->mlx, game_info->w_mlx, game_info->mlx_i.tlw_img, x * 48, y * 48);
	else if (y == 0 && x != 0 && x != game_info->map_i.width - 1)
		mlx_put_image_to_window(game_info->mlx, game_info->w_mlx, game_info->mlx_i.tw_img, x * 48, y * 48);
	else if (y == game_info->map_i.height - 1 && x == 0)
		mlx_put_image_to_window(game_info->mlx, game_info->w_mlx, game_info->mlx_i.blw_img, x * 48, y * 48);
	else if (x == game_info->map_i.width - 1 && y == 0)
		mlx_put_image_to_window(game_info->mlx, game_info->w_mlx, game_info->mlx_i.trw_img, x * 48, y * 48);
	else if (y == game_info->map_i.height - 1 && x != 0 && x != game_info->map_i.width - 1)
		mlx_put_image_to_window(game_info->mlx, game_info->w_mlx, game_info->mlx_i.bw_img, x * 48, y * 48);
	else if (x == game_info->map_i.width - 1 && y != 0 && y != game_info->map_i.height - 1)
		mlx_put_image_to_window(game_info->mlx, game_info->w_mlx, game_info->mlx_i.rw_img, x * 48, y * 48);
	else if (y == game_info->map_i.height - 1 && x == game_info->map_i.width - 1)
		mlx_put_image_to_window(game_info->mlx, game_info->w_mlx, game_info->mlx_i.brw_img, x * 48, y * 48);
}

void	put_to_window(t_game *game_info, int y, int x)
{
	char to_put;

	to_put = game_info->map_i.map[y][x];
	if (to_put == '1' && x != 0 && y != 0 && y != game_info->map_i.height - 1 \
		&& x != game_info->map_i.width - 1)
		mlx_put_image_to_window(game_info->mlx, game_info->w_mlx, game_info->mlx_i.wi_img, x * 48, y * 48);
	if (to_put == '1')
		put_sides(game_info, x, y);
	if (to_put == 'C')
		mlx_put_image_to_window(game_info->mlx, game_info->w_mlx, game_info->mlx_i.c_img, x * 48, y * 48);
	if (to_put == 'P')
		mlx_put_image_to_window(game_info->mlx, game_info->w_mlx, game_info->mlx_i.p_img, x * 48, y * 48);
	if (to_put == 'E')
		mlx_put_image_to_window(game_info->mlx, game_info->w_mlx, game_info->mlx_i.e_img, x * 48, y * 48);
}

void	prep_map(t_game *game_info)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y <= game_info->map_i.height)
	{
		while (x <= game_info->map_i.width)
		{
			mlx_put_image_to_window(game_info->mlx, game_info->w_mlx, game_info->mlx_i.bg_img, x * 48, y * 48);
			x++;
		}
		x = 0;
		y++;
	}
}

void	init_map(t_game *game_info)
{
	int x;
	int y;

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