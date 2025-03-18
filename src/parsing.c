/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   parsing.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/10 16:41:31 by cyglardo       #+#    #+#                */
/*   Updated: 2025/03/10 16:41:32 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static int	count_lines_2(char **tab)
{
	int		i;

	i = 0;
	if (!tab)
		return (i);
	while (tab[i])
		i++;
	return (i);
}

static int	count_lines(int fd)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (i);
	i++;
	while (line)
	{
		tmp = get_next_line(fd);
		free(line);
		if (tmp == NULL)
			break ;
		line = tmp;
		i++;
	}
	close(fd);
	return (i);
}

static int	is_a_map(char *filename)
{
	size_t	i;
	size_t	j;
	size_t	l;
	char	*ext;

	ext = ".ber";
	i = ft_strlen(filename);
	j = 1;
	l = 3;
	while (j < 4)
	{
		if (filename[i - j] != ext[l])
			return (0);
		l --;
		j ++;
	}
	return (1);
}

static char	**prep_map(int fd)
{
	char	**tab;
	int		nelem;

	tab = NULL;
	nelem = count_lines(fd);
	if (nelem == 0)
		return (write(2, "Error\nInvalid map : empty.\n", 26), tab);
	tab = (char **)malloc((nelem + 1) * sizeof(char *));
	if (tab == NULL)
		return (tab);
	tab = fill_map(fd, tab);
	return (tab);
}

int	main(int argc, char **argv)
{
	char	**tab;
	size_t	len;
	int		nelem;
	int		fd;

	if (argc != 2)
		return (write(2, "Error\nUse format : ./so_long <map.ber>\n", 40), 1);
	fd = open(argv[1], O_RDONLY);
	if (is_a_map(argv[1]) == 0 || fd < 0)
		return (write(2, "Error\nInvalid file.\n", 21), 1);
	tab = prep_map(fd);
	close(fd);
	if (tab[0] == NULL)
		return (free(tab), 1);
	len = ft_strlen(tab[0]);
	nelem = count_lines_2(tab);
	if (is_map_invalid(tab, nelem, len) == 1)
		return (free_tab(tab), 1);
	initialize(tab, len, nelem);
	free_tab(tab);
	return (0);
}
