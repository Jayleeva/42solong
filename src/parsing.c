#include "libft.h"

int main(int argc, char **argv)
{
    char    *line;
    int     file_descriptor;

    if (argc != 2)
        return (0);
    file_descriptor = open(argv[1], O_RDONLY);
    while (1)
    {
        line = get_next_line(file_descriptor);
        if (line == NULL)
            break;
    }

}