/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitabde <aaitabde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:21:42 by aaitabde          #+#    #+#             */
/*   Updated: 2025/01/24 19:16:22 by aaitabde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_game	*game_info)
{  
	int i;

	i = 0;
	while (i < game_info->map_i.height)
		free(game_info->map_i.map[i++]);
	free(game_info->map_i.map);
	free(game_info);
}

int	escape(t_game *game_info)
{
	free_game(game_info);
	exit(0);
}

void	init_game(t_game *game_info)
{
	game_info->mlx = mlx_init();
	game_info->w_mlx = mlx_new_window(game_info->mlx, game_info->map_i.width * 48, game_info->map_i.height * 48, "so_long");
	init_imgs(game_info);
	init_map(game_info);
}


void get_out(char *str, t_game *game_info)
{
	free_game(game_info);
	print_error(str, 1);
}

void check_for_leaks(void){system("leaks so_long");}

int main(int ac, char **av)
{
	t_game	*game_info;

	atexit(check_for_leaks);
	if (ac != 2)
		return(0);
	if (!(ft_strlen(av[1]) > 4 && !(ft_strncmp(av[1] + (ft_strlen(av[1]) - 4), ".ber", 4))))
		print_error("Error: invalid map\n", 1);
	game_info = malloc(sizeof(t_game));
	if (!game_info)
		print_errno("Error ");
	get_map_info(av[1], game_info);
	game_info->map_i.width = map_validity(game_info);
	if (!game_info->map_i.width || !map_elements(game_info))
		get_out("Error: invalid map\n", game_info);
	init_game(game_info);
	let_us_play(game_info);
	// write(2, "fail\n",5);
	// int *()
	mlx_loop(game_info->mlx);
	// free_game(game_info);
}
