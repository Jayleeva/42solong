#include "so_long.h"
#include "libft.h"

static char **fill_tab(char *arg, char **tab)
{
    int     fd;
    char    *line;
    int     i;
    size_t  len;

    fd = open(arg, O_RDONLY);
    if (fd < 0)
        return (0);
    i = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        len = ft_strlen(line);
        ft_memcpy(&tab[i], &line, (int)len);
        i ++;
    }
    tab[i] = NULL;
    close(fd);
    return (tab);
}

static int count_lines(char *arg)
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
    char    **tab;
    size_t  len;
    int     nelem;

    if (argc != 2)
        return (0);
    nelem = count_lines(argv[1]);
    tab = (char **)malloc((nelem + 1) * sizeof(char *));
    if (tab == NULL)
        return (0);
    tab = fill_tab(argv[1], tab);
    //display_map(tab);
    len = ft_strlen(tab[0]);
    if (is_map_invalid(tab, nelem, len) == 1)
    {
        ft_printf("Error : map invalid.\n");
        return (free_tab(tab), 0);
    }
    ft_printf("Map valid!\n");
}