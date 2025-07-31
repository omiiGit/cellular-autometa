#ifndef MATRIX_H
#define MATRIX_H

#include <SDL2/SDL.h>
#include <stdbool.h> 
#include "Macro.h"
#include "list.h"

#define CURRENT_CELL obj->arr[COLUMNS * i + j]
#define DOWN_CELL obj->arr[COLUMNS * (i+1) + j]
#define DOWN_RIGHT obj->arr[COLUMNS * (i+1) + (j+1)]
#define DOWN_LEFT obj->arr[COLUMNS * (i+1) + (j-1)]

typedef enum 
{
    VOID = 0,
    SAND = 1,
    COLLIDE = -1,
}State;

typedef struct 
{
    int x;
    int y;
}Vec2;

typedef struct
{
    int arr[COLUMNS*ROWS];
    //SDL_Surface* surface;
}Matrix;

Vec2 createVec2(int x,int y);
bool compVec2(Vec2 a,Vec2 b);
bool isVec2inList(Vec2* a,List* vec_list);

Matrix createMatrix(void);
void initMatrix(Matrix* matrix);
void drawGrid(SDL_Surface* surface);
void printMatrix(Matrix* obj);
void setCell(Matrix* obj,int x,int y,State state);
void updateCells(Matrix* obj);
void drawCell(SDL_Surface* surface,int x,int y,Uint32 color);
void drawMatrix(Matrix* matrix,SDL_Surface* surface);

#endif 
