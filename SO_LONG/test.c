#include "includes/so_long.h"
#define COLUMN 4
#define ROW 4
#include <stdio.h>
#include <string.h>

void free_all(char **map, int row) {
    for (int i = 0; i < row; i++) {
        free(map[i]);
    }
    free(map);
}

char    **map(char *Map_Name)
{
    int     fd, bytes_read, i = 0;
    char    buffer[COLUMN + 2];
    
    char    **map = (char **)malloc(sizeof(char *) * ROW + 1);
    if(!map)
        return NULL;
    
    fd = open(Map_Name, O_RDONLY);
    if(fd < 0)
    {
        write(2, "Erro ao abrir o mapa", 20);
        exit(1);
    }
    
    i = 0;
    while(i < ROW && fd >= 0)
    {
        bytes_read = read(fd, buffer, COLUMN+2);
        if(bytes_read < 0)
        {
            return(free_all(map, i), NULL); // fazer free para as columas preenchidas
        }
        buffer[bytes_read] = '\0';
        map[i] = strdup(buffer);  // lib
        if (!map[i])
        {
            free_all(map, i);
            return NULL;
        }
        i ++;
    }
    map[i] = NULL;
    close(fd);
    return (map);
}

int main()
{
    char **map1 = map("map1.ber");

    for (size_t y = 0; y < ROW; y++)
    {
        for (size_t x = 0; x < COLUMN; x++)
        {
            printf("%c", map1[y][x]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}