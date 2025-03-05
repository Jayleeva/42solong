#include "so_long.h"
#include "libft.h"

/*void	create_images(mlx)
{
	void	*img;
	char	*relative_path = "./sprites_xpm/wall.xpm";
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (img == NULL)
		return (free(mlx));
}*/

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
	//create_images(data.mlx_ptr);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "hi :)");
	if (!data.win_ptr)
	{
		write(1, "window\n", 7);
		return (free(data.mlx_ptr), 1);
	}
	//mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	//mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);

	//create_map(data.mlx_ptr, tab);
	return (0);
}