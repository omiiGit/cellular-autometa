#include <stdio.h>
#include <SDL2/SDL.h>
#include "Macro.h"
#include "utils.h"
#include "matrix.h" 
#include "window.h"

int main()
{

    Matrix matrix = createMatrix();
    int x = 2;
    int y = 1;

    initMatrix(&matrix);

    /*const char* title = "AUTOMATA";
    Window window = createWindow(
            title,
            SCREEN_WIDTH,
            SCREEN_HEIGHT
            );

    GET_WINDOW_DETAILS;

    startWindow(&window);
    updateWindowSurface(&window);
    closeWindow(&window);*/ 

    setCell(&matrix,x,y);

    printMatrix(&matrix);
    
    return 0;
}
