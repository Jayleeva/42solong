/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:35:24 by cyglardo          #+#    #+#             */
/*   Updated: 2025/03/18 14:36:29 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	destroy_walk(t_data *data)
{
	if (data->tiles.walk_down0.img)
		mlx_destroy_image(data->mlx_ptr, data->tiles.walk_down0.img);
	if (data->tiles.walk_left0.img)
		mlx_destroy_image(data->mlx_ptr, data->tiles.walk_left0.img);
	if (data->tiles.walk_right0.img)
		mlx_destroy_image(data->mlx_ptr, data->tiles.walk_right0.img);
	if (data->tiles.walk_up0.img)
		mlx_destroy_image(data->mlx_ptr, data->tiles.walk_up0.img);
	if (data->tiles.walk_down1.img)
		mlx_destroy_image(data->mlx_ptr, data->tiles.walk_down1.img);
	if (data->tiles.walk_left1.img)
		mlx_destroy_image(data->mlx_ptr, data->tiles.walk_left1.img);
	if (data->tiles.walk_right1.img)
		mlx_destroy_image(data->mlx_ptr, data->tiles.walk_right1.img);
	if (data->tiles.walk_up1.img)
		mlx_destroy_image(data->mlx_ptr, data->tiles.walk_up1.img);
	if (data->tiles.walk_down2.img)
		mlx_destroy_image(data->mlx_ptr, data->tiles.walk_down2.img);
	if (data->tiles.walk_left2.img)
		mlx_destroy_image(data->mlx_ptr, data->tiles.walk_left2.img);
	if (data->tiles.walk_right2.img)
		mlx_destroy_image(data->mlx_ptr, data->tiles.walk_right2.img);
	if (data->tiles.walk_up2.img)
		mlx_destroy_image(data->mlx_ptr, data->tiles.walk_up2.img);
}

void	destroy_idle(t_data *data)
{
	if (data->tiles.idle_down.img)
		mlx_destroy_image(data->mlx_ptr, data->tiles.idle_down.img);
	if (data->tiles.idle_left.img)
		mlx_destroy_image(data->mlx_ptr, data->tiles.idle_left.img);
	if (data->tiles.idle_right.img)
		mlx_destroy_image(data->mlx_ptr, data->tiles.idle_right.img);
	if (data->tiles.idle_up.img)
		mlx_destroy_image(data->mlx_ptr, data->tiles.idle_up.img);
}

void	destroy_background(t_data *data)
{
	if (data->tiles.wall.img)
		mlx_destroy_image(data->mlx_ptr, data->tiles.wall.img);
	if (data->tiles.ground.img)
		mlx_destroy_image(data->mlx_ptr, data->tiles.ground.img);
	if (data->tiles.collectible.img)
		mlx_destroy_image(data->mlx_ptr, data->tiles.collectible.img);
	if (data->tiles.collected.img)
		mlx_destroy_image(data->mlx_ptr, data->tiles.collected.img);
	if (data->tiles.exit.img)
		mlx_destroy_image(data->mlx_ptr, data->tiles.exit.img);
}

void	destroy_images(t_data *data)
{
	destroy_background(data);
	destroy_idle(data);
	destroy_walk(data);
}
