#ifndef MATRIX_H
#define MATRIX_H

#include <SDL2/SDL.h>
#include "Macro.h"

typedef struct
{
    int arr[COLUMNS*ROWS];
    SDL_Surface* surface;
}Matrix;

Matrix creatMatrix(void);
void initMatrix(Matrix* matrix);
void drawGrid(SDL_Surface* surface);

#endif 
