#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>  
#include <matrix.h>

typedef struct 
{
    const char* title;
    int width;
    int height;
    SDL_Window* window;
    SDL_Surface* current_surface;
    SDL_Surface* buffer_surface;
    Matrix matrix;
}Window;

Window createWindow(const char* title,int width,int height);
void startWindow(Window* obj);
void updateBufferSurface(Window* obj);
void updateCurrentSurface(Window* obj);
void updateWindowSurface(Window* obj);
void closeWindow(Window* obj);




#endif
