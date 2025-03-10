#include "so_long.h"
#include "libft.h"

void	load_image(t_image *tile, char *path, void *mlx_ptr)
{
	int	img_width;
	int	img_height;

	tile->img = mlx_xpm_file_to_image(mlx_ptr, path, &img_width, &img_height);
	(tile->img)->width = img_width;
	(tile->img)->height = img_height;
	check_transparency(tile);
}

void	load_walk_frames(t_data *data)
{
	load_image(&data->tiles.walk_down0, PATH_WALK_DOWN0, data->mlx_ptr);
	load_image(&data->tiles.walk_left0, PATH_WALK_LEFT0, data->mlx_ptr);
	load_image(&data->tiles.walk_right0, PATH_WALK_RIGHT0, data->mlx_ptr);
	load_image(&data->tiles.walk_up0, PATH_WALK_UP0, data->mlx_ptr);
	load_image(&data->tiles.walk_down1, PATH_WALK_DOWN1, data->mlx_ptr);
	load_image(&data->tiles.walk_left1, PATH_WALK_LEFT1, data->mlx_ptr);
	load_image(&data->tiles.walk_right1, PATH_WALK_RIGHT1, data->mlx_ptr);
	load_image(&data->tiles.walk_up1, PATH_WALK_UP1, data->mlx_ptr);
	load_image(&data->tiles.walk_down2, PATH_WALK_DOWN2, data->mlx_ptr);
	load_image(&data->tiles.walk_left2, PATH_WALK_LEFT2, data->mlx_ptr);
	load_image(&data->tiles.walk_right2, PATH_WALK_RIGHT2, data->mlx_ptr);
	load_image(&data->tiles.walk_up2, PATH_WALK_UP2, data->mlx_ptr);
}

void	load_idle_frames(t_data *data)
{
	load_image(&data->tiles.idle_down, PATH_IDLE_DOWN, data->mlx_ptr);
	load_image(&data->tiles.idle_left, PATH_IDLE_LEFT, data->mlx_ptr);
	load_image(&data->tiles.idle_right, PATH_IDLE_RIGHT, data->mlx_ptr);
	load_image(&data->tiles.idle_up, PATH_IDLE_UP, data->mlx_ptr);
}

void	load_background(t_data *data)
{
	load_image(&data->tiles.wall, PATH_WALL, data->mlx_ptr);
	load_image(&data->tiles.ground, PATH_GROUND, data->mlx_ptr);
	load_image(&data->tiles.exit, PATH_EXIT, data->mlx_ptr);
	load_image(&data->tiles.collectible, PATH_COLLECTIBLE, data->mlx_ptr);
	load_image(&data->tiles.collected, PATH_COLLECTED, data->mlx_ptr);
}

void	load_images(t_data *data)
{
	load_background(data);
	load_idle_frames(data);
	load_walk_frames(data);
}
