#include "utils.h"

int main (int argc, char *argv[]) {
    if (argc != 2)
        return -1;

    grid grid_game;
    FILE *input_data;

    input_data = fopen (argv[1], "rt");
    grid_game = *read_data (input_data, &grid_game);
    grid_game = *ant_sort (&grid_game);

    FILE *output = fopen ("output.txt", "wt");
    fprintf (stdout, "%d\n", grid_game.num_ant);
    for (int i = 0; i < grid_game.num_ant; i++) {
        fprintf (stdout, "%d %d %d\n", i, grid_game.builds[i].poz.poz_x, grid_game.builds[i].poz.poz_y);
    }
    fclose (output);
    fclose (input_data);

    return 0;
}