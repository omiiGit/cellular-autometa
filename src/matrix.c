#include "matrix.h"
#include "Colors.h"
#include "SDL_stdinc.h"
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

void drawGrid(SDL_Surface* surface)
{
    SDL_Rect background = (SDL_Rect)
    {
        .x = 1,
        .y = 1,
        .w = SCREEN_WIDTH-1,
        .h = SCREEN_HEIGHT-1,
    };

    SDL_FillRect(surface,&background,WHITE);

    for(int i = 1;i < ROWS ;i++)
    {
        SDL_Rect line = (SDL_Rect){.h = 1,.w = SCREEN_WIDTH,.x = 0,.y = CELL_HEIGHT*i};

        SDL_FillRect(surface,&line,GREY);
    }

    for(int i = 1;i < COLUMNS ;i++)
    {

        SDL_Rect line = (SDL_Rect){.h = SCREEN_HEIGHT,.w = 1,.x = CELL_WIDTH*i,.y = 0};

        SDL_FillRect(surface,&line,GREY);
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
}

void updateCells(Matrix* obj)
{
    List vectors = createList();

    for(int i = 0;i < ROWS;i++)
    {
        for(int j = 0;j < COLUMNS;j++)
        {
            Vec2 temp = {i,j};

            int pos = COLUMNS * i + j;
            switch(obj->arr[pos])
            {
                case SAND:
                    if(!isVec2inList(&temp,&vectors))
                    {
                        if(obj->arr[COLUMNS * (i+1) + j] == COLLIDE || i == ROWS - 1)
                        {
                            obj->arr[pos] = COLLIDE;
                        }
                        else 
                        {
                            obj->arr[pos] = 0;
                            if(obj->arr[COLUMNS * (i+1) + j] != SAND)
                            {
                                obj->arr[COLUMNS * (i+1) + j] = SAND;
                                Vec2 vec = (Vec2){.x = i+1,.y=j};
                                LIST_ADD(Vec2,&vectors,vec);
                            }
                            else
                            {
                                obj->arr[COLUMNS * i + j] = SAND;
                            }
                            //Vec2 vec = (Vec2){.x = i+1,.y=j};
                            //LIST_ADD(Vec2,&vectors,vec);
                        }
                    }
                break;
                case COLLIDE:
                    
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
        .h = CELL_HEIGHT-1,
        .w = CELL_WIDTH-1,
    };

    SDL_FillRect(surface,&cell,color);
}

void drawMatrix(Matrix* matrix,SDL_Surface* surface)
{
    for(int i = 0;i < ROWS;i++)
    {
        for(int j = 0;j < COLUMNS;j++)
        {
            if(matrix->arr[COLUMNS * i + j] == SAND)
            {
                drawCell(surface,j,i,SANDY);
            }
            if(matrix->arr[COLUMNS * i + j] == COLLIDE)
            {
                drawCell(surface,j,i,RED);
            }
        }
    }
}

