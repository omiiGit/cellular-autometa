#include <stdio.h>
#include <SDL2/SDL.h>
#include "matrix.h"
#include "cell.h"
#include "macro.h" 


void initMatrix(Matrix* matrix,int x,int y)
{
    matrix->cells = CREATE_LIST(Cell); 
    //matrix->matrix = (int*)malloc(sizeof(int) * (ROWS*COLUMNS));

    for(int i = 0;i < ROWS;i++)
    {
        for(int j = 0;j < COLUMNS;j++)
        {
            matrix->matrix[i * COLUMNS + j] = 0;
        }
    }

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

