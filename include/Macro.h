#ifndef MACRO_H
#define MACRO_H

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define CELL_WIDTH 8
#define CELL_HEIGHT 8

#define COLUMNS SCREEN_WIDTH/CELL_WIDTH
#define ROWS SCREEN_HEIGHT/CELL_HEIGHT

#define GET_WINDOW_DETAILS \
do{\
    printf("WINDOW DETAILS\n");\
    printf("-----------------");\
    getMacroDetails();\
}while(0)\

#endif 
