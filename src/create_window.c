#include "so_long.h"
#include "libft.h"

int	initialize(char **tab)
{
	void    *mlx_ptr;
	void    *win_ptr;

	(void)tab;
	/*t_data data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "hi :)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);

	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);*/

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
    win_ptr = mlx_new_window(mlx_ptr, 600, 400, "hi :)");
    if (!win_ptr)
        return (free(mlx_ptr), 1);
    mlx_destroy_window(mlx_ptr, win_ptr);
    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
	return (0);
}