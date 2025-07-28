#ifndef CELL_H
#define CELL_H

#include <SDL2/SDL.h>
#include "macro.h"

typedef enum
{
    REST,
    DOWN,
    COLLIDE,
    DEAD,
}State;

typedef struct 
{
    int x_pos;
    int y_pos;
    int velocity;
    State state;
}Cell;

Cell createCell(int x,int y,int v);
//void drawCells(List_Cell* cells,SDL_Surface* surface,int x,int y);
//void updateCellsPos(List_Cell* cells,SDL_Surface* surface);


#endif 
