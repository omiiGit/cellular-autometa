#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "window.h"
#include "matrix.h"

Window createWindow(int width,int height)
{
    return(Window)
    {
        .width = width,
        .height = height,
        .win = NULL,
        .win_surface = NULL,
    };
}

void initWindow(Window* obj)
{
    SDL_Init(SDL_INIT_VIDEO);

    obj->win = SDL_CreateWindow(
            "Cellular Autometa",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            obj->width,
            obj->height,
            SDL_WINDOW_SHOWN 
            );

    obj->win_surface = SDL_GetWindowSurface(obj->win);

    SDL_FillRect(obj->win_surface,NULL,0x000000);

    SDL_UpdateWindowSurface(obj->win);
}

void updateWindow(Window* obj)
{
    drawMatrix(&obj->matrix,obj->win_surface);

    SDL_UpdateWindowSurface(obj->win);

    bool quit = false;

    while(!quit)
    {
        while(SDL_PollEvent(&(obj->event)))
        {
            if(obj->event.type == SDL_QUIT)
            {
                quit = true;
            }
        }
    }
}

void closeWindow(Window* obj)
{
    SDL_FreeSurface(obj->win_surface);
    SDL_DestroyWindow(obj->win);

    SDL_Quit();
}
