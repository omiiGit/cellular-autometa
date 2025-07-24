#include <stdio.h>
#include <SDL2/SDL.h>
#include "matrix.h"
#include "macro.h" 

Cell createCell(int x,int y,int v)
{
    return(Cell)
    {
        .x_pos = x,
        .y_pos = y,
        .velocity = v,
    };
}

void initMatrix(Matrix* matrix)
{
    matrix->s_cell = createCell(5,5,0); 

    for(int i = 0;i < ROWS;i++)
    {
        for(int j = 0;j < COLUMNS;j++)
        {
            matrix->matrix[i * COLUMNS + j] = 0;
        }
    }

    int x = matrix->s_cell.x_pos;
    int y = matrix->s_cell.y_pos;
    matrix->matrix[x * COLUMNS + y] = 1;
}

void printMatrix(Matrix* matrix)
{
    printf("\n");
    for(int i = 0;i < ROWS;i++)
    {
        for(int j = 0;j < COLUMNS;j++)
        {
            printf("%d ",matrix->matrix[i * COLUMNS + j]);
        }
        printf("\n");
    }
}

void drawCell(Matrix* matrix,SDL_Surface* surface)
{
    SDL_Rect cell = (SDL_Rect)
    {
        .x = (matrix->s_cell.x_pos) * CELL_WIDTH+1,
        .y = matrix->s_cell.y_pos * CELL_HEIGHT+1,
        .h = CELL_HEIGHT-1,
        .w = CELL_WIDTH-1,
    };

    SDL_FillRect(surface,&cell,RED);
}
