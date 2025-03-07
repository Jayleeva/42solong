#include "so_long.h"
#include "libft.h"

void    check_tile(t_data *data, t_point pos)
{
    if (data->map[pos.x][pos.y] == 'C')
    {
        data->was_carot = 1;
        data->map[pos.x][pos.y] = 'c';
        data->c_remaining --;
    }
    else if (data->map[pos.x][pos.y] == 'c')
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->tiles.collected, pos.y * 64, pos.x * 64);
    else if (data->map[pos.x][pos.y] == 'E')
    {
        if (data->c_remaining == 0)
            on_destroy(data);
    }
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->tiles.idle_right, (pos.y) * 64, (pos.x) * 64);
}

static int  move_left(t_data *data)
{
    t_point pos;
	
	pos = get_player_pos(data->map, pos);
	if (data->map[pos.x][pos.y + LEFT] == '1')
		return (0);
    data->map[pos.x][pos.y] = '0';
	if (data->was_carot == 1)
    {
        data->map[pos.x][pos.y] = 'c';
        //data->was_carot = 0;
    }
    if (data->was_carot == 1 || data->map[pos.x][pos.y] == 'c')
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->tiles.collected, pos.y * 64, pos.x * 64);
    else
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->tiles.ground, pos.y * 64, pos.x * 64);
    data->was_carot = 0;
    pos.y += LEFT;
    check_tile(data, pos);
    data->map[pos.x][pos.y] = 'P';
	return (1);
}

static int  move_right(t_data *data)
{
    t_point pos;
	
	pos = get_player_pos(data->map, pos);
	if (data->map[pos.x][pos.y + RIGHT] == '1')
		return (0);
	data->map[pos.x][pos.y] = '0';
    if (data->was_carot == 1)
    {
        data->map[pos.x][pos.y] = 'c';
        //data->was_carot = 0;
    }
    if (data->was_carot == 1 || data->map[pos.x][pos.y] == 'c')
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->tiles.collected, pos.y * 64, pos.x * 64);
    else
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->tiles.ground, pos.y * 64, pos.x * 64);
    data->was_carot = 0;
    pos.y += RIGHT;
    check_tile(data, pos);
    data->map[pos.x][pos.y] = 'P';
	return (1);
}

static int  move_up(t_data *data)
{
    t_point pos;
	
	pos = get_player_pos(data->map, pos);
	if (data->map[pos.x + UP][pos.y] == '1')
		return (0);
	data->map[pos.x][pos.y] = '0';
    if (data->was_carot == 1)
    {
        data->map[pos.x][pos.y] = 'c';
        //data->was_carot = 0;
    }
    if (data->was_carot == 1 || data->map[pos.x][pos.y] == 'c')
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->tiles.collected, pos.y * 64, pos.x * 64);
    else
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->tiles.ground, pos.y * 64, pos.x * 64);
    data->was_carot = 0;
    pos.x += UP;
    check_tile(data, pos);
    data->map[pos.x][pos.y] = 'P';
	return (1);
}

static int	move_down(t_data *data)
{
    t_point pos;
	
	pos = get_player_pos(data->map, pos);
	if (data->map[pos.x + DOWN][pos.y] == '1')
		return (0);
	data->map[pos.x][pos.y] = '0';
	if (data->was_carot == 1)
    {
        data->map[pos.x][pos.y] = 'c';
        //data->was_carot = 0;
    }
    if (data->was_carot == 1 || data->map[pos.x][pos.y] == 'c')
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->tiles.collected, pos.y * 64, pos.x * 64);
    else
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->tiles.ground, pos.y * 64, pos.x * 64);
    data->was_carot = 0;
    pos.x += DOWN;
    check_tile(data, pos);
    data->map[pos.x][pos.y] = 'P';
	return (1);
}

void	ft_move(t_data *data, char move)
{
	//static int	frame = 0;
	static int	count = 0;
	int			moves;

	//ft_printf("tab[1] = %s\n", data->map[1]);
	moves = 0;
	if (move == 'D')
		moves = move_down(data);
	else if (move == 'U')
		moves = move_up(data);
	else if (move == 'L')
		moves = move_left(data);
	else if (move == 'R')
		moves = move_right(data);
	/*if (frame < 3)
		frame ++;
	else
		frame = 0;*/

	count += moves;
	if (moves != 0)
		ft_printf("Movements : %d\n", count);
}