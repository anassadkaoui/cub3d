#include <stdio.h>
#include "cub3d.h"



int key_handler(int keycode, t_mlx *mlx_data)
{
	(void)mlx_data;
	// printf("keycode:%d\n", keycode);
    if (keycode == 65307)
        exit(0);
    return (0);
}

typedef struct s_img			/*what's the core meaning of this ??*/
{
    void    *img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
}   t_img;

void    put_pixel_to_img(t_img *img, int x, int y, int color)
{
	/*what's the core logic here ???*/
    char    *dst;

    dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(unsigned int *)dst = color;
	/*i don't return here*/
}

void    draw_floor_ceiling(t_img *img, int width, int height, int ceiling_color, int floor_color)
{
	printf("width:%d	height:%d	celling_color:0x%x	floor_color:0x%x\n", width, height, ceiling_color, floor_color);
	/*width:2160      height:3840     celling_color:0xcccccc  floor_color:0x333333*/
    int x, y;
    for (y = 0; y < height; y++)
    {
		// printf("y:%d\n", y);
        for (x = 0; x < width; x++)
        {
			// printf("x:%d\n", x);
            if (y < height / 2)
			{
                put_pixel_to_img(img, x, y, ceiling_color);
			}
            else
			{
                put_pixel_to_img(img, x, y, floor_color);
			}
        }
    }
}

int main(void)
{
    t_img   img;
    // int     width = 800;
    // int     height = 600;
    t_mlx mlx_data;

    if (init_cub3d(&mlx_data))
        return (1);

    mlx_key_hook(mlx_data.win, key_handler, &mlx_data);





























	/*
		there's the struct
		there's the function mlx_new_image
	*/
    img.img = mlx_new_image(mlx_data.mlx, mlx_data.width, mlx_data.height);
    
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	// img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);

    // draw_floor_ceiling(&img, width, height, 0xCCCCCC, 0x333333);


    mlx_loop(mlx_data.mlx);
    return 0;
}

