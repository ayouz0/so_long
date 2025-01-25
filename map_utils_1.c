/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitabde <aaitabde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:56:02 by aaitabde          #+#    #+#             */
/*   Updated: 2025/01/24 10:04:13 by aaitabde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void add_element(t_game *game_info, int y, int x)
{
	char elem;

	elem = game_info->map_i.map[y][x];
	if (elem == 'E')
	{
		game_info->map_i.ex = x;
		game_info->map_i.ey = y;
		game_info->map_i.e++;
	}
	else if (elem == 'C')
		game_info->map_i.c++;
	else if (elem == 'P')
	{
		game_info->map_i.py = y;
		game_info->map_i.px = x;
		game_info->map_i.p++;
	}
	else
		game_info->map_i.other++;
}
short	closed_rectangular_map(char **map)
{
	int	start;
	int	end;
	int	j;

	start = 0;
	end = ft_strlen(map[0]) - 1;
	j = 0;
	while (map[j])
	{
		if (!(map[j][start] == '1' && map[j][end] == '1'))
			return (0);
		j++;
	}
	if (j > end)
		return (0);
	return (1);
}
