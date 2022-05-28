#include "main.h"

int main(int ac, char **av)
{
    if (ac < 2) {
        printf("Usage: %s <filename>\n", av[0]);
        return (1);
    }
    char *buffer = read_file(av[1]);
    return (jacklang_entry(buffer));
}
