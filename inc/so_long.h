#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include "../minilibx_linux/mlx.h"
# include "../minilibx_linux/mlx_int.h"
//# include "../minilibx_mms_20200219/mlx.h"
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
# define M_CLK_L 1
# define K_ESC 65307

# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

# define tile_size 64
# define path_wall "./src/sprites_xpm/wall.xpm"
# define path_ground "./src/sprites_xpm/ground.xpm"
# define path_exit "./src/sprites_xpm/exit.xpm"
# define path_collectible "./src/sprites_xpm/collectible.xpm"
# define path_collected "./src/sprites_xpm/collected.xpm"

# define path_idle_down "./src/sprites_xpm/player_idle_down.xpm"
# define path_idle_up "./src/sprites_xpm/player_idle_up.xpm"
# define path_idle_right "./src/sprites_xpm/player_idle_right.xpm"
# define path_idle_left "./src/sprites_xpm/player_idle_left.xpm"

# define path_walk_down0 "./src/sprites_xpm/player_walk_down0.xpm"
# define path_walk_up0 "./src/sprites_xpm/player_walk_up0.xpm"
# define path_walk_right0 "./src/sprites_xpm/player_walk_right0.xpm"
# define path_walk_left0 "./src/sprites_xpm/player_walk_left0.xpm"

# define path_walk_down1 "./src/sprites_xpm/player_walk_down1.xpm"
# define path_walk_up1 "./src/sprites_xpm/player_walk_up1.xpm"
# define path_walk_right1 "./src/sprites_xpm/player_walk_right1.xpm"
# define path_walk_left1 "./src/sprites_xpm/player_walk_left1.xpm"

# define path_walk_down2 "./src/sprites_xpm/player_walk_down2.xpm"
# define path_walk_up2 "./src/sprites_xpm/player_walk_up2.xpm"
# define path_walk_right2 "./src/sprites_xpm/player_walk_right2.xpm"
# define path_walk_left2 "./src/sprites_xpm/player_walk_left2.xpm"

typedef struct	s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct	s_tiles
{
	t_img	*wall;
	t_img	*ground;
	t_img	*exit;
	t_img	*collectible;
	t_img	*collected;
	t_img	*idle_down;
	t_img	*idle_up;
	t_img	*idle_right;
	t_img	*idle_left;
	t_img	*walk_down0;
	t_img	*walk_up0;
	t_img	*walk_right0;
	t_img	*walk_left0;
	t_img	*walk_down1;
	t_img	*walk_up1;
	t_img	*walk_right1;
	t_img	*walk_left1;
	t_img	*walk_down2;
	t_img	*walk_up2;
	t_img	*walk_right2;
	t_img	*walk_left2;
}		t_tiles;

typedef struct s_data
{
	void	*mlx_ptr; // MLX pointer
	void	*win_ptr; // MLX window pointer
	//void	*textures[5]; // MLX image pointers (on the stack)
	char	**map; // Map pointer (contains map details - preferably kept on the stack)
	int		c_remaining;
	int		was_carot;
	t_tiles	tiles;
}			t_data;

char	**flood(char **tab, t_point size, t_point begin);
void    display_map(char **tab);
int 	is_map_invalid(char **tab, int nelem, size_t len);
int		initialize(char **tab, size_t len, int nelem);
void	ft_move(t_data *data, char move);
t_point	get_player_pos(char **tab,  t_point pos);
int		on_keypress(int keycode, t_data *data);
int		on_destroy(t_data *data);
#endif
