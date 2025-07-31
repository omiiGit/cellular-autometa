#include "matrix.h"
#include "Colors.h"
#include "SDL_stdinc.h"
#include "utils.h"
#include "list.h"
#include "Macro.h"

Vec2 createVec2(int x,int y)
{
    return(Vec2)
    {
        .x = x,
        .y = y,
    };
}

bool isVec2inList(Vec2* a,List* vec_list)
{
    for(int i = 0;i < vec_list->count;i++)
    {
        Vec2 vec = LIST_GET(Vec2,vec_list,i);

        if(a->x == vec.x && a->y == vec.y)
        {
            return true;
        }
    }

    return false;
}

/*Matrix createMatrix(void)
{
    return(Matrix)
    {
        .surface = NULL,
    };
}*/

void initMatrix(Matrix* matrix)
{
    for(int i = 0;i < ROWS;i++)
    {
        for(int j = 0;j < COLUMNS;j++)
        {
            matrix->arr[COLUMNS * i + j] = 0;
        }
    }
}

void drawGrid(SDL_Surface* surface,Uint32 grid_color,Uint32 background_color)
{
    SDL_Rect background = (SDL_Rect)
    {
        .x = 1,
        .y = 1,
        .w = SCREEN_WIDTH-1,
        .h = SCREEN_HEIGHT-1,
    };

    SDL_FillRect(surface,&background,background_color);

    for(int i = 1;i < ROWS ;i++)
    {
        SDL_Rect line = (SDL_Rect){.h = 1,.w = SCREEN_WIDTH,.x = 0,.y = CELL_HEIGHT*i};

        SDL_FillRect(surface,&line,grid_color);
    }

    for(int i = 1;i < COLUMNS ;i++)
    {

        SDL_Rect line = (SDL_Rect){.h = SCREEN_HEIGHT,.w = 1,.x = CELL_WIDTH*i,.y = 0};

        SDL_FillRect(surface,&line,grid_color);
    }
}

void printMatrix(Matrix* matrix)
{
    printf("    ");
    for(int i = 0;i < COLUMNS;i++)
    {
        printf("%2d",i);
    }
    printf("\n--+-");
    for(int i = 0;i < COLUMNS*2;i++)
    {
        printf("-");
    }
    printf("\n");

    for(int i = 0;i < ROWS;i++)
    {
        printf("%d | ",i);
        for(int j = 0;j < COLUMNS;j++)
        {
            printf("%2d",matrix->arr[COLUMNS * i + j]);
        }
        printf("\n");
    }
    
}

void setCell(Matrix* obj,int x,int y,State state)
{
    obj->arr[COLUMNS * y + x] = state;
    obj->arr[COLUMNS * (y+1) + x] = state;
    obj->arr[COLUMNS * y + (x+1)] = state;
    obj->arr[COLUMNS * (y+1) + (x+1)] = state;
}

void updateCells(Matrix* obj)
{
    List vectors = createList();

    for(int i = 0;i < ROWS;i++)
    {
        for(int j = 0;j < COLUMNS;j++)
        {
            Vec2 temp = {i,j};

            switch(CURRENT_CELL)
            {
                case SAND:
                    if(!isVec2inList(&temp,&vectors))
                    {
                        if(i == ROWS-1)
                        {
                            CURRENT_CELL = DEAD;
                            continue;
                        }
                        else 
                        {
                            CURRENT_CELL = VOID;
                            if(DOWN_CELL == VOID)
                            {
                                DOWN_CELL = SAND;
                                ADD_TO_LIST;
                            }
                            else if(DOWN_CELL == DEAD || DOWN_CELL == STONE || DOWN_CELL == SAND)
                            {
                                if(DOWN_RIGHT == VOID)
                                {
                                    DOWN_RIGHT = SAND;
                                    Vec2 vec = (Vec2){.x = i+1,.y=j+1};
                                    LIST_ADD(Vec2,&vectors,vec);
                                }
                                else if(DOWN_LEFT == VOID)
                                {
                                    DOWN_LEFT = SAND;
                                    Vec2 vec = (Vec2){.x = i+1,.y=j-1};
                                    LIST_ADD(Vec2,&vectors,vec);
                                }
                                else if(DOWN_CELL == STONE)
                                {
                                    CURRENT_CELL = SAND;
                                    Vec2 vec = (Vec2){.x = i+1,.y=j-1};
                                    LIST_ADD(Vec2,&vectors,vec);;
                                }
                                else 
                                {
                                    CURRENT_CELL = DEAD;
                                }
                            }
                            else
                            {
                                CURRENT_CELL = SAND;
                            }
                        }
                    }
                break;
                case DEAD:
                    
                break;
            }
        }
    }

    LIST_FLUSH(Vec2,&vectors);
}

void drawCell(SDL_Surface* surface,int x,int y,Uint32 color)
{
    SDL_Rect cell = (SDL_Rect){
        .x = x * CELL_WIDTH+1,
        .y = y * CELL_HEIGHT+1,
        .h = CELL_HEIGHT - 1,
        .w = CELL_WIDTH - 1,
    };

    SDL_FillRect(surface,&cell,color);
}

void drawMatrix(Matrix* obj,SDL_Surface* surface)
{
    for(int i = 0;i < ROWS;i++)
    {
        for(int j = 0;j < COLUMNS;j++)
        {
            if(CURRENT_CELL == SAND)
            {
                drawCell(surface,j,i,SANDY);
            }
            else if(CURRENT_CELL == DEAD)
            {
                drawCell(surface,j,i,RED);
            }
            else if(CURRENT_CELL == STONE)
            {
                drawCell(surface,j,i,BLACK);
            }
        }
    }
}

