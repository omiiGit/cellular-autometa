#ifndef FONT_H
#define FONT_H

#include <SDL2/SDL_ttf.h>

typedef struct 
{
    int x,y,size;

    TTF_Font* font;
    SDL_Color color;
    SDL_Surface* fontSurface;
    char* string;

}Text;

Text createText(const char* font_path,int font_size,Uint8 r,Uint8 g,Uint8 b);
void initText(Text* text,SDL_Surface* surface,char* string,int x,int y);

#endif 
