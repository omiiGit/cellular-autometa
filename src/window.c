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
            SCREEN_WIDTH-1,
            SCREEN_HEIGHT-1,
            32,
            0,
            0,
            0,
            0
            );
    
    initMatrix(&obj->matrix);

    SDL_FillRect(obj->current_surface,NULL,BLACK);

    SDL_UpdateWindowSurface(obj->window);
}

void updateBufferSurface(Window* obj)
{
    SDL_Surface* opt = SDL_ConvertSurface(obj->buffer_surface,obj->current_surface->format,0);

    SDL_BlitSurface(opt,NULL,obj->buffer_surface,NULL);

    drawGrid(obj->buffer_surface,GREY,WHITE);
    drawMatrix(&obj->matrix,obj->buffer_surface);

    SDL_FreeSurface(opt);
}

void updateCurrentSurface(Window* obj)
{
    updateBufferSurface(obj);

    SDL_BlitSurface(obj->buffer_surface,NULL,obj->current_surface,NULL);
    SDL_UpdateWindowSurface(obj->window);
}


void updateWindowSurface(Window* obj)
{
    State state = SAND;
    bool quit = false;
    SDL_Event event;

    while(!quit)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                quit = true;
            }
            else if(event.type == SDL_KEYDOWN)
            {
                switch(event.key.keysym.sym)
                {    
                    case SDLK_UP:
                        state = SAND;
                        printf("Sand is selected\n");
                    break;
                    case SDLK_DOWN:
                        state = STONE;
                        printf("Stone is selected\n");
                    break;
                    case SDLK_RIGHT:
                        state = VOID;
                        printf("Void is selected\n");
                    break;

                }
            }
            else if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                int x_pos = event.motion.x / CELL_WIDTH;
                int y_pos = event.motion.y / CELL_HEIGHT;

                setCell(&obj->matrix,x_pos,y_pos,state);
            }
        }
        updateCurrentSurface(obj);
        updateCells(&obj->matrix);
        SDL_Delay(20);
    }

}

void closeWindow(Window* obj)
{
    SDL_FreeSurface(obj->current_surface);
    SDL_FreeSurface(obj->buffer_surface);

    SDL_DestroyWindow(obj->window);

    SDL_Quit();
}
