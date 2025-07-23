#include <stdio.h>
#include <SDL2/SDL.h>
#include "window.h"

#define SCREEN_HEIGHT 400
#define SCREEN_WIDTH 600

#define CELL_WIDTH 20
#define CELL_HEIGHT 20
#define COLUMNS SCREEN_HEIGHT/CELL_HEIGHT
#define ROWS SCREEN_WIDTH/CELL_WIDTH

int main()
{
    Window window = createWindow(SCREEN_WIDTH,SCREEN_HEIGHT);

    initWindow(&window);
    updateWindow(&window);
    closeWindow(&window);
    
    return 0;
}

