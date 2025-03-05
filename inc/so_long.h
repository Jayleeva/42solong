#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"

typedef struct	s_point
{
	int	x;
	int	y;
}		t_point;

char	**flood(char **tab, t_point size, t_point begin);
void    display_map(char **tab);
int 	is_map_invalid(char **tab, int nelem, size_t len);
#endif