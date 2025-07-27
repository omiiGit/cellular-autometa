#ifndef CELL_H
#define CELL_H

#include <SDL2/SDL.h>
#include "macro.h"


#define NODE(type)\
    typedef struct Node_##type\
    {\
        struct Node_##type* next;\
        struct Node_##type* prev;\
        type data;\
    }Node_##type;\

#define LIST(type)\
    typedef struct\
    {\
        struct Node_##type frist;\
        struct Node_##type head;\
        int count;\
    }List_##type;\





#define CREATE_NODE(type)\
    (Node_##type)\
    {\
        .next = NULL,\
        .prev = NULL,\
    }\

#define CREATE_LIST(type)\
    (List_##type)\
    {\
        .frist = CREATE_NODE(type),\
        .head = CREATE_NODE(type),\
        .count = 0,\
    }\


#define ADD_LIST(type,list,data)\
  do{\
       \
    }\

typedef struct 
{
    int x_pos;
    int y_pos;
    int velocity;
}Cell;

NODE(Cell);
LIST(Cell);

NODE(int);
LIST(int);

Cell createCell(int x,int y,int v);
void drawCell(Cell* s_cell,SDL_Surface* surface,int x,int y);
void updateCellPos(Cell* obj,SDL_Surface* surface,int x,int y);


#endif 
