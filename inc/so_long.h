/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   so_long.h                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/10 16:42:29 by cyglardo       #+#    #+#                */
/*   Updated: 2025/03/10 16:42:30 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# define K_A 97
# define K_S 115
# define K_D 100
# define K_W 119
# define K_AR_L 65361
# define K_AR_R 65363
# define K_AR_U 65362
# define K_AR_D 65364
# define K_Q 113
# define K_ESC 65307

# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

# define PATH_WALL "./src/sprites_xpm/wall.xpm"
# define PATH_GROUND "./src/sprites_xpm/ground.xpm"
# define PATH_EXIT "./src/sprites_xpm/exit.xpm"
# define PATH_COLLECTIBLE "./src/sprites_xpm/collectible.xpm"
# define PATH_COLLECTED "./src/sprites_xpm/collected.xpm"

# define PATH_IDLE_DOWN "./src/sprites_xpm/player_idle_down.xpm"
# define PATH_IDLE_UP "./src/sprites_xpm/player_idle_up.xpm"
# define PATH_IDLE_RIGHT "./src/sprites_xpm/player_idle_right.xpm"
# define PATH_IDLE_LEFT "./src/sprites_xpm/player_idle_left.xpm"

# define PATH_WALK_DOWN0 "./src/sprites_xpm/player_walk_down0.xpm"
# define PATH_WALK_UP0 "./src/sprites_xpm/player_walk_up0.xpm"
# define PATH_WALK_RIGHT0 "./src/sprites_xpm/player_walk_right0.xpm"
# define PATH_WALK_LEFT0 "./src/sprites_xpm/player_walk_left0.xpm"

# define PATH_WALK_DOWN1 "./src/sprites_xpm/player_walk_down1.xpm"
# define PATH_WALK_UP1 "./src/sprites_xpm/player_walk_up1.xpm"
# define PATH_WALK_RIGHT1 "./src/sprites_xpm/player_walk_right1.xpm"
# define PATH_WALK_LEFT1 "./src/sprites_xpm/player_walk_left1.xpm"

# define PATH_WALK_DOWN2 "./src/sprites_xpm/player_walk_down2.xpm"
# define PATH_WALK_UP2 "./src/sprites_xpm/player_walk_up2.xpm"
# define PATH_WALK_RIGHT2 "./src/sprites_xpm/player_walk_right2.xpm"
# define PATH_WALK_LEFT2 "./src/sprites_xpm/player_walk_left2.xpm"

# define FLOOD_SET "0PCE"
# define MAP_SET "10PCE"

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_image
{
	t_img	*img;
}			t_image;

typedef struct s_tiles
{
	t_image	wall;
	t_image	ground;
	t_image	exit;
	t_image	collectible;
	t_image	collected;
	t_image	idle_down;
	t_image	idle_up;
	t_image	idle_right;
	t_image	idle_left;
	t_image	walk_down0;
	t_image	walk_up0;
	t_image	walk_right0;
	t_image	walk_left0;
	t_image	walk_down1;
	t_image	walk_up1;
	t_image	walk_right1;
	t_image	walk_left1;
	t_image	walk_down2;
	t_image	walk_up2;
	t_image	walk_right2;
	t_image	walk_left2;
}			t_tiles;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		c_remaining;
	int		was_carrot;
	int		was_exit;
	int		load_successful;
	t_tiles	tiles;
}			t_data;

char	**fill_map(int fd, char **tab);
void	free_tab_rev(char **tab, int i);
char	**flood(char **tab, t_point size, t_point begin);
int		is_everything_flooded(char **map);
int		is_everything_reachable(char **tab, int nelem, size_t len);
int		has_elem(char **tab, char c);
int		is_map_invalid(char **tab, int nelem, size_t len);
void	initialize(char **tab, size_t len, int nelem);
void	load_images(t_data *data);
void	update_last_tile(t_data *data, t_point pos);
void	update_new_tile(t_data *data, t_point pos);
void	ft_move(t_data *data, char move);
t_point	get_player_pos(char **tab, t_point pos);
void	destroy_images(t_data *data);
int		on_keypress(int keycode, t_data *data);
int		on_destroy(t_data *data);

#endif
