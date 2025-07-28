#include <stdio.h>
#include "macro.h"
#include "window.h"
#include "matrix.h"
#include "cell.h"

void print_stats();

int main(int argc, char* argv[])
{
    /*const char* title = "CELLULAR AUTOMETA";
    Window win = createWindow(title,SCREEN_WIDTH,SCREEN_HEIGHT);
    initWindow(&win);

    print_stats();
    //printMatrix(&win.matrix);

    updateWindowSurface(&win);
    closeWindow(&win);*/

    /*List_Cell cells;
    int x,y;

    for(int i = 0,x = 0,y = 0;i < 7;i++,y++)
    {
        Cell* cell = (Cell*)malloc(sizeof(Cell));

        cell->x_pos = x;
        cell->y_pos = y;
        cell->state = DOWN;
        cell->velocity = 0;

        ADD_LIST(Cell,&cells,*cell);
    }

    int pos = 2;
    //DELL_LIST(Cell,&cells,3);

    for(int i = 0;i < cells.count;i++)
    {
        Cell* cell = GET_ITEM(Cell,&cells,i);

        printf("CELL %d= %d,%d\n",i,cell->x_pos,cell->y_pos);
    }*/ 


    return 0;
}

void print_stats()
{
    printf("SCREEN WIDTH: %d\n",SCREEN_WIDTH);
    printf("SCREEN HEIGHT: %d\n\n",SCREEN_HEIGHT);
    printf("CELL_WIDTH: %d\n",CELL_WIDTH);
    printf("CELL_HEIGHT: %d\n\n",CELL_HEIGHT);
    printf("ROWS: %d\n",ROWS);
    printf("COLUMNS: %d\n",COLUMNS);
}
