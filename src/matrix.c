#include "matrix.h"
#include "Colors.h"
#include "Macro.h"


Matrix creatMatrix(void)
{
    return(Matrix)
    {
        .surface = NULL,
    };
}

void initMatrix(Matrix* matrix)
{
    for(int i = 0;i < ROWS;i++)
    {
        for(int j = 0;j < COLUMNS;j++)
        {
            matrix->arr[COLUMNS * i + j] = 0;
        }
    }
}

void drawGrid(SDL_Surface* surface)
{
    SDL_FillRect(surface,NULL,WHITE);

    for(int i = 1;i <= ROWS-1;i++)
    {
        SDL_Rect line = (SDL_Rect){.h = 1,.w = SCREEN_WIDTH,.x = 0,.y = CELL_HEIGHT*i};

        SDL_FillRect(surface,&line,RED);
    }

    for(int i = 1;i <= COLUMNS-1;i++)
    {
        SDL_Rect line = (SDL_Rect){.h = SCREEN_HEIGHT,.w = 1,.x = CELL_WIDTH*i,.y = 0};

        SDL_FillRect(surface,&line,RED);
    }
}
