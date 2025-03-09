#include "so_long.h"
#include "libft.h"

void	update_last_tile(t_data *data, t_point pos)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->tiles.ground, pos.y * TILE_SIZE, pos.x * TILE_SIZE);
	if (data->was_carot == 1 || data->map[pos.x][pos.y] == 'c')
	{
		data->was_carot = 0;
		data->map[pos.x][pos.y] = 'c';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.collected, pos.y * TILE_SIZE, pos.x * TILE_SIZE);
	}
	else if (data->was_exit == 1 || data->map[pos.x][pos.y] == 'E')
	{
		data->was_exit = 0;
		data->map[pos.x][pos.y] = 'E';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.exit, pos.y * TILE_SIZE, pos.x * TILE_SIZE);
	}
	else
	{
		data->map[pos.x][pos.y] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.ground, pos.y * TILE_SIZE, pos.x * TILE_SIZE);
	}
}

void	update_new_tile(t_data *data, t_point pos)
{
	if (data->map[pos.x][pos.y] == 'C')
	{
		data->was_carot = 1;
		data->map[pos.x][pos.y] = 'c';
		data->c_remaining --;
	}
	if (data->was_carot == 1 || data->map[pos.x][pos.y] == 'c')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.collected, pos.y * TILE_SIZE, pos.x * TILE_SIZE);
	}
	else if (data->map[pos.x][pos.y] == 'E')
	{
		if (data->c_remaining == 0)
			on_destroy(data);
		else
		{
			data->was_exit = 1;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->tiles.exit, pos.y * TILE_SIZE, pos.x * TILE_SIZE);
		}
	}
}
