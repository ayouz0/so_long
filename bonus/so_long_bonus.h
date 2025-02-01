/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitabde <aaitabde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:22:04 by aaitabde          #+#    #+#             */
/*   Updated: 2025/02/01 19:20:38 by aaitabde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line/get_next_line_bonus.h"

# ifndef TILE_SIZE
#  define TILE_SIZE 50
# endif

# ifndef MOVE_UP
#  define MOVE_UP 13
# endif

# ifndef MOVE_DOWN
#  define MOVE_DOWN 1
# endif

# ifndef MOVE_LEFT
#  define MOVE_LEFT 0
# endif

# ifndef MOVE_RIGHT
#  define MOVE_RIGHT 2
# endif

# ifndef ESC_KEY
#  define ESC_KEY 53
# endif

typedef struct s_mlx
{
	void	*p_img;
	void	*ps_img;
	void	*h_img;
	void	*tw_img;
	void	*bw_img;
	void	*rw_img;
	void	*lw_img;
	void	*trw_img;
	void	*tlw_img;
	void	*brw_img;
	void	*blw_img;
	void	*wi_img;
	void	*c_img;
	void	*bg_img;
	void	*e_img;
	void	*d_img;
	int		img_x;
	int		img_y;
}	t_mlx;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		px;
	int		py;
	int		ex;
	int		ey;
	int		p;
	int		e;
	int		h;
	int		hx;
	int		hy;
	int		c;
	int		other;
}	t_map;

typedef struct s_path_data
{
	short	e;
	int		c;
	int		x;
	int		y;
	char	**map;
}	t_path_data;

typedef struct s_game
{
	void	*mlx;
	void	*w_mlx;
	t_map	map_i;
	t_mlx	mlx_i;
}	t_game;

// General Utils
int		ft_strncmp(char *s1, char *s2, size_t n);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);

// Error Utils
void	print_error(char *str, int exit_stat);
void	print_errno(char *str);

// freeing utils
void	free_game(t_game	*game_info);
void	get_out(char *str, t_game *game_info);
void	destroy_mlx(t_game *game_info);
// Map Utils
void	get_map_info(char *map_name, t_game *game_info);
int		map_validity(t_game	*game_info);
void	add_element(t_game *game_info, int y, int x);
int		map_elements(t_game *game_info);
short	closed_rectangular_map(char **map);
void	let_us_play(t_game *game_info);
short	check_path(t_game *game_info);
char	**map_copier(t_game *game_info);
// game generating
void	make_move(t_game *game_info, int y, int x, int *count);
void	put_image(t_game *game_info, void *img, int x, int y);
void	init_imgs(t_game *game_info);
void	init_map(t_game *game_info);

//bonus
int		move_enemy(t_game *game_info);
void	get_next_enemy(t_game *game_info, int h);
void	norm_func_ifs(t_game *game_info, int direction);
void	replace(t_game *game_info, int y, int x, char repl);
#endif