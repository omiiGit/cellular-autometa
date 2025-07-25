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

void initMatrix(Matrix* matrix,int x,int y)
{
    matrix->s_cell = createCell(x,y,0); 

    for(int i = 0;i < ROWS;i++)
    {
        for(int j = 0;j < COLUMNS;j++)
        {
            matrix->matrix[i * COLUMNS + j] = 0;
        }
    }

    int tx = matrix->s_cell.x_pos;
    int ty = matrix->s_cell.y_pos;
    matrix->matrix[tx * COLUMNS + ty] = 1;
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

void drawCell(Matrix* matrix,SDL_Surface* surface,int x,int y)
{

    updateCellPos(matrix,surface,x,y);

    SDL_Rect cell = (SDL_Rect)
    {
        .x = (matrix->s_cell.x_pos) * CELL_WIDTH+1,
        .y = matrix->s_cell.y_pos * CELL_HEIGHT+1,
        .h = CELL_HEIGHT-1,
        .w = CELL_WIDTH-1,
    };

    SDL_FillRect(surface,&cell,RED);
}

void updateCellPos(Matrix* obj,SDL_Surface* surface,int x,int y)
{
    obj->matrix[obj->s_cell.x_pos * COLUMNS + obj->s_cell.y_pos] = 0;

    SDL_Rect cell = (SDL_Rect)
    {
        .x = (obj->s_cell.x_pos) * CELL_WIDTH+1,
        .y = (obj->s_cell.y_pos) * CELL_HEIGHT+1,
        .h = CELL_HEIGHT-1,
        .w = CELL_WIDTH-1,
    };

    SDL_FillRect(surface,&cell,BLACK);

    obj->s_cell.x_pos = x;
    obj->s_cell.y_pos = y;

    obj->matrix[obj->s_cell.x_pos * COLUMNS + obj->s_cell.y_pos] = 1;
}

