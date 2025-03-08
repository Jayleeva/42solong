#include "so_long.h"
#include "libft.h"

static int  is_everything_flooded(char **map)
{
    int i;
    int j;

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

t_point   get_player_pos(char **tab,  t_point pos)
{
    int     i;
    int     j;

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

static int  is_everything_reachable(char **tab, int nelem, size_t len)
{
    t_point begin = {};
    t_point size;
    char    **flooded;
    int     i;

    flooded = (char **)malloc((nelem + 1) * sizeof(char *));
    if (flooded == NULL)
        return (0);
    i = 0;
    while (tab[i])
    {
        flooded[i] = ft_strdup(tab[i]);
        if (flooded[i] == NULL)
            return(free_tab(flooded), free_tab(tab), 0);
        i ++;
    }
    begin = get_player_pos(tab, begin);
    if (begin.x == 0 && begin.y == 0)
        return (0);
    size.x = len;
    size.y = nelem;
    flooded = flood(flooded, size, begin);
    //display_map(flooded);
    if (is_everything_flooded(flooded) == 0)
        return (0);
    return (1);
}

static int  has_elem_util(int count, char c)
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

static int  has_elem(char **tab, char c)
{
    int i;
    int j;
    int count;

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

static int  is_playable(char **tab, int nelem, size_t len)
{
    if (has_elem(tab, 'P') == 0)
        return (0);
    write(1, "4\n", 2);
    if (has_elem(tab, 'C') == 0)
        return (0);
    write(1, "5\n", 2);
    if (has_elem(tab, 'E') == 0)
        return (0);
    write(1, "6\n", 2);
    if (is_everything_reachable(tab, nelem, len) == 0)
        return (0);
    write(1, "7\n", 2);
    return (1);
}

static int  is_surrounded_by_walls(char **tab, int nelem, size_t len)
{
    int i;
    int j;

    i = 0;
    while (tab[i])
    {
        if (i == 0 || i == nelem -1)
        {
            j = 0;
            while (tab[i][j])
            {
                //ft_printf("tab[%d][%d] = %c\n", i, j, tab[i][j]);
                if (tab[i][j] != '1')
                    return (0);
                j ++;
            }
        }
        else
        {
            //ft_printf("tab[%d][0] = %c, tab[%d][%d] = %c\n", i, tab[i][0], i, last, tab[i][last -1]);
            if (tab[i][0] != '1' || tab[i][len -1] != '1')
                return (0);
        }
        i ++;
    }
    return (1);
}

static int  is_rectangular(char **tab, int nelem, size_t len)
{
    int     i;
    size_t  j;

    i = 1;
    while (nelem -1)
    {
        j = 0;
        while (tab[i][j])
            j ++;
        //ft_printf("j = %d, len = %d\n", j, len);
        if (len != j)
            return (0);
        i ++;
        nelem --;
    }
    return (1);
}

static int is_in_set_(char *set, char c)
{
    int i;

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

int has_only_valid_char(char **tab)
{
    int     i;
    int     j;
    char    *set;

    set =(char *)malloc((6 + 1) * sizeof(char));
    if (set == NULL)
        return (1);
    set = "10PCE\n";
    i = 0;
    while (tab[i])
    {
        j = 0;
        while (tab[i][j])
        {
            if (is_in_set_(set, tab[i][j]) == 0)
                return (0);
            j ++;
        }
        i ++;
    }
    return (1);
}

int is_map_invalid(char **tab, int nelem, size_t len)
{
    if (nelem < 3 || len < 3)
        return (1);
    if (has_only_valid_char(tab) == 0)
        return (1);
    write(1, "1\n", 2);
    if (is_rectangular(tab, nelem, len) == 0)
        return (1);
    write(1, "2\n", 2);
    if (is_surrounded_by_walls(tab, nelem, len) == 0)
        return (1);
    write(1, "3\n", 2);
    if (is_playable(tab, nelem, len) == 0)
        return (1);
    return (0);
}
