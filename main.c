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
    closeWindow(&win);

    return 0;*/

    List_int list = CREATE_LIST(int);

    //int n = 9;

    ADD_LIST(int,&list,178);
    ADD_LIST(int,&list,12);
    ADD_LIST(int,&list,17);
    ADD_LIST(int,&list,19);

    PRINT_LIST(int,&list);
    DELL_LIST(int,&list,2);
    PRINT_LIST(int,&list);

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
