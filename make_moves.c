/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitabde <aaitabde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:41:18 by aaitabde          #+#    #+#             */
/*   Updated: 2025/01/25 11:05:18 by aaitabde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	check_advancement(t_game *game_info, int y, int x)
// {
// 	if (game_info->map_i.map[game_info->map_i.py + y][game_info->map_i.px + x] != 'E')
// 	{
// 		if ();
// 	}
// }

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t	i;

	i = 0;
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 0 && n <= 9)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}


void	make_move(t_game *game_info, int y, int x, int *count)
{
	// check_advancement(game_info, y, x);
	if (game_info->map_i.map[game_info->map_i.py + y][game_info->map_i.px + x] != '1')
	{
		game_info->map_i.map[game_info->map_i.py][game_info->map_i.px] = '0';
		game_info->map_i.map[game_info->map_i.py + y][game_info->map_i.px + x] = 'P';
		mlx_put_image_to_window(game_info->mlx, game_info->w_mlx, game_info->mlx_i.bg_img, (game_info->map_i.px + x) * 48, (game_info->map_i.py + y) * 48);
		mlx_put_image_to_window(game_info->mlx, game_info->w_mlx, game_info->mlx_i.p_img, (game_info->map_i.px + x) * 48, (game_info->map_i.py + y) * 48);
		mlx_put_image_to_window(game_info->mlx, game_info->w_mlx, game_info->mlx_i.bg_img, game_info->map_i.px * 48, game_info->map_i.py * 48);
		game_info->map_i.px += x;
		game_info->map_i.py += y;
		(*count)++;
		write(1, "Moves: ", 7);
		ft_putnbr_fd(*count, 1);
		write(1, "\n", 1);
	}
}