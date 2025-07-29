#ifndef MACRO_H
#define MACRO_H

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 400

#define CELL_WIDTH 50
#define CELL_HEIGHT 50

#define COLUMNS SCREEN_WIDTH/CELL_WIDTH
#define ROWS SCREEN_HEIGHT/CELL_HEIGHT

#define GET_WINDOW_DETAILS \
do{\
    printf("WINDOW DETAILS\n");\
    printf("-----------------");\
    getMacroDetails();\
}while(0)\

#endif 
