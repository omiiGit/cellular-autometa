#ifndef MATRIX_H
#define MATRIX_H

#include "macro.h"
#include <SDL2/SDL.h>

typedef struct 
{
    int x_pos;
    int y_pos;
    int velocity;
}Cell;

typedef struct 
{
    Cell s_cell;
    //int matrix[ROWS * COLUMNS];
    int* matrix;
}Matrix;

Cell createCell(int x,int y,int v);

void initMatrix(Matrix* matrix,int x,int y);
void drawCell(Matrix* matrix,SDL_Surface* surface,int x,int y);
void printMatrix(Matrix* matrix);
void updateCellPos(Matrix* obj,SDL_Surface* surface,int x,int y);

#endif 
