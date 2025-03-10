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

void	destroy_images(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->tiles.wall.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.ground.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.collectible.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.collected.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.exit.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.idle_down.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.idle_left.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.idle_right.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.idle_up.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.walk_down0.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.walk_left0.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.walk_right0.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.walk_up0.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.walk_down1.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.walk_left1.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.walk_right1.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.walk_up1.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.walk_down2.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.walk_left2.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.walk_right2.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.walk_up2.img);
}

int	on_destroy(t_data *data)
{
	destroy_images(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_tab(data->map);
	exit(0);
	return (0);
}
