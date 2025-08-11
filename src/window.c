#include <stdbool.h> 
#include "window.h"
#include "matrix.h"
#include "Colors.h"



Window createWindow(const char* title,int width,int height)
{
    return(Window)
    {
        .window = NULL,
        //.current_surface = NULL,
        .buffer_surface = NULL,
        .window_renderer = NULL,
        .current_texture = NULL,
        .title = title,
        .width = width,
        .height = height,
        .state = SAND,
    };
}

void startWindow(Window* obj)
{
    SDL_Init(SDL_INIT_VIDEO);
    
    if(TTF_Init() < 0)
    {
        printf("\nFailed to init TTF\n");
    }

    obj->window = SDL_CreateWindow(
            obj->title,
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            obj->width,
            obj->height,
            SDL_WINDOW_SHOWN
            );

    //obj->current_surface = SDL_GetWindowSurface(obj->window);
    obj->window_renderer = SDL_CreateRenderer(obj->window,-1,SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(obj->window_renderer,255,255,255,0);
     
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
    obj->typeState = createText("res/acer.ttf",14,255,0,0);
    obj->wTitle = createText("res/acer.ttf",20,0,0,255);

    //SDL_FillRect(obj->current_surface,NULL,BLACK);

    SDL_UpdateWindowSurface(obj->window);
}

void updateBufferSurface(Window* obj)
{

    drawGrid(obj->buffer_surface,GREY,WHITE);
    drawMatrix(&obj->matrix,obj->buffer_surface); 


    switch(obj->state)
    {
        case SAND:
            initText(&obj->typeState,obj->buffer_surface,"SAND",20,20);
        break;
        case STONE:
            initText(&obj->typeState,obj->buffer_surface,"STONE",20,20);
        break;
        case VOID:
            initText(&obj->typeState,obj->buffer_surface,"VOID",20,20);
        break;
        case SAND_S: break;
    }
    initText(&obj->wTitle,obj->buffer_surface,"SAND AUTOMATA",180,20);

    //SDL_Surface* opt = SDL_ConvertSurface(obj->buffer_surface,obj->current_surface->format,0);

    //SDL_FreeSurface(obj->buffer_surface);
    SDL_FreeSurface(obj->typeState.fontSurface);
    SDL_FreeSurface(obj->wTitle.fontSurface);

    //return opt;
}

void updateCurrentSurface(Window* obj)
{
    //obj->buffer_surface = updateBufferSurface(obj);

    //SDL_BlitSurface(obj->buffer_surface,NULL,obj->current_surface,NULL);
    //SDL_UpdateWindowSurface(obj->window);

    updateBufferSurface(obj);
    obj->current_texture = SDL_CreateTextureFromSurface(obj->window_renderer,obj->buffer_surface);

    //SDL_RenderClear(obj->window_renderer);
    SDL_RenderCopy(obj->window_renderer,obj->current_texture,NULL,NULL);
    SDL_RenderPresent(obj->window_renderer);

    SDL_DestroyTexture(obj->current_texture);

}


void updateWindowSurface(Window* obj)
{
    bool quit = false;
    SDL_Event event;

    bool isMouseClicked = false;
    int mouseX,mouseY;
    Uint32 buttonType;

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
                        obj->state = SAND;
                        printf("Sand is selected\n");
                    break;
                    case SDLK_DOWN:
                        obj->state = STONE;
                        printf("Stone is selected\n");
                    break;
                    case SDLK_RIGHT:
                        obj->state = VOID;
                        printf("Void is selected\n");
                    break;

                }
            }
            else if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                isMouseClicked = true;
            }
            else if(event.type == SDL_MOUSEBUTTONUP)
            {
                isMouseClicked = false;
            }
        }
        

        if(isMouseClicked)
        {
            SDL_GetMouseState(&mouseX,&mouseY);
            setCell(&obj->matrix,mouseX/CELL_WIDTH,mouseY/CELL_HEIGHT,obj->state);
        }

        updateCurrentSurface(obj);
        updateCells(&obj->matrix);
        SDL_Delay(20);
    }

}

void closeWindow(Window* obj)
{
    //SDL_FreeSurface(obj->current_surface);
    SDL_FreeSurface(obj->buffer_surface);
    SDL_DestroyRenderer(obj->window_renderer);
    SDL_DestroyTexture(obj->current_texture);

    SDL_DestroyWindow(obj->window);

    SDL_Quit();
}
