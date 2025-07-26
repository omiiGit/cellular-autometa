#include <SDL2/SDL.h>
#include "macro.h"
#include <stdio.h>
#include "cell.h"

Cell createCell(int x,int y,int v)
{
    return(Cell)
    {
        .x_pos = x,
        .y_pos = y,
        .velocity = v,
    };
}

void drawCell(Cell* s_cell,SDL_Surface* surface,int x,int y)
{
    s_cell->x_pos = x;
    s_cell->y_pos = y;

    SDL_Rect cell = (SDL_Rect)
    {
        .x = (s_cell->x_pos) * CELL_WIDTH+1,
        .y = s_cell->y_pos * CELL_HEIGHT+1,
        .h = CELL_HEIGHT-1,
        .w = CELL_WIDTH-1,
    };

    SDL_FillRect(surface,&cell,RED);
}

void updateCellPos(Cell* s_cell,SDL_Surface* surface,int x,int y)
{
    SDL_Rect cell = (SDL_Rect)
    {
        .x = (s_cell->x_pos) * CELL_WIDTH+1,
        .y = (s_cell->y_pos) * CELL_HEIGHT+1,
        .h = CELL_HEIGHT-1,
        .w = CELL_WIDTH-1,
    };

    SDL_FillRect(surface,&cell,WHITE);

    s_cell->x_pos = x;
    s_cell->y_pos = y;

    cell.x = (s_cell->x_pos) * CELL_WIDTH+1,
    cell.y = (s_cell->y_pos) * CELL_HEIGHT+1,
    
    SDL_FillRect(surface,&cell,RED);
}

