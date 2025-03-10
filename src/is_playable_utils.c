#include "so_long.h"
#include "libft.h"

t_point	get_player_pos(char **tab, t_point pos)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'P')
			{
				pos.x = i;
				pos.y = j;
				return (pos);
			}
			j ++;
		}
		i ++;
	}
	return (pos);
}

int	is_everything_flooded(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != 'F' && map[i][j] != '0')
				return (0);
			j++;
		}
		i ++;
	}
	return (1);
}
