/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   is_invalid.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/10 16:40:41 by cyglardo       #+#    #+#                */
/*   Updated: 2025/03/10 16:40:42 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static int	is_playable(char **tab, int nelem, size_t len)
{
	if (has_elem(tab, 'P') == 0)
	{
		write(2, "Error\nInvalid map : incorrect number of player.\n", 48);
		return (0);
	}
	if (has_elem(tab, 'C') == 0)
	{
		write(2, "Error\nInvalid map : no collectible.\n", 36);
		return (0);
	}
	if (has_elem(tab, 'E') == 0)
	{
		write(2, "Error\nInvalid map : incorrect number of exit.\n", 46);
		return (0);
	}
	if (is_everything_reachable(tab, nelem, len) == 0)
	{
		write(2, "Error\nInvalid map : exit unreachable.\n", 38);
		return (0);
	}
	return (1);
}

static int	is_surrounded_by_walls(char **tab, int nelem, size_t len)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		if (i == 0 || i == nelem -1)
		{
			j = 0;
			while (tab[i][j])
			{
				if (tab[i][j] != '1')
					return (0);
				j ++;
			}
		}
		else
		{
			if (tab[i][0] != '1' || tab[i][len -1] != '1')
				return (0);
		}
		i ++;
	}
	return (1);
}

static int	is_rectangular(char **tab, int nelem, size_t len)
{
	int		i;
	size_t	j;

	i = 1;
	while (nelem -1)
	{
		j = 0;
		while (tab[i][j])
			j ++;
		if (len != j)
			return (0);
		i ++;
		nelem --;
	}
	return (1);
}

int	has_only_valid_char(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (is_in_set(MAP_SET, tab[i][j]) == 0)
				return (0);
			j ++;
		}
		i ++;
	}
	return (1);
}

int	is_map_invalid(char **tab, int nelem, size_t len)
{
	if (nelem < 3 || len < 3)
	{
		write(2, "Error\nInvalid map : too small.\n", 31);
		return (1);
	}
	if (has_only_valid_char(tab) == 0)
	{
		write(2, "Error\nInvalid char in map.\n", 27);
		return (1);
	}
	if (is_rectangular(tab, nelem, len) == 0)
	{
		write(2, "Error\nInvalid map : is not rectangular.\n", 40);
		return (1);
	}
	if (is_surrounded_by_walls(tab, nelem, len) == 0)
	{
		write(2, "Error\nInvalid map : missing walls.\n", 35);
		return (1);
	}
	if (is_playable(tab, nelem, len) == 0)
		return (1);
	return (0);
}
