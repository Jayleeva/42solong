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
		{
			write(1, &c, 1);
			write(1, "\n", 1);
			return (1);
		}
		else
			i ++;
	}
	return (0);
}

char	**flood(char **tab, t_point size, t_point begin)
{
	char	c;
	t_point	p;

	c = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';
	if (begin.y > 0 && tab[begin.y - 1][begin.x] == is_in_set(c))
	{
		write(1, "DOWN\n", 5);
		p.x = begin.x;
		p.y = begin.y - 1;
		flood(tab, size, p);
	}
	if ((begin.y < (size.y - 1)) && tab[begin.y + 1][begin.x] == is_in_set(c))
	{
		write(1, "UP\n", 3);
		p.x = begin.x;
		p.y = begin.y + 1;
		flood(tab, size, p);
	}
	if ((begin.x < (size.x - 1)) && tab[begin.y][begin.x + 1] == is_in_set(c))
	{
		write(1, "RIGHT\n", 6);
		p.x = begin.x + 1;
		p.y = begin.y;
		flood(tab, size, p);
	}
	if (begin.x > 0 && tab[begin.y][begin.x - 1] == is_in_set(c))
	{
		write(1, "LEFT\n", 5);
		p.x = begin.x - 1;
		p.y = begin.y;
		flood(tab, size, p);
	}
	return (tab);
}
