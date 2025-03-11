/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   is_playable.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/10 16:40:52 by cyglardo       #+#    #+#                */
/*   Updated: 2025/03/10 16:40:54 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	is_everything_reachable(char **tab, int nelem, size_t len)
{
	t_point	begin;
	t_point	size;
	char	**flooded;
	int		i;

	flooded = (char **)malloc((nelem + 1) * sizeof(char *));
	if (flooded == NULL)
		return (0);
	i = 0;
	while (tab[i])
	{
		flooded[i] = ft_strdup(tab[i]);
		if (flooded[i] == NULL)
			return (free_tab(flooded), 0);
		i ++;
	}
	begin = get_player_pos(tab, begin);
	size.x = len;
	size.y = nelem;
	flooded = flood(flooded, size, begin);
	if (is_everything_flooded(flooded) == 0)
		return (free_tab(flooded), 0);
	return (1);
}

static int	has_elem_util(int count, char c)
{
	if (c == 'C')
	{
		if (count < 1)
			return (0);
	}
	else
	{
		if (count != 1)
			return (0);
	}
	return (1);
}

int	has_elem(char **tab, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == c)
				count ++;
			j ++;
		}
		i ++;
	}
	if (has_elem_util(count, c) == 0)
		return (0);
	return (1);
}
