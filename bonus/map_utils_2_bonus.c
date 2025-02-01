/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitabde <aaitabde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:37:19 by aaitabde          #+#    #+#             */
/*   Updated: 2025/02/01 20:44:03 by aaitabde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_elems(t_game *game_info, int *i, int *j)
{
	game_info->map_i.c = 0;
	game_info->map_i.p = 0;
	game_info->map_i.e = 0;
	game_info->map_i.h = 0;
	game_info->map_i.other = 0;
	game_info->map_i.p = 0;
	*i = 0;
	*j = 1;
}

int	map_elements(t_game *game_info)
{
	int		i;
	char	**map;
	int		j;

	init_elems(game_info, &i, &j);
	map = game_info->map_i.map;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] != '0' && map[j][i] != '1')
				add_element(game_info, j, i);
			i++;
		}
		i = 0;
		j++;
	}
	if (game_info->map_i.other > 0 || game_info->map_i.c == 0 \
	|| game_info->map_i.p != 1 || \
	game_info->map_i.e != 1 || !closed_rectangular_map(map))
		return (0);
	return (1);
}

static int	check_for_ones(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	map_validity(t_game *game_info)
{
	int		i;
	int		j;
	char	**map;
	size_t	line_len;

	i = 0;
	j = 0;
	map = game_info->map_i.map;
	if (!check_for_ones(map[i]))
		return (0);
	line_len = ft_strlen(map[0]);
	while (map[i])
	{
		if (line_len != ft_strlen(map[i++]))
			return (0);
	}
	i--;
	if (!check_for_ones(map[i]))
		return (0);
	return (line_len);
}
