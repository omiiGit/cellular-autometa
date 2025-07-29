#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>  

typedef struct 
{
    const char* title;
    int width;
    int height;
    SDL_Window* window;
    SDL_Surface* current_surface;
    SDL_Surface* buffer_surface;
}Window;

Window createWindow(const char* title,int width,int height);
void startWindow(Window* obj);
void updateBufferSurface(SDL_Surface* surface);
void updateCurrentSurface(Window* obj);
void updateWindowSurface(Window* obj);
void closeWindow(Window* obj);




#endif
