#ifndef CELL_H
#define CELL_H

#include <SDL2/SDL.h>
#include "macro.h"

typedef struct 
{
    int x_pos;
    int y_pos;
    int velocity;
}Cell;

Cell createCell(int x,int y,int v);
void drawCell(Cell* s_cell,SDL_Surface* surface,int x,int y);
void updateCellPos(Cell* obj,SDL_Surface* surface,int x,int y);

#endif 
