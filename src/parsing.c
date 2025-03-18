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

static char	**fill_map(char *arg, char **tab)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (tab);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		tab[i] = ft_strdup(line);
		free(line);
		if (tab[i] == NULL)
		{
			free_tab_rev(tab, i);
			break ;
		}
		i ++;
	}
	tab[i] = NULL;
	close(fd);
	return (tab);
}

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

static int	count_lines(char *arg)
{
	int		i;
	char	*line;
	char	*tmp;
	int		fd;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (0);
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

int	is_a_map(char *filename)
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

int	main(int argc, char **argv)
{
	char	**tab;
	size_t	len;
	int		nelem;

	if (argc != 2)
		return (write(2, "Error\nUse format : ./so_long <map.ber>\n", 40), 1);
	if (is_a_map(argv[1]) == 0 || open(argv[1], O_RDONLY) < 0)
		return (write(2, "Error\nInvalid file.\n", 21), 1);
	nelem = count_lines(argv[1]);
	if (nelem == 0)
		return (write(2, "Error\nInvalid map : empty.\n", 26), 1);
	tab = (char **)malloc((nelem + 1) * sizeof(char *));
	if (tab == NULL)
		return (1);
	tab = fill_map(argv[1], tab);
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
