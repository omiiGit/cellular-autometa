#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include "matrix.h"

typedef struct
{
    const char* title;
    int width;
    int height;
    SDL_Window* win;
    SDL_Surface* win_surface;
    SDL_Event event;
    Matrix matrix;
}Window;

Window createWindow(const char* title,int width,int height);
void initWindow(Window* obj);
void drawGrid(SDL_Surface* surface);
void updateWindowSurface(Window* obj);
void closeWindow(Window* obj);

#endif 
