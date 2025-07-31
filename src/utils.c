#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "Macro.h" 

void getMacroDetails(void)
{
    printf("\nSCREEN_WIDTH %d\n",SCREEN_WIDTH);
    printf("SCREEN_HEIGHT %d\n",SCREEN_HEIGHT);
    printf("CELL_WIDTH %d\n",CELL_WIDTH);
    printf("CELL_HEIGHT %d\n",CELL_HEIGHT);
    printf("COLUMNS %d\n",COLUMNS);
    printf("ROWS %d\n",ROWS);
}

int getRandom(int lower,int upper)
{
    return rand() % (upper - lower + 1) + lower;
}

void foo(void)
{
    for(int i = 0;i < 10;i++)
    {
        printf("%d\n",getRandom(0,1));
    }
}
