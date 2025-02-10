#include "so_long.h"

char **load_map(char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
        error_exit("Erro ao abrir o mapa!");

    char *line;
    char **map = malloc(sizeof(char *) * MAX_LINES);
    int i = 0;

    while ((line = get_next_line(fd))) // Lê cada linha do arquivo
    {
        map[i] = strdup(line);
        free(line);
        i++;
    }
    map[i] = NULL; // Finaliza a matriz
    close(fd);
    return map;
}
