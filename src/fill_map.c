#include "so_long.h"
#include "libft.h"

char	**fill_map(int fd, char **tab)
{
	char	*line;
	int		i;

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
	return (tab);
}