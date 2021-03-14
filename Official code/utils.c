#include "utils.h"

void *alloc_memory_build (building *builds, int size) {
    builds = (building *) calloc (size, sizeof (building));
    if (!builds) {
        fprintf (stderr, "Memory problem\n");
        exit (-1);
    }

    return (void *)builds;
}

void *alloc_memory_antenna (antenna *antennas, int size) {
    antennas = (antenna *) calloc (size, sizeof (antenna));
    if (!antennas) {
        fprintf (stderr, "Memory problem\n");
        exit (-2);
    }

    return (void *)antennas;
}

grid *read_data (FILE *input, grid *grid_game) {
    fscanf (input, "%d %d", &(grid_game->width), &(grid_game->height));
    fscanf (input, "%d %d", &(grid_game->num_builds), &(grid_game->num_ant));
    fscanf (input, "%d", &(grid_game->reward));
    grid_game->builds = (building *)alloc_memory_build (grid_game->builds,
                                                    grid_game->num_builds);
    grid_game->antennas = (antenna *) alloc_memory_antenna (grid_game->antennas,
                                                            grid_game->num_ant);
    for (int i = 0; i < grid_game->num_builds; i++) {
        fscanf (input, "%d", &(grid_game->builds[i].poz.poz_x));
        fscanf (input, "%d", &(grid_game->builds[i].poz.poz_y));
        fscanf (input, "%d", &(grid_game->builds[i].latency_weight));
        fscanf (input, "%d", &(grid_game->builds[i].connction_weight));
    }

    for (int i = 0; i < grid_game->num_ant; i++) {
        grid_game->antennas[i].id = i;
        fscanf (input, "%d", &(grid_game->antennas[i].range));
        fscanf (input, "%d", &(grid_game->antennas[i].connection_speed));
    }

    return grid_game;
}

int cmp (const void *a, const void *b) {
    antenna *aux1 = (antenna *) a, *aux2 = (antenna *) b;
    return (aux2->connection_speed - aux1->connection_speed);
}

int cmp_2 (const void *a, const void *b) {
    building *aux1 = (building *) a, *aux2 = (building *) b;
    return (aux2->connction_weight - aux1->connction_weight); 
}

grid *ant_sort (grid *grid_game) {
    qsort (grid_game->antennas, grid_game->num_ant, sizeof (antenna), cmp);
    qsort (grid_game->builds, grid_game->num_builds, sizeof (building), cmp_2);

    return grid_game;
}