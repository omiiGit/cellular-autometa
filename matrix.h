#ifndef MATRIX_H
#define MATRIX_H

#include <SDL2/SDL.h>

typedef struct
{
    int cell_width;
    int cell_height;
    int columns;
    int rows;
}Matrix;

Matrix createMatrix(int cell_width,int cell_height,int columns,int rows);
void drawMatrix(Matrix* obj,SDL_Surface* surface);

#endif 

