typedef struct s_map						/*what's the core meaning of this ??*/
{
    char    **grid;
    int     width;
    int     height;
}   t_map;

typedef struct s_textures /*what's the core meaning of texures ???*/
{
    char    *north;
    char    *south;
    char    *east;
    char    *west;
}   t_textures;

typedef struct s_colors			/*what's the core meaning of colors*/
{
    int floor;
    int ceiling;
}   t_colors;

typedef struct s_player				/*what's the core meaning of those properties of the player ??*/
{
    double x;
    double y;
    double dir_x;
    double dir_y;
    double plane_x;
    double plane_y;
}   t_player;

/*
	what the world looks like (the map),

	what to draw on the walls (textures),

	what colors to paint the floor and sky.

	where the player is and how they see the world,
*/
typedef struct s_data
{
    t_map       map;
    t_textures  textures;
    t_colors    colors;
    t_player    player;
}   t_data;