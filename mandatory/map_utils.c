/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitabde <aaitabde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:53:46 by aaitabde          #+#    #+#             */
/*   Updated: 2025/01/24 10:10:19 by aaitabde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	reset_offset(int fd, char *map_name)
{
	close(fd);
	return (open(map_name, O_RDONLY));
}

int	get_height(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (i);
}

void	get_map_info(char *map_name, t_game *game_info)
{
	int fd;
	int	i;

	fd  = open(map_name, O_RDONLY);
	if (fd == -1)
		print_errno("Error");
	game_info->map_i.height = get_height(fd);
	if (game_info->map_i.height == 0)
		print_error("Error: invalid Map", 1);
	fd = reset_offset(fd, map_name);
	game_info->map_i.map = malloc(sizeof(char *) * (game_info->map_i.height + 1));
	if (!(game_info->map_i.map))
		print_errno("Error");
	game_info->map_i.map[game_info->map_i.height] = NULL;
	i = 0;
	while (i < game_info->map_i.height)
	{
		game_info->map_i.map[i] = get_next_line(fd);
		if (game_info->map_i.map[i][ft_strlen(game_info->map_i.map[i]) - 1] == '\n')
			game_info->map_i.map[i][ft_strlen(game_info->map_i.map[i]) - 1] = '\0';
		i++;
	}
	close(fd);
}

int	map_elements(t_game *game_info)
{
	int		i;
	char	**map;
	int		j;

	(i = 0, j = 1);
	map = game_info->map_i.map;
	(game_info->map_i.c = 0, game_info->map_i.p = 0,game_info->map_i.e = 0 );
	(game_info->map_i.other = 0, game_info->map_i.p = 0);
	while (map[j])
	{
		while(map[j][i])
		{
			if (map[j][i] != '0' && map[j][i] != '1')
				add_element(game_info, j, i);
			i++;
		}
		i = 0;
		j++;
	}
	if (game_info->map_i.other > 0 || game_info->map_i.c == 0 || game_info->map_i.p != 1 || \
		game_info->map_i.e != 1|| !closed_rectangular_map(map))
			return (0);
	return (1);
}

int	map_validity(t_game *game_info)
{
	int		i;
	int		j;
	char **map;
	size_t line_len;

	(i = 0, j = 0, map = game_info->map_i.map);
	while (map[0][j] != '\0')
	{
		if (map[0][j] != '1')
			return (0);
		j++;
	}
	line_len = ft_strlen(map[0]);
	while (map[i])
	{
		if (line_len != ft_strlen(map[i++]))
			return (0);
	}
	(i--, j = 0);
	while (map[i][j])
	{
		if (map[i][j++] != '1')
			return (0);
	}
	return (line_len);
}
