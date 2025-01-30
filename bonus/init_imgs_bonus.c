/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitabde <aaitabde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:59:18 by aaitabde          #+#    #+#             */
/*   Updated: 2025/01/28 11:43:39 by aaitabde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_files(t_game *game_info)
{
	int	i;

	i = 0;
	if (!game_info->mlx_i.rw_img || !game_info->mlx_i.bw_img || \
	!game_info->mlx_i.tw_img || !game_info->mlx_i.e_img || \
	!game_info->mlx_i.wi_img || !game_info->mlx_i.d_img || \
	!game_info->mlx_i.bg_img || !game_info->mlx_i.p_img || \
	!game_info->mlx_i.c_img ||!game_info->mlx_i.blw_img || \
	!game_info->mlx_i.brw_img || !game_info->mlx_i.tlw_img || \
	!game_info->mlx_i.trw_img || !game_info->mlx_i.lw_img || \
	!game_info->mlx_i.h_img)
	{
		destroy_mlx(game_info);
		print_error("Error : missing functional texture", 0);
		while (i < game_info->map_i.height)
			free(game_info->map_i.map[i++]);
		free(game_info->map_i.map);
		exit(0);
	}
}

void	second_init(t_game *game_info)
{
	game_info->mlx_i.lw_img = mlx_xpm_file_to_image(game_info->mlx, \
						"bonus/assets/ground/Walls/LeftWall.xpm", \
						&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	game_info->mlx_i.h_img = mlx_xpm_file_to_image(game_info->mlx, \
						"bonus/assets/enemy.xpm", \
						&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	game_info->mlx_i.trw_img = mlx_xpm_file_to_image(game_info->mlx, \
						"bonus/assets/ground/Walls/WallTopRight.xpm", \
						&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	game_info->mlx_i.tlw_img = mlx_xpm_file_to_image(game_info->mlx, \
						"bonus/assets/ground/Walls/WallTopLeft.xpm", \
						&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	game_info->mlx_i.brw_img = mlx_xpm_file_to_image(game_info->mlx, \
						"bonus/assets/ground/walls/WallBottomRight.xpm", \
						&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	game_info->mlx_i.blw_img = mlx_xpm_file_to_image(game_info->mlx, \
						"bonus/assets/ground/Walls/WallBottomLeft.xpm", \
						&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	game_info->mlx_i.c_img = mlx_xpm_file_to_image(game_info->mlx, \
						"bonus/assets/player/Flag.xpm", \
						&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	game_info->mlx_i.p_img = mlx_xpm_file_to_image(game_info->mlx, \
						"bonus/assets/player/Player.xpm", \
						&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
}

void	init_imgs(t_game *game_info)
{
	game_info->mlx_i.bg_img = mlx_xpm_file_to_image(game_info->mlx, \
						"bonus/assets/ground/Grass.xpm", \
						&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	game_info->mlx_i.d_img = mlx_xpm_file_to_image(game_info->mlx, \
						"bonus/assets/ground/Walls/3dBWall.xpm", \
						&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	game_info->mlx_i.wi_img = mlx_xpm_file_to_image(game_info->mlx, \
						"bonus/assets/ground/Walls/InternalWall.xpm", \
						&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	game_info->mlx_i.e_img = mlx_xpm_file_to_image(game_info->mlx, \
						"bonus/assets/player/Exit.xpm", \
						&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	game_info->mlx_i.tw_img = mlx_xpm_file_to_image(game_info->mlx, \
						"bonus/assets/ground/Walls/TopWall.xpm", \
						&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	game_info->mlx_i.bw_img = mlx_xpm_file_to_image(game_info->mlx, \
						"bonus/assets/ground/Walls/BottomWall.xpm", \
						&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	game_info->mlx_i.rw_img = mlx_xpm_file_to_image(game_info->mlx, \
						"bonus/assets/ground/Walls/RightWall.xpm", \
						&game_info->mlx_i.img_x, &game_info->mlx_i.img_y);
	second_init(game_info);
	check_files(game_info);
}

void	put_image(t_game *game_info, void *img, int x, int y)
{
	mlx_put_image_to_window(game_info->mlx, game_info->w_mlx, \
		img, x * 48, y * 48);
}
