/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   update_tiles.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/10 16:41:45 by cyglardo       #+#    #+#                */
/*   Updated: 2025/03/10 16:41:46 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	update_last_tile(t_data *data, t_point pos)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->tiles.ground.img, pos.y * 64, pos.x * 64);
	if (data->was_carot == 1 || data->map[pos.x][pos.y] == 'c')
	{
		data->was_carot = 0;
		data->map[pos.x][pos.y] = 'c';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.collected.img, pos.y * 64, pos.x * 64);
	}
	else if (data->was_exit == 1 || data->map[pos.x][pos.y] == 'E')
	{
		data->was_exit = 0;
		data->map[pos.x][pos.y] = 'E';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.exit.img, pos.y * 64, pos.x * 64);
	}
	else
	{
		data->map[pos.x][pos.y] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.ground.img, pos.y * 64, pos.x * 64);
	}
}
void	update_new_tile(t_data *data, t_point pos)
{
	if (data->map[pos.x][pos.y] == 'C')
	{
		data->map[pos.x][pos.y] = 'c';
		data->c_remaining --;
	}
	if (data->map[pos.x][pos.y] == 'c')
		data->was_carot = 1;
	else if (data->map[pos.x][pos.y] == 'E')
	{
		if (data->c_remaining == 0)
			on_destroy(data);
		else
			data->was_exit = 1;
	}
}
