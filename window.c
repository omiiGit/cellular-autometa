#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "macro.h"
#include "matrix.h"
#include "string.h"
#include "window.h"

Window createWindow(const char* title,int width,int height)
{
    SDL_Init(SDL_INIT_VIDEO);

    return(Window)
    {
        .width = width,
        .height = height,
        .win = NULL,
        .win_surface = NULL,
        .title = strdup(title),
    };
}

void drawGrid(SDL_Surface* surface)
{
    for(int i = 0;i < ROWS;i++)
    {
        SDL_Rect line = {0,i * CELL_HEIGHT,SCREEN_WIDTH,1};
        SDL_FillRect(surface,&line,GREY);
    }

    for(int i = 0;i < COLUMNS;i++)
    {
        SDL_Rect line = {i * CELL_WIDTH,0,1,SCREEN_HEIGHT};
        SDL_FillRect(surface,&line,GREY);
    }
}

void initWindow(Window* obj)
{
    obj->win = SDL_CreateWindow(
            obj->title,
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            obj->width,
            obj->height,
            SDL_WINDOW_SHOWN
            );

    obj->win_surface = SDL_GetWindowSurface(obj->win);

    initMatrix(&obj->matrix);

    SDL_FillRect(obj->win_surface,NULL,BLACK);
    drawGrid(obj->win_surface);
    drawCell(&obj->matrix,obj->win_surface);

    SDL_UpdateWindowSurface(obj->win);
}

void updateWindowSurface(Window* obj)
{
    bool quit = false;

    while(!quit)
    {
        while(SDL_PollEvent(&obj->event))
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
