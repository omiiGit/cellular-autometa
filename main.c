#include <stdio.h>
#include <SDL2/SDL.h>
#include "window.h"

#define SCREEN_HEIGHT 400
#define SCREEN_WIDTH 600

#define CELL_WIDTH 10
#define CELL_HEIGHT 10
#define COLUMNS SCREEN_WIDTH/CELL_WIDTH
#define ROWS SCREEN_HEIGHT/CELL_HEIGHT

int main()
{
    Window window = createWindow(SCREEN_WIDTH,SCREEN_HEIGHT);
    initWindow(&window);

    window.matrix = createMatrix(
            CELL_WIDTH,
            CELL_HEIGHT,
            COLUMNS,
            ROWS 
            );
    SDL_UpdateWindowSurface(window.win);

    updateWindow(&window);
    closeWindow(&window);
    
    return 0;
}

