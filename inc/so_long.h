#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include "/workspace/42solong/minilibx_linux/mlx.h"
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

typedef struct	s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_data
{
	void	*mlx_ptr; // MLX pointer
	void	*win_ptr; // MLX window pointer
	void	*textures[5]; // MLX image pointers (on the stack)
	//t_map	*map; // Map pointer (contains map details - preferably kept on the stack)
}			t_data;

char	**flood(char **tab, t_point size, t_point begin);
void    display_map(char **tab);
int 	is_map_invalid(char **tab, int nelem, size_t len);
int		initialize(char **tab);
#endif