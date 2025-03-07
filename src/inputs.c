#include "so_long.h"
#include "libft.h"

int	on_keypress(int keycode, t_data *data)
{
	if (keycode == K_Q || keycode == K_ESC)
	{
		write(1, "exit\n", 5);
		on_destroy(data);
	}
	else if (keycode == K_W || keycode == K_AR_U)
		ft_move(data, 'U');
	else if (keycode == K_A || keycode == K_AR_L)
		ft_move(data, 'L');
	else if (keycode == K_S || keycode == K_AR_D)
		ft_move(data, 'D');
	else if (keycode == K_D || keycode == K_AR_R)
		ft_move(data, 'R');
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