#include <stdio.h>
#include <SDL2/SDL.h>
#include "Macro.h"
#include "utils.h"
#include "window.h"

int main()
{
    const char* title = "AUTOMATA";
    Window window = createWindow(
            title,
            SCREEN_WIDTH,
            SCREEN_HEIGHT
            );

    GET_WINDOW_DETAILS;

    startWindow(&window);
    SDL_Delay(10000);
    
    return 0;
}
