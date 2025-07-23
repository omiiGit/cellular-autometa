#include <SDL2/SDL.h>
#include "matrix.h"

#define WHITE 0xffffff

Matrix createMatrix(int cell_width,int cell_height,int columns,int rows)
{
    return(Matrix)
    {
        .cell_width = cell_width,
        .cell_height = cell_height,
        .columns = columns,
        .rows = rows,
    };
}

void drawMatrix(Matrix* obj,SDL_Surface* surface)
{
    SDL_Rect line = (SDL_Rect)
    {
        .h = obj->cell_height * obj->rows,
        .w = 1,
        .x = obj->cell_width,
        .y = 0,
    };

    for(int i = 0;i < obj->columns - 1;i++)
    {
        SDL_FillRect(surface,&line,WHITE);
        line.x += obj->cell_width;
    }

    line.h = 1;
    line.w = obj->cell_width * obj->columns;
    line.x = 0;
    line.y = obj->cell_height;

    for(int i = 0;i < obj->rows - 1;i++)
    {
        SDL_FillRect(surface,&line,WHITE);
        line.y += obj->cell_height;
    }
}
