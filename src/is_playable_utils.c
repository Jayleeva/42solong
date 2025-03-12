/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   is_playable_utils.c                                 :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/10 16:41:04 by cyglardo       #+#    #+#                */
/*   Updated: 2025/03/10 16:41:05 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

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

char	**flood(char **tab, t_point size, t_point begin)
{
	tab[begin.x][begin.y] = 'F';
	if (begin.y > 0 && is_in_set(FLOOD_SET, tab[begin.x][begin.y - 1]))
		flood(tab, size, (t_point){begin.x, begin.y -1});
	if ((begin.y < (size.y - 1))
		&& is_in_set(FLOOD_SET, tab[begin.x][begin.y + 1]))
		flood(tab, size, (t_point){begin.x, begin.y +1});
	if ((begin.x < (size.x - 1))
		&& is_in_set(FLOOD_SET, tab[begin.x + 1][begin.y]))
		flood(tab, size, (t_point){begin.x +1, begin.y});
	if (begin.x > 0 && is_in_set(FLOOD_SET, tab[begin.x - 1][begin.y]))
		flood(tab, size, (t_point){begin.x -1, begin.y});
	return (tab);
}
