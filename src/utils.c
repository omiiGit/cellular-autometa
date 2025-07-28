#include <stdio.h>
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
