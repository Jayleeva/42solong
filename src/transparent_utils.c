#include "so_long.h"
#include "libft.h"

void	check_transparency(t_image *image)
{
	int		i;
	int		j;
	char	*content;
	t_trans	trans;

	image->transparent = 0;
	i = 0;
	content = mlx_get_data_addr(image->img,
			&trans.bpp, &trans.size_line, &trans.endian);
	while (i < image->img->width)
	{
		j = 0;
		while (j < image->img->height)
		{
			if (*(int *)(content + j * trans.size_line
				+ i * (trans.bpp / 8)) == 0x00FFFFFF)
			{
				image->transparent = 1;
				return ;
			}
			j ++;
		}
		i ++;
	}
}
