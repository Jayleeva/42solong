#include "so_long.h"
#include "libft.h"
	
/*void	ft_move(t_data *data, char ax, int move)
{
	int	max_right = len -1;
	int	max_up = nelem -1;

	if (!(pos.x > 1) && !(pos.x < max_right))
		if (!(pos.y > 1) && !(pos.x < max_up))
			return ;
	if (move == UP)
	{
		if (pos.y -1 == '0')
			mlx_put_image_to_window();
		else if (pos.y -1 == 'C')
			//mettre a jour collecte 
	}
	else if (move == LEFT)
	{
	}
	
}*/

int	on_keypress(int keycode, t_data *data)
{
	if (keycode == K_Q || keycode == K_ESC)
	{
		write(1, "exit\n", 5);
		on_destroy(data);
	}
	else if (keycode == K_W || keycode == K_AR_U)
		//ft_move(data, 'y', UP);
		write(1, "up\n", 3);
	else if (keycode == K_A || keycode == K_AR_L)
		//ft_move(data, 'x', LEFT);
		write(1, "left\n", 5);
	else if (keycode == K_S || keycode == K_AR_D)
		//ft_move(data, 'y', DOWN);
		write(1, "down\n", 5);
	else if (keycode == K_D || keycode == K_AR_R)
		//ft_move(data, 'x', RIGHT);
			write(1, "right\n", 5);
	//if (data->map->map[data->p_y][data->p_x] == 'E')
		//winner(data);
	return (0);
}

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}