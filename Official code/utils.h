#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifndef utils
#define utils

typedef struct location {
    int poz_x, poz_y;
} location;

typedef struct building {
    location poz;
    int latency_weight, connction_weight;
} building;

typedef struct antenna {
    int range;
    int connection_speed;
    int id;
} antenna;

typedef struct grid {
    int width, height, num_builds, num_ant, reward;
    building *builds;
    antenna *antennas;
    int **matrix;
} grid;

//Implemented functions
grid *read_data (FILE *, grid *);
grid *ant_sort (grid *);

#endif