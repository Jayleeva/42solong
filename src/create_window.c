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

void	create_map(t_data *data, char **tab)
{
	int		x;
	int		y;
	void	*img;

	x = 0;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y])
		{
			//ft_printf("x = %d, y = %d\n", x, y);
			find_img(data, &img, tab[x][y]);
			if (tab[x][y] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->tiles.ground, y * 64, x * 64);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, y * 64, x * 64);
			y ++;
		}
		x ++;
	}
}

void	load_images(t_data *data)
{
	int		img_width;
	int		img_height;

	data->tiles.wall = mlx_xpm_file_to_image(data->mlx_ptr, path_wall, &img_width, &img_height);
	(data->tiles.wall)->width = img_width;
	(data->tiles.wall)->height = img_height;
	data->tiles.ground = mlx_xpm_file_to_image(data->mlx_ptr, path_ground, &img_width, &img_height);
	(data->tiles.ground)->width = img_width;
	(data->tiles.ground)->height = img_height;
	data->tiles.exit = mlx_xpm_file_to_image(data->mlx_ptr, path_exit, &img_width, &img_height);
	(data->tiles.exit)->width = img_width;
	(data->tiles.exit)->height = img_height;
	data->tiles.collectible = mlx_xpm_file_to_image(data->mlx_ptr, path_collectible, &img_width, &img_height);
	(data->tiles.collectible)->width = img_width;
	(data->tiles.collectible)->height = img_height;
	data->tiles.collected = mlx_xpm_file_to_image(data->mlx_ptr, path_collected, &img_width, &img_height);
	(data->tiles.collected)->width = img_width;
	(data->tiles.collected)->height = img_height;

	data->tiles.idle_down = mlx_xpm_file_to_image(data->mlx_ptr, path_idle_down, &img_width, &img_height);
	(data->tiles.idle_down)->width = img_width;
	(data->tiles.idle_down)->height = img_height;
	data->tiles.idle_left = mlx_xpm_file_to_image(data->mlx_ptr, path_idle_left, &img_width, &img_height);
	(data->tiles.idle_left)->width = img_width;
	(data->tiles.idle_left)->height = img_height;
	data->tiles.idle_right = mlx_xpm_file_to_image(data->mlx_ptr, path_idle_right, &img_width, &img_height);
	(data->tiles.idle_right)->width = img_width;
	(data->tiles.idle_right)->height = img_height;
	data->tiles.idle_up = mlx_xpm_file_to_image(data->mlx_ptr, path_idle_up, &img_width, &img_height);
	(data->tiles.idle_up)->width = img_width;
	(data->tiles.idle_up)->height = img_height;

	data->tiles.walk_down0 = mlx_xpm_file_to_image(data->mlx_ptr, path_walk_down0, &img_width, &img_height);
	(data->tiles.walk_down0)->width = img_width;
	(data->tiles.walk_down0)->height = img_height;
	data->tiles.walk_left0 = mlx_xpm_file_to_image(data->mlx_ptr, path_walk_left0, &img_width, &img_height);
	(data->tiles.walk_left0)->width = img_width;
	(data->tiles.walk_left0)->height = img_height;
	data->tiles.walk_right0 = mlx_xpm_file_to_image(data->mlx_ptr, path_walk_right0, &img_width, &img_height);
	(data->tiles.walk_right0)->width = img_width;
	(data->tiles.walk_right0)->height = img_height;
	data->tiles.walk_up0 = mlx_xpm_file_to_image(data->mlx_ptr, path_walk_up0, &img_width, &img_height);
	(data->tiles.walk_up0)->width = img_width;
	(data->tiles.walk_up0)->height = img_height;

	data->tiles.walk_down1 = mlx_xpm_file_to_image(data->mlx_ptr, path_walk_down1, &img_width, &img_height);
	(data->tiles.walk_down1)->width = img_width;
	(data->tiles.walk_down1)->height = img_height;
	data->tiles.walk_left1 = mlx_xpm_file_to_image(data->mlx_ptr, path_walk_left1, &img_width, &img_height);
	(data->tiles.walk_left1)->width = img_width;
	(data->tiles.walk_left1)->height = img_height;
	data->tiles.walk_right1 = mlx_xpm_file_to_image(data->mlx_ptr, path_walk_right1, &img_width, &img_height);
	(data->tiles.walk_right1)->width = img_width;
	(data->tiles.walk_right1)->height = img_height;
	data->tiles.walk_up1 = mlx_xpm_file_to_image(data->mlx_ptr, path_walk_up1, &img_width, &img_height);
	(data->tiles.walk_up1)->width = img_width;
	(data->tiles.walk_up1)->height = img_height;

	data->tiles.walk_down2 = mlx_xpm_file_to_image(data->mlx_ptr, path_walk_down2, &img_width, &img_height);
	(data->tiles.walk_down2)->width = img_width;
	(data->tiles.walk_down2)->height = img_height;
	data->tiles.walk_left2 = mlx_xpm_file_to_image(data->mlx_ptr, path_walk_left2, &img_width, &img_height);
	(data->tiles.walk_left2)->width = img_width;
	(data->tiles.walk_left2)->height = img_height;
	data->tiles.walk_right2 = mlx_xpm_file_to_image(data->mlx_ptr, path_walk_right2, &img_width, &img_height);
	(data->tiles.walk_right2)->width = img_width;
	(data->tiles.walk_right2)->height = img_height;
	data->tiles.walk_up2 = mlx_xpm_file_to_image(data->mlx_ptr, path_walk_up2, &img_width, &img_height);
	(data->tiles.walk_up2)->width = img_width;
	(data->tiles.walk_up2)->height = img_height;
}

int	initialize(char **tab, size_t len, int nelem)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, (int)len * 64, nelem * 64, "So long");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	load_images(&data);
	(void)tab;
	create_map(&data, tab);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}