#include "mlx/mlx.h"
#include <stdio.h>

typedef struct s_textures
{
    void    *north;
    void    *south;
    void    *east;
    void    *west;
    int     width;
    int     height;
}   t_textures;

typedef struct s_mlx
{
    void        *mlx;
    void        *win;
    int         width;
    int         height;
    t_textures  textures;
}   t_mlx;

int init_cub3d(t_mlx *mlx_data)
{
    // 1️⃣ Initialize MiniLibX
    mlx_data->mlx = mlx_init();
    if (!mlx_data->mlx)
    {
        printf("Failed to initialize MiniLibX\n");
        return (1);
    }

    // 2️⃣ Create a window
    mlx_data->width = 800;
    mlx_data->height = 600;
    mlx_data->win = mlx_new_window(mlx_data->mlx, mlx_data->width, mlx_data->height, "Cub3D World");
    if (!mlx_data->win)
    {
        printf("Failed to create window\n");
        return (1);
    }

    // 3️⃣ Load textures
    mlx_data->textures.north = mlx_xpm_file_to_image(mlx_data->mlx, "textures/north.xpm", &mlx_data->textures.width, &mlx_data->textures.height);
    mlx_data->textures.south = mlx_xpm_file_to_image(mlx_data->mlx, "textures/south.xpm", &mlx_data->textures.width, &mlx_data->textures.height);
    mlx_data->textures.east  = mlx_xpm_file_to_image(mlx_data->mlx, "textures/east.xpm",  &mlx_data->textures.width, &mlx_data->textures.height);
    mlx_data->textures.west  = mlx_xpm_file_to_image(mlx_data->mlx, "textures/west.xpm",  &mlx_data->textures.width, &mlx_data->textures.height);

    if (!mlx_data->textures.north || !mlx_data->textures.south
        || !mlx_data->textures.east || !mlx_data->textures.west)
    {
        printf("Failed to load one or more textures\n");
        return (1);
    }

    return (0); // Success
}
