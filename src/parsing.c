#include "so_long.h"
#include "libft.h"

static int  is_everything_reachable(char **tab)
{
    void(tab);
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

static int  is_playable(char **tab)
{
    //char    **test;
    
    if (has_elem(tab, 'P') == 0)
        return (0);
    if (has_elem(tab, 'C') == 0)
        return (0);
    if (has_elem(tab, 'E') == 0)
        return (0);
    if (is_everything_reachable(tab) == 0)
        return (0);
    //test = flood(tab);
    return (1);
}

static int  is_surrounded_by_walls(char **tab, int nelem, size_t len)
{
    int i;
    int j;
    int last;

    last = len -1;
    i = 0;
    while (tab[i])
    {
        if (i == 0 || i == nelem -1)
        {
            j = 0;
            len = last;
            while (len)
            {
                //ft_printf("tab[%d][%d] = %c\n", i, j, tab[i][j]);
                if (tab[i][j] != '1')
                    return (0);
                j ++;
                len --;
            }
        }
        else
        {
            //ft_printf("tab[%d][0] = %c, tab[%d][%d] = %c\n", i, tab[i][0], i, last, tab[i][last -1]);
            if (tab[i][0] != '1' || tab[i][last -1] != '1')
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
    while (nelem -2)
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
    j = 0;
    while (tab[i][j])
        j ++;
    //ft_printf("j = %d, len = %d\n", j, len);
    if (len -1 != j)
        return (0);
    return (1);
}

int is_map_invalid(char **tab, int nelem, size_t len)
{
    if (nelem < 3 && len < 5)
        return (1);
    write(1, "1\n", 2);
    if (is_rectangular(tab, nelem, len) == 0)
        return (1);
    write(1, "2\n", 2);
    if (is_surrounded_by_walls(tab, nelem, len) == 0)
        return (1);
    write(1, "3\n", 2);
    if (is_playable(tab) == 0)
        return (1);
    return (0);
}

int count_lines(char *arg)
{
    int     i;
    char    *line;
    int     fd;

    fd = open(arg, O_RDONLY);
    if (fd < 0)
        return (0);
    i = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        i ++;
    }
    close(fd);
    return (i);
}

int main(int argc, char **argv)
{
    char    *line;
    int     file_descriptor;
    char    **tab;
    int     i;
    //int     j;
    size_t  len;

    if (argc != 2)
        return (0);
    i = count_lines(argv[1]);
    tab = (char **)malloc((i + 1) * sizeof(char *));
    if (tab == NULL)
        return (0);
    file_descriptor = open(argv[1], O_RDONLY);
    if (file_descriptor < 0)
        return (0);
    i = 0;
    while (1)
    {
        line = get_next_line(file_descriptor);
        if (line == NULL)
            break;
        len = ft_strlen(line);
        ft_memcpy(&tab[i], &line, (int)len);
        i ++;
    }
    tab[i] = NULL;
    close(file_descriptor);
    len = ft_strlen(tab[0]);
    //display_map(tab);
    if (is_map_invalid(tab, i, len) == 1)
    {
        ft_printf("Error : map invalid.");
        return (free_tab(tab), 0);
    }
}