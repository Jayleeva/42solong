#include "so_long.h"
#include "libft.h"

int	initialize(char **tab)
{
	t_data data;

	(void)tab;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
	{
		write(1, "init\n", 5);
		return (1);
	}
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "hi :)");
	if (!data.win_ptr)
	{
		write(1, "window\n", 7);
		return (free(data.mlx_ptr), 1);
	}
	//mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	//mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}