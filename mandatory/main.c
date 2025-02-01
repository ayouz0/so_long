/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitabde <aaitabde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:21:42 by aaitabde          #+#    #+#             */
/*   Updated: 2025/02/01 23:15:07 by aaitabde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_game	*game_info)
{
	int	i;

	i = 0;
	while (i < game_info->map_i.height)
		free(game_info->map_i.map[i++]);
	free(game_info->map_i.map);
	free(game_info);
}

void	init_game(t_game *game_info)
{
	game_info->mlx = mlx_init();
	game_info->w_mlx = mlx_new_window(game_info->mlx, \
	game_info->map_i.width * 48, game_info->map_i.height * 48, "so_long");
	init_imgs(game_info);
	init_map(game_info);
}

void	get_out(char *str, t_game *game_info)
{
	free_game(game_info);
	print_error(str, 1);
}

int	main(int ac, char **av)
{
	t_game	*game_info;

	if (ac != 2)
		print_error("Error\nusage : ./so_long \033[31mNAME\033[0m.ber\n", 1);
	if (!(ft_strlen(av[1]) > 4 && \
	!(ft_strncmp(av[1] + (ft_strlen(av[1]) - 4), ".ber", 4))))
		print_error("\033[31mError:\033[0m\ninvalid map name\n", 1);
	game_info = malloc(sizeof(t_game));
	if (!game_info)
		print_errno("\033[31mError:\033[0m");
	get_map_info(av[1], game_info);
	game_info->map_i.width = map_validity(game_info);
	if (!game_info->map_i.width || !map_elements(game_info) \
		|| game_info->map_i.height > 30)
		get_out("\033[31mError:\033[0m\ninvalid map\n", game_info);
	if (!check_path(game_info))
		get_out("\033[31mError:\033[0m\ninvalid path\n", game_info);
	init_game(game_info);
	let_us_play(game_info);
	exit(0);
}
