#include "so_long.h"
#include "libft.h"

void    display_map(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        ft_printf("%s\n", tab[i]);
        i ++;
    }
    ft_printf("\n");
}
