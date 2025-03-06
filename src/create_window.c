#include "so_long.h"
#include "libft.h"
//#include "mlx.h"

void	create_images(void *mlx, void *win)
{
	void	*img;
	char	*relative_path = "./sprites_xpm/wall.xpm";
	int		img_width;
	int		img_height;

	write(1, "Mini: 1\n", 8);
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	write(1, "Mini: 2\n", 8);
	mlx_put_image_to_window(mlx, win, img, 64, 64);
	write(1, "Mini: 3\n", 8);
}

int	initialize(char **tab)
{
	t_data	data;

	(void)tab;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
	{
		write(1, "init\n", 5);
		return (1);
	}
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1200, 800, "So long");
	if (!data.win_ptr)
	{
		write(1, "window\n", 7);
		return (free(data.mlx_ptr), 1);
	}
	create_images(data.mlx_ptr, data.win_ptr);
	mlx_loop(data.mlx_ptr);
	//mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	//mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	//create_map(data.mlx_ptr, tab);
	return (0);
}