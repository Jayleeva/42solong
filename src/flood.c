/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   flood.c                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/10 16:40:22 by cyglardo       #+#    #+#                */
/*   Updated: 2025/03/10 16:40:23 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	is_in_set(char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		else
			i ++;
	}
	return (0);
}

char	**flood(char **tab, t_point size, t_point begin)
{
	tab[begin.y][begin.x] = 'F';
	if (begin.y > 0 && is_in_set(SET_FLOOD, tab[begin.y - 1][begin.x]))
	{
		begin.y = begin.y - 1;
		flood(tab, size, begin);
	}
	if ((begin.y < (size.y - 1))
		&& is_in_set(SET_FLOOD, tab[begin.y + 1][begin.x]))
	{
		begin.y = begin.y + 1;
		flood(tab, size, begin);
	}
	if ((begin.x < (size.x - 1))
		&& is_in_set(SET_FLOOD, tab[begin.y][begin.x + 1]))
	{
		begin.x = begin.x + 1;
		flood(tab, size, begin);
	}
	if (begin.x > 0 && is_in_set(SET_FLOOD, tab[begin.y][begin.x - 1]))
	{
		begin.x = begin.x - 1;
		flood(tab, size, begin);
	}
	return (tab);
}
