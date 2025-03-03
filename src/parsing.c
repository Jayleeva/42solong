#include "libft.h"

static int  is_playable(char **tab)
{
    //flood(tab);
    (void)tab;
    return (1);
}

static int  is_surrounded_by_walls(char **tab, int nelem, size_t len)
{
    int i;
    int j;

    i = 0;
    while (tab[i])
    {
        j = 0;
        while (tab[i][j])
        {
            if (i == 0 || i == nelem)
            {
                if (tab[i][j] != 1)
                    return (0);
            }
            else
            {
                if (tab[i][j] != 1 || tab[i][len] != 1)
                    return (0);
            }
            j ++;
        }
        i ++;
    }
    return (1);
}

static int  is_rectangular(char **tab, size_t len)
{
    int     i;
    size_t  j;

    i = 1;
    while (tab[i])
    {
        j = 0;
        while (tab[i][j])
            j ++;
        if (len != j)
            return (0);
        i ++;
    }
    return (1);
}

int is_map_invalid(char **tab, int nelem, size_t len)
{
    if (nelem < 3 && len < 5)
        return (1);
    write(1, "1\n", 2);
    if (is_rectangular(tab, len) == 0)
        return (1);
    write(1, "2\n", 2);
    if (is_surrounded_by_walls(tab, nelem, len) == 0)
    {
        write(1, "NO WALLS\n", 9);
        return (1);
    }
    write(1, "3\n", 2);
    if (is_playable(tab) == 0)
        return (1);
    return (0);
}

char    **parse(char **tab, int i, char *s)
{
    size_t  len;
    int     j;

    len = ft_strlen(s);
    tab[i] = malloc((len + 1) * sizeof(char));
    if (tab[i] == NULL)
        return (free_tab(tab), NULL);
    while (s[j])
    {
        tab[i][j] = s[j];
        j ++;
    }
    tab[i][j] = '\0';
    return (tab);
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
    i = count_lines(argv[1]); // comme deja ouvert, quand reouvre, reprend la ou il en etait au lieu de reprendre du debut.......fseek pas autorise.
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
        tab = parse(tab, i, line);
        ft_printf("%s\n", line);
        i ++;
    }
    tab[i +1] = NULL;
    close(file_descriptor);
    ft_printf("%d, %s\n", i, tab[0]);
    len = ft_strlen(tab[0]);
    if (is_map_invalid(tab, i, len) == 1)
    {
        ft_printf("Error : map invalid.");
        return (free_tab(tab), 0);
    }

    /*file_descriptor = open(argv[1], O_RDONLY);
    if (file_descriptor < 0)
        return (0);
    i = 0;
    j = 0;
    while (1)
    {
        line = get_next_line(file_descriptor);
        if (line == NULL)
            break;
        if (i == 0)
        {
            while (line[j])
            {
                if (line[j] != 1)
                    write_error_and_exit();
                j ++;
            }
        }
        else
        {

        }
        i ++;
    }
    close(file_descriptor);*/
}