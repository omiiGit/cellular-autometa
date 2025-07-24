#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

typedef struct
{
    const char* title;
    int width;
    int height;
    SDL_Window* win;
    SDL_Surface* win_surface;
    SDL_Event event;
}Window;

Window createWindow(const char* title,int width,int height);
void initWindow(Window* obj);
void updateWindowSurface(Window* obj);
void closeWindow(Window* obj);

#endif 
