#include <stdio.h>
#include "macro.h"
#include "window.h"
#include "matrix.h"

void print_stats();

int main(int argc, char* argv[])
{
    const char* title = "CELLULAR AUTOMETA";
    Window win = createWindow(title,SCREEN_WIDTH,SCREEN_HEIGHT);
    initWindow(&win);

    print_stats();
    //printMatrix(&win.matrix);

    updateWindowSurface(&win);
    closeWindow(&win);

    return 0;
}

void print_stats()
{
    printf("SCREEN WIDTH: %d\n",SCREEN_WIDTH);
    printf("SCREEN HEIGHT: %d\n",SCREEN_HEIGHT);
    printf("CELL_WIDTH: %d\n",CELL_WIDTH);
    printf("CELL_HEIGHT: %d\n",CELL_HEIGHT);
}
