#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include "font.h"
#include <matrix.h>

typedef struct 
{
    const char* title;
    int width;
    int height;
    SDL_Window* window;
    //SDL_Surface* current_surface;
    SDL_Texture* current_texture;
    SDL_Renderer* window_renderer;
    SDL_Surface* buffer_surface;
    Matrix matrix;

    State state;
    Text typeState;
    Text wTitle;
}Window;

Window createWindow(const char* title,int width,int height);
void startWindow(Window* obj);
void updateBufferSurface(Window* obj);
void updateCurrentSurface(Window* obj);
void updateWindowSurface(Window* obj);
void closeWindow(Window* obj);




#endif
