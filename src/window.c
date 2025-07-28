#include <SDL2/SDL.h>
#include "window.h"
#include "matrix.h"
#include "Colors.h"



Window createWindow(const char* title,int width,int height)
{
    return(Window)
    {
        .window = NULL,
        .current_surface = NULL,
        .buffer_surface = NULL,
        .title = title,
        .width = width,
        .height = height,
    };
}

void startWindow(Window* obj)
{
    SDL_Init(SDL_INIT_VIDEO);

    obj->window = SDL_CreateWindow(
            obj->title,
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            obj->width,
            obj->height,
            SDL_WINDOW_SHOWN
            );

    obj->current_surface = SDL_GetWindowSurface(obj->window);
     
    obj->buffer_surface = SDL_CreateRGBSurface(
            0,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            32,
            0,
            0,
            0,
            0
            );

    SDL_FillRect(obj->current_surface,NULL,BLACK);

    SDL_UpdateWindowSurface(obj->window);
}

