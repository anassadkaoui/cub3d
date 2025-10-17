/* init_data.c */
#include <stdio.h>
#include <stdlib.h>
#include "cub3d.h"

/* Helper to convert RGB to int */
int rgb_to_int(int r, int g, int b)
{
    return (r << 16) | (g << 8) | b;
}

/* Initialize mock data */
t_data init_data(void)
{
    t_data data;

    /* --- Map --- */
    static char *grid[] = {
        "111111",
        "100001",
        "10N001",
        "100001",
        "111111",
        NULL
    };
    data.map.grid = grid;
    data.map.width = 6;
    data.map.height = 5;

    /* --- Textures --- */
    data.textures.north = "./textures/north.xpm";
    data.textures.south = "./textures/south.xpm";
    data.textures.east  = "./textures/east.xpm";
    data.textures.west  = "./textures/west.xpm";

    /* --- Colors --- */
    data.colors.floor   = rgb_to_int(220, 100, 0);  // brown
    data.colors.ceiling = rgb_to_int(100, 100, 255); // sky blue

    /* --- Player --- */
    data.player.x = 2.5;   // center of cell with 'N'
    data.player.y = 2.5;
    data.player.dir_x = 0;   /*facing North*/
    data.player.dir_y = -1;
    data.player.plane_x = 0.66; // FOV
    data.player.plane_y = 0;

    return data;
}

// /* Test printing */
// int main(void)
// {
//     t_data data = init_data();
//     printf("Map size: %dx%d\n", data.map.width, data.map.height);
//     printf("Player pos: (%f, %f)\n", data.player.x, data.player.y);
//     printf("Player dir: (%f, %f)\n", data.player.dir_x, data.player.dir_y);
//     printf("Floor color: 0x%X\n", data.colors.floor);
//     printf("Ceiling color: 0x%X\n", data.colors.ceiling);
//     return 0;
// }
