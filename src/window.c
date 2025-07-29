#include <stdbool.h> 
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

void updateBufferSurface(SDL_Surface* surface)
{
    drawGrid(surface);
}

void updateCurrentSurface(Window* obj)
{
    SDL_BlitSurface(obj->buffer_surface,NULL,obj->current_surface,NULL);
    SDL_UpdateWindowSurface(obj->window);
}


void updateWindowSurface(Window* obj)
{
    bool quit = false;
    SDL_Event event;

    updateBufferSurface(obj->buffer_surface);

    while(!quit)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                quit = true;
            }
        }
        updateCurrentSurface(obj);
    }

}

void closeWindow(Window* obj)
{
    SDL_FreeSurface(obj->current_surface);
    SDL_FreeSurface(obj->buffer_surface);

    SDL_DestroyWindow(obj->window);

    SDL_Quit();
}
