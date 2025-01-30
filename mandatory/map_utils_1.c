/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitabde <aaitabde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:56:02 by aaitabde          #+#    #+#             */
/*   Updated: 2025/01/27 10:57:47 by aaitabde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_element(t_game *game_info, int y, int x)
{
	char	elem;

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

char	**map_copier(t_game *game_info)
{
	char	**dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dst = malloc(sizeof(char *) * game_info->map_i.height);
	if (!dst)
	{
		(free_game(game_info), destroy_mlx(game_info));
		print_errno("Error ");
	}
	while (j < game_info->map_i.height)
	{
		dst[j] = malloc(game_info->map_i.width + 1);
		while (i < game_info->map_i.width)
		{
			dst[j][i] = game_info->map_i.map[j][i];
			i++;
		}
		dst[j][i] = '\0';
		i = 0;
		j++;
	}
	return (dst);
}

void	validate_path(t_path_data *path, int y, int x)
{
	if (path->map[y][x] == '1' || path->map[y][x] == 's')
		return ;
	if (path->map[y][x] == 'C')
		path->c--;
	if (path->map[y][x] == 'E')
	{
		path->e = 1;
		return ;
	}
	path->map[y][x] = 's';
	validate_path(path, y, x + 1);
	validate_path(path, y, x - 1);
	validate_path(path, y + 1, x);
	validate_path(path, y - 1, x);
}

short	check_path(t_game *game_info)
{
	t_path_data	path_i;
	int			i;

	i = 0;
	path_i.c = game_info->map_i.c;
	path_i.e = 0;
	path_i.x = game_info->map_i.px;
	path_i.y = game_info->map_i.py;
	path_i.map = map_copier(game_info);
	validate_path(&path_i, path_i.y, path_i.x);
	while (i < game_info->map_i.height)
		free(path_i.map[i++]);
	free(path_i.map);
	return (!path_i.c && path_i.e);
}
