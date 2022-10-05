/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:33:19 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/08/01 12:36:40 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../../libft/libft.h"
# include "../../libft/get_next_line.h"
# include "../../mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define UP      13
# define DOWN    1
# define LEFT    0
# define RIGHT   2
# define ESC     53
# define IMG_PXL 50
# define WND_NAME "so_long"

typedef struct s_enemy
{
	int	**array;
	int	nbr;
	int	pos;
}t_enemy;

typedef struct s_player
{
	int	y;
	int	x;
}t_player;

typedef struct s_img
{
	void	*empty;
	void	*collectible;
	void	*wall;
	void	*exit;
	void	*player_left1;
	void	*player_right1;
	void	*player_up1;
	void	*player_down1;
	void	*player_left2;
	void	*player_right2;
	void	*player_up2;
	void	*player_down2;
	void	*enemy;
	void	*enemy2;

}t_img;

typedef struct s_map
{
	int			fd;
	char		**array;
	char		**copy;
	char		*filename;
	int			y;
	int			x;
	int			e;
	int			c;
	int			c_check;
	int			e_check;
	int			p;
	int			z;
	int			action;
	int			moves;
	int			exit;
	void		*mlx;
	void		*wnd;
	t_img		img;
	t_player	player;
	t_enemy		enemy;

}t_map;

void	map_checker(t_map *map);
void	check_valid_path(t_map *map);
void	map_array(t_map *mapper);
void	file_to_image(t_map *mapper);
void	file_to_image_player(t_map *map);
void	map_printer(t_map *mapper);
int		key_hook(int keycode, t_map *map);

void	error_array(void);
void	error_filename(void);
void	error_wall(t_map *map);
void	error_openfile(void);
void	error_size(t_map *map);
void	error_map_elements(t_map *map);
void	error_empty_line(void);
void	error_malloc(void);
int		ft_free(char **ret, int i);
void	ft_exit_free(char *str);
int		ft_free_array(char **ret, int max);

void	scan_player(t_map *map);

void	scan_monster(t_map *map);

void	move_up(t_map *map);
void	move_left(t_map *map);
void	move_down(t_map *map);
void	move_right(t_map *map);

int		monster_hook(t_map *map);

void	print_counter(t_map *map);

void	map_initializer(t_map *map);

int		count_monster(t_map *map);
void	alloc_monster(t_map *map);
void	scan_monster(t_map *map);

void	scan_monster(t_map *map);
void	scan_monster(t_map *map);

void	move_up_m(t_map *map, int m);
void	move_left_m(t_map *map, int m);
void	move_down_m(t_map *map, int m);
void	move_right_m(t_map *map, int m);

int		move_monster(t_map *map);

void	print_movements(t_map *map);

void	ft_win(t_map *map);
void	ft_lose(t_map *map);
int		ft_close(t_map *map);

void	print_wall(t_map *map);

void	move_animation_right(t_map *map, int x, int y);
void	move_animation_left(t_map *map, int x, int y);
void	move_animation_down(t_map *map, int x, int y);
void	move_animation_up(t_map *map, int x, int y);

#endif