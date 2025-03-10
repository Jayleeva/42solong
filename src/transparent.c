#include "so_long.h"
#include "libft.h"

void	blend_images_utils(char *src_d, char *dest_d, t_trans trans, int size)
{
	int		i;
	int		j;
	int		*c_s;
	int		*c_d;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			c_s = (int *)(src_d + j * trans.size_line + i * (trans.bpp / 8));
			c_d = (int *)(dest_d + j * trans.size_line + i * (trans.bpp / 8));
			if (*c_s != 0x00FFFFFF)
				*c_d = *c_s;
			i ++;
		}
		j ++;
	}
}

void	blend_images(t_img *dest, t_img *src)
{
	int		size;
	char	*dest_data;
	char	*src_data;
	t_trans	trans;

	dest_data = mlx_get_data_addr(dest, &trans.bpp,
			&trans.size_line, &trans.endian);
	src_data = mlx_get_data_addr(src, &trans.bpp,
			&trans.size_line, &trans.endian);
	size = src->width;
	blend_images_utils(src_data, dest_data, trans, size);
}

void	get_window_pixels_utils(char *img_d, XImage *img, t_trans trans, int s)
{
	int		i;
	int		j;

	i = 0;
	while (i < s)
	{
		j = 0;
		while (j < s)
		{
			*(int *)(img_d + j * trans.size_line
					+ i * (trans.bpp / 8)) = XGetPixel(img, i, j);
			j ++;
		}
		i ++;
	}
}

t_img	*get_window_pixels(t_data *data, int x, int y, int size)
{
	t_img	*img;
	XImage	*image;
	char	*img_data;
	t_trans	trans;

	img = mlx_new_image(data->mlx_ptr, size, size);
	if (!img)
		return (NULL);
	image = XGetImage(((t_xvar *)data->mlx_ptr)->display,
			((t_win_list *)data->win_ptr)->window,
			x, y, size, size, AllPlanes, ZPixmap);
	if (!image)
	{
		mlx_destroy_image(data->mlx_ptr, img);
		return (NULL);
	}
	img_data = mlx_get_data_addr(img, &trans.bpp,
			&trans.size_line, &trans.endian);
	get_window_pixels_utils(img_data, image, trans, size);
	XDestroyImage(image);
	return (img);
}

int	put_image_with_transparency(t_data *data, t_image *image, int x, int y)
{
	t_img	*window_pixels;

	if (image->transparent)
	{
		window_pixels = get_window_pixels(data, x, y, image->img->width);
		if (!window_pixels)
			return (0);
		blend_images(window_pixels, image->img);
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, window_pixels, x, y);
		mlx_destroy_image(data->mlx_ptr, window_pixels);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, image->img, x, y);
	}
	return (1);
}
