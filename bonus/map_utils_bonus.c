/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitabde <aaitabde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:53:46 by aaitabde          #+#    #+#             */
/*   Updated: 2025/02/01 17:00:08 by aaitabde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	read_map(t_game *game_info, int fd)
{
	int	i;

	i = 0;
	while (i < game_info->map_i.height)
	{
		game_info->map_i.map[i] = get_next_line(fd);
		if (game_info->map_i.map[i] \
		[ft_strlen(game_info->map_i.map[i]) - 1] == '\n')
			game_info->map_i.map[i] \
			[ft_strlen(game_info->map_i.map[i]) - 1] = '\0';
		i++;
	}
}

void	get_map_info(char *map_name, t_game *game_info)
{
	int	fd;
	int	i;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		print_errno("Error");
	game_info->map_i.height = get_height(fd);
	if (game_info->map_i.height == 0)
	{
		close(fd);
		print_error("Error: No Empty Maps Please!\n", 1);
	}
	fd = reset_offset(fd, map_name);
	game_info->map_i.map = \
	malloc(sizeof(char *) * (game_info->map_i.height + 1));
	if (!(game_info->map_i.map))
	{
		close(fd);
		print_errno("Error");
	}
	game_info->map_i.map[game_info->map_i.height] = NULL;
	i = 0;
	read_map(game_info, fd);
	close(fd);
}
