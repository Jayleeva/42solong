/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   inputs.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/10 16:40:33 by cyglardo       #+#    #+#                */
/*   Updated: 2025/03/10 16:40:34 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	on_keypress(int keycode, t_data *data)
{
	if (keycode == K_Q || keycode == K_ESC)
		on_destroy(data);
	else if (keycode == K_W || keycode == K_AR_U)
		ft_move(data, 'U');
	else if (keycode == K_A || keycode == K_AR_L)
		ft_move(data, 'L');
	else if (keycode == K_S || keycode == K_AR_D)
		ft_move(data, 'D');
	else if (keycode == K_D || keycode == K_AR_R)
		ft_move(data, 'R');
	return (0);
}

int	on_destroy(t_data *data)
{
	if (!data)
		return (0);
	destroy_images(data);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->map)
		free_tab(data->map);
	exit(0);
	return (0);
}
