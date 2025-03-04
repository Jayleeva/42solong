#include "so_long.h"
#include "libft.h"

int	is_in_set(char c)
{
	char	set[4];
	int		i;

	set[0] = '0';
	set[1] = 'C';
	set[2] = 'E';
	set[3] = 'P';
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
	t_point	p;

	tab[begin.y][begin.x] = 'F';
	if (begin.y > 0 && is_in_set(tab[begin.y - 1][begin.x]))
	{
		//ft_printf("UP\n");
		p.x = begin.x;
		p.y = begin.y - 1;
		flood(tab, size, p);
	}
	if ((begin.y < (size.y - 1)) && is_in_set(tab[begin.y + 1][begin.x]))
	{
		//ft_printf("DOWN\n");
		p.x = begin.x;
		p.y = begin.y + 1;
		flood(tab, size, p);
	}
	if ((begin.x < (size.x - 1)) && is_in_set(tab[begin.y][begin.x + 1]))
	{
		//ft_printf("RIGHT\n");
		p.x = begin.x + 1;
		p.y = begin.y;
		flood(tab, size, p);
	}
	if (begin.x > 0 && is_in_set(tab[begin.y][begin.x - 1]))
	{
		//ft_printf("LEFT\n");
		p.x = begin.x - 1;
		p.y = begin.y;
		flood(tab, size, p);
	}
	return (tab);
}
