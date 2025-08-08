#include "font.h"
#include <SDL2/SDL_ttf.h>

Text createText(const char* font_path,int font_size,Uint8 r,Uint8 g,Uint8 b)
{
    return(Text)
    {
        .font = TTF_OpenFont(font_path,font_size),
        .size = font_size,
        .color = (SDL_Color){r,g,b},
    };
}

void initText(Text* text,SDL_Surface* surface,char* string,int x,int y)
{
    text->fontSurface = TTF_RenderText_Solid(text->font,string,text->color);

    SDL_Rect vec = {x,y};

    SDL_BlitSurface(text->fontSurface,NULL,surface,&vec);
}
