#ifndef MATRIX_H
#define MATRIX_H

#include "macro.h"
#include <SDL2/SDL.h>
#include "cell.h"

typedef struct 
{
    List_Cell cells;
    int matrix[ROWS * COLUMNS];
    //int* matrix;
}Matrix;

void initMatrix(Matrix* matrix,int x,int y);
void printMatrix(Matrix* matrix);

#endif 
