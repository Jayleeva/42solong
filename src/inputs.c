#include "so_long.h"
#include "libft.h"

	//mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	//mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	
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

/*int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == K_Q || keycode == K_ESC)
		ft_exit(data);
	else if (keycode == K_W || keycode == K_AR_U)
		ft_move(data, 'y', UP);
	else if (keycode == K_A || keycode == K_AR_L)
		ft_move(data, 'x', LEFT);
	else if (keycode == K_S || keycode == K_AR_D)
		ft_move(data, 'y', DOWN);
	else if (keycode == K_D || keycode == K_AR_R)
		ft_move(data, 'x', RIGHT);
	//if (data->map->map[data->p_y][data->p_x] == 'E')
		//winner(data);
	return (0);
}*/