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

    initMatrix(&obj->matrix,0,0);

    SDL_FillRect(obj->win_surface,NULL,BLACK);
    drawGrid(obj->win_surface);

    SDL_UpdateWindowSurface(obj->win);
}

void updateWindowSurface(Window* obj)
{
    bool quit = false;
    bool flag;
    int x_pos = obj->matrix.s_cell.x_pos;
    int y_pos = obj->matrix.s_cell.y_pos;

    while(!quit)
    {
        flag = false;
        while(SDL_PollEvent(&obj->event))
        {
            if(obj->event.type == SDL_QUIT)
            {
                quit = true;
            }
            else if(obj->event.type == SDL_KEYDOWN)
            {
                switch(obj->event.key.keysym.sym)
                {

                }
            }
            else if(obj->event.type == SDL_MOUSEBUTTONDOWN)
            {
                x_pos = (obj->event.motion.x-1)/CELL_WIDTH;
                y_pos = (obj->event.motion.y-1)/CELL_HEIGHT;
                printf("Mouse is clicked at %d-%d\n",x_pos,y_pos);
                drawCell(&obj->matrix,obj->win_surface,x_pos,y_pos);
            }
            
        }
        SDL_UpdateWindowSurface(obj->win);
        //printf("%d-%d\n",x_pos,y_pos);

        if(y_pos <= ROWS-1)
        {
            drawCell(&obj->matrix,obj->win_surface,x_pos,y_pos);
            //x_pos++;
            if(y_pos == ROWS-1)
            {
                obj->matrix.matrix[y_pos * COLUMNS + x_pos] = 1;
                printMatrix(&obj->matrix);
            }

            y_pos++;
        }

        SDL_UpdateWindowSurface(obj->win);
        SDL_Delay(100);
    }
}

void closeWindow(Window* obj)
{
    SDL_FreeSurface(obj->win_surface);
    SDL_DestroyWindow(obj->win);

    SDL_Quit();
}
