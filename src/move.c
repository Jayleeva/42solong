/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   move.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/10 16:41:22 by cyglardo       #+#    #+#                */
/*   Updated: 2025/03/10 16:41:22 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static int	move_left(t_data *data, int frame)
{
	t_point	pos;

	pos = get_player_pos(data->map, pos);
	if (data->map[pos.x][pos.y + LEFT] == '1')
		return (0);
	update_last_tile(data, pos);
	pos.y += LEFT;
	update_new_tile(data, pos);
	if (frame == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.idle_left.img, (pos.y) * 64, (pos.x) * 64);
	else if (frame == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.walk_left0.img, (pos.y) * 64, (pos.x) * 64);
	else if (frame == 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.walk_left1.img, (pos.y) * 64, (pos.x) * 64);
	else if (frame == 3)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.walk_left2.img, (pos.y) * 64, (pos.x) * 64);
	data->map[pos.x][pos.y] = 'P';
	return (1);
}

static int	move_right(t_data *data, int frame)
{
	t_point	pos;

	pos = get_player_pos(data->map, pos);
	if (data->map[pos.x][pos.y + RIGHT] == '1')
		return (0);
	update_last_tile(data, pos);
	pos.y += RIGHT;
	update_new_tile(data, pos);
	if (frame == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.idle_right.img, (pos.y) * 64, (pos.x) * 64);
	else if (frame == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.walk_right0.img, (pos.y) * 64, (pos.x) * 64);
	else if (frame == 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.walk_right1.img, (pos.y) * 64, (pos.x) * 64);
	else if (frame == 3)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.walk_right2.img, (pos.y) * 64, (pos.x) * 64);
	data->map[pos.x][pos.y] = 'P';
	return (1);
}

static int	move_up(t_data *data, int frame)
{
	t_point	pos;

	pos = get_player_pos(data->map, pos);
	if (data->map[pos.x + UP][pos.y] == '1')
		return (0);
	update_last_tile(data, pos);
	pos.x += UP;
	update_new_tile(data, pos);
	if (frame == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.idle_up.img, (pos.y) * 64, (pos.x) * 64);
	else if (frame == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.walk_up0.img, (pos.y) * 64, (pos.x) * 64);
	else if (frame == 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.walk_up1.img, (pos.y) * 64, (pos.x) * 64);
	else if (frame == 3)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.walk_up2.img, (pos.y) * 64, (pos.x) * 64);
	data->map[pos.x][pos.y] = 'P';
	return (1);
}

static int	move_down(t_data *data, int frame)
{
	t_point	pos;

	pos = get_player_pos(data->map, pos);
	if (data->map[pos.x + DOWN][pos.y] == '1')
		return (0);
	update_last_tile(data, pos);
	pos.x += DOWN;
	update_new_tile(data, pos);
	if (frame == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.idle_down.img, (pos.y) * 64, (pos.x) * 64);
	else if (frame == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.walk_down0.img, (pos.y) * 64, (pos.x) * 64);
	else if (frame == 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.walk_down1.img, (pos.y) * 64, (pos.x) * 64);
	else if (frame == 3)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.walk_down2.img, (pos.y) * 64, (pos.x) * 64);
	data->map[pos.x][pos.y] = 'P';
	return (1);
}

void	ft_move(t_data *data, char move)
{
	static int	frame = 0;
	static int	count = 0;
	int			moves;

	moves = 0;
	if (move == 'D')
		moves = move_down(data, frame);
	else if (move == 'U')
		moves = move_up(data, frame);
	else if (move == 'L')
		moves = move_left(data, frame);
	else if (move == 'R')
		moves = move_right(data, frame);
	if (frame < 3)
		frame ++;
	else
		frame = 0;
	count += moves;
	if (moves != 0)
		ft_printf("Movements : %d\n", count);
}
