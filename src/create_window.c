#include "so_long.h"
#include "libft.h"

void	find_img(t_data *data, void **img, char c)
{
	if (c == '1')
		*img = data->tiles.wall;
	else if (c == '0')
		*img = data->tiles.ground;
	else if (c == 'E')
		*img = data->tiles.exit;
	else if (c == 'C')
		*img = data->tiles.collectible;
	else
		*img = data->tiles.idle_right;
}

void	create_map(t_data *data)
{
	int		x;
	int		y;
	void	*img;

	data->c_remaining = 0;
	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			find_img(data, &img, data->map[x][y]);
			if (data->map[x][y] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->tiles.ground, y * TILE_SIZE, x * TILE_SIZE);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				img, y * TILE_SIZE, x * TILE_SIZE);
			if (data->map[x][y] == 'C')
				data->c_remaining ++;
			y ++;
		}
		x ++;
	}
}

int	initialize(char **tab, size_t len, int nelem)
{
	t_data	data;

	data.was_carot = 0;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, (int)len * TILE_SIZE,
			nelem * TILE_SIZE, "So long");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	load_images(&data);
	data.map = tab;
	create_map(&data);
	data.was_carot = 0;
	data.was_exit = 0;
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy,
		&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
