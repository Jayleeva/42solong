#include "so_long.h"
#include "libft.h"

t_img	*to_image(t_img *tile, void *mlx_ptr, char *path)
{
	int	img_width;
	int	img_height;

	tile = mlx_xpm_file_to_image(mlx_ptr, path, &img_width, &img_height);
	(tile)->width = img_width;
	(tile)->height = img_height;
	return (tile);
}

void	load_walk_frames(t_data *data)
{
	data->tiles.walk_down0 = to_image(data->tiles.walk_down0,
			data->mlx_ptr, PATH_WALK_DOWN0);
	data->tiles.walk_left0 = to_image(data->tiles.walk_left0,
			data->mlx_ptr, PATH_WALK_LEFT0);
	data->tiles.walk_right0 = to_image(data->tiles.walk_right0,
			data->mlx_ptr, PATH_WALK_RIGHT0);
	data->tiles.walk_up0 = to_image(data->tiles.walk_up0,
			data->mlx_ptr, PATH_WALK_UP0);
	data->tiles.walk_down1 = to_image(data->tiles.walk_down1,
			data->mlx_ptr, PATH_WALK_DOWN1);
	data->tiles.walk_left1 = to_image(data->tiles.walk_left1,
			data->mlx_ptr, PATH_WALK_LEFT1);
	data->tiles.walk_right1 = to_image(data->tiles.walk_right1,
			data->mlx_ptr, PATH_WALK_RIGHT1);
	data->tiles.walk_up1 = to_image(data->tiles.walk_up1,
			data->mlx_ptr, PATH_WALK_UP1);
	data->tiles.walk_down2 = to_image(data->tiles.walk_down2,
			data->mlx_ptr, PATH_WALK_DOWN2);
	data->tiles.walk_left2 = to_image(data->tiles.walk_left2,
			data->mlx_ptr, PATH_WALK_LEFT2);
	data->tiles.walk_right2 = to_image(data->tiles.walk_right2,
			data->mlx_ptr, PATH_WALK_RIGHT2);
	data->tiles.walk_up2 = to_image(data->tiles.walk_up2,
			data->mlx_ptr, PATH_WALK_UP2);
}

void	load_idle_frames(t_data *data)
{
	data->tiles.idle_down = to_image(data->tiles.idle_down,
			data->mlx_ptr, PATH_IDLE_DOWN);
	data->tiles.idle_left = to_image(data->tiles.idle_left,
			data->mlx_ptr, PATH_IDLE_LEFT);
	data->tiles.idle_right = to_image(data->tiles.idle_right,
			data->mlx_ptr, PATH_IDLE_RIGHT);
	data->tiles.idle_up = to_image(data->tiles.idle_up,
			data->mlx_ptr, PATH_IDLE_UP);
}

void	load_background(t_data *data)
{
	data->tiles.wall = to_image(data->tiles.wall,
			data->mlx_ptr, PATH_WALL);
	data->tiles.ground = to_image(data->tiles.ground,
			data->mlx_ptr, PATH_GROUND);
	data->tiles.exit = to_image(data->tiles.exit,
			data->mlx_ptr, PATH_EXIT);
	data->tiles.collectible = to_image(data->tiles.collectible,
			data->mlx_ptr, PATH_COLLECTIBLE);
	data->tiles.collected = to_image(data->tiles.collected,
			data->mlx_ptr, PATH_COLLECTED);
}

void	load_images(t_data *data)
{
	load_background(data);
	load_idle_frames(data);
	load_walk_frames(data);
}
