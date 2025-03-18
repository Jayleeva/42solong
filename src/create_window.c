/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   create_window.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/10 16:40:11 by cyglardo       #+#    #+#                */
/*   Updated: 2025/03/10 16:40:14 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	find_img(t_data *data, t_img **img, char c)
{
	if (c == '1')
		*img = data->tiles.wall.img;
	else if (c == '0')
		*img = data->tiles.ground.img;
	else if (c == 'E')
		*img = data->tiles.exit.img;
	else if (c == 'C')
		*img = data->tiles.collectible.img;
	else
		*img = data->tiles.idle_right.img;
}

void	create_map(t_data *data)
{
	int		x;
	int		y;
	t_img	*img;

	data->c_remaining = 0;
	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			find_img(data, &img, data->map[x][y]);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				img, y * 64, x * 64);
			if (data->map[x][y] == 'C')
				data->c_remaining ++;
			y ++;
		}
		x ++;
	}
}

static void	initialize_images(t_data *data)
{
	data->tiles.wall.img = NULL;
	data->tiles.ground.img = NULL;
	data->tiles.collectible.img = NULL;
	data->tiles.collected.img = NULL;
	data->tiles.exit.img = NULL;
	data->tiles.idle_down.img = NULL;
	data->tiles.idle_left.img = NULL;
	data->tiles.idle_right.img = NULL;
	data->tiles.idle_up.img = NULL;
	data->tiles.walk_down0.img = NULL;
	data->tiles.walk_left0.img = NULL;
	data->tiles.walk_right0.img = NULL;
	data->tiles.walk_up0.img = NULL;
	data->tiles.walk_down1.img = NULL;
	data->tiles.walk_left1.img = NULL;
	data->tiles.walk_right1.img = NULL;
	data->tiles.walk_up1.img = NULL;
	data->tiles.walk_down2.img = NULL;
	data->tiles.walk_left2.img = NULL;
	data->tiles.walk_right2.img = NULL;
	data->tiles.walk_up2.img = NULL;
}

static void	init(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->map = NULL;
	data->c_remaining = -1;
	data->was_carrot = -1;
	data->was_exit = -1;
	data->load_successful = -1;
	initialize_images(data);
}

void	initialize(char **tab, size_t len, int nelem)
{
	t_data	data;

	init(&data);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		on_destroy(&data);
	data.win_ptr = mlx_new_window(data.mlx_ptr, (int)len * 64,
			nelem * 64, "So long");
	if (!data.win_ptr)
		on_destroy(&data);
	load_images(&data);
	data.map = tab;
	create_map(&data);
	data.was_carrot = 0;
	data.was_exit = 0;
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy,
		&data);
	mlx_loop(data.mlx_ptr);
	on_destroy(&data);
}
