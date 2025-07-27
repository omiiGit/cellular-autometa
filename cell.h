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
        struct Node_##type* first;\
        struct Node_##type* head;\
        int count;\
    }List_##type;\

NODE(int);
LIST(int);

#define CREATE_NODE(type)\
({\
    Node_##type* t = (Node_##type*)malloc(sizeof(Node_##type));\
    *t = (Node_##type)\
    {\
        .next = NULL,\
        .prev = NULL,\
    };\
\
    t;\
})\

#define CREATE_LIST(type)\
    (List_##type)\
    {\
        .first = CREATE_NODE(type),\
        .head = CREATE_NODE(type),\
        .count = 0,\
    }\


//#define Node Node_##type

/*#define ADD_LIST(type,list,value)\
  do{\
        Node_##type* t = (Node_##type*)malloc(sizeof(Node_##type));\
        t->next = NULL;\
        t->prev = NULL;\
        t->data = (value);\
        if((list)->count == 0)\
        {\
            (list)->head = t;\
            (list)->frist = t;\
        }\
        else\
        {\
            (list)->head->next = t;\
            t->prev = (list)->head;\
            (list)->head = t;\
        }\
        (list)->count++;\
    }while(0)\*/

#define ADD_LIST(type, list, value)                              \
    do {                                                         \
        Node_##type* t = (Node_##type*)malloc(sizeof(Node_##type)); \
        t->next = NULL;                                          \
        t->prev = NULL;                                          \
        t->data = (value);                                       \
                                                                 \
        if ((list)->count == 0) {                                \
            (list)->first = t;                                   \
            (list)->head = t;                                    \
        } else {                                                 \
            (list)->head->next = t;                              \
            t->prev = (list)->head;                              \
            (list)->head = t;                                    \
        }                                                        \
        (list)->count++;                                         \
    } while (0)

typedef struct 
{
    int x_pos;
    int y_pos;
    int velocity;
}Cell;

NODE(Cell);
LIST(Cell);

Cell createCell(int x,int y,int v);
void drawCell(Cell* s_cell,SDL_Surface* surface,int x,int y);
void updateCellPos(Cell* obj,SDL_Surface* surface,int x,int y);


#endif 
