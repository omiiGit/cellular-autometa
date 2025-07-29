#include "matrix.h"
#include "Colors.h"
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

Matrix createMatrix(void)
{
    return(Matrix)
    {
        .surface = NULL,
    };
}

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
    SDL_FillRect(surface,NULL,WHITE);

    for(int i = 1;i <= ROWS-1;i++)
    {
        SDL_Rect line = (SDL_Rect){.h = 1,.w = SCREEN_WIDTH,.x = 0,.y = CELL_HEIGHT*i};

        SDL_FillRect(surface,&line,RED);
    }

    for(int i = 1;i <= COLUMNS-1;i++)
    {
        SDL_Rect line = (SDL_Rect){.h = SCREEN_HEIGHT,.w = 1,.x = CELL_WIDTH*i,.y = 0};

        SDL_FillRect(surface,&line,RED);
    }
}

void printMatrix(Matrix* matrix)
{
    printf("    ");
    for(int i = 0;i < COLUMNS;i++)
    {
        printf("%d",i);
    }
    printf("\n--+-");
    for(int i = 0;i < COLUMNS;i++)
    {
        printf("-");
    }
    printf("\n");

    for(int i = 0;i < ROWS;i++)
    {
        printf("%d | ",i);
        for(int j = 0;j < COLUMNS;j++)
        {
            printf("%d",matrix->arr[COLUMNS * i + j]);
        }
        printf("\n");
    }
    
}

void setCell(Matrix* obj,int x,int y)
{
    obj->arr[COLUMNS * y + x] = 1;
}

void updateCells(Matrix* obj)
{
    List vectors = createList();

    for(int i = 0;i < COLUMNS;i++)
    {
        for(int j = 0;j < ROWS;j++)
        {
            Vec2 temp = {j,i};
            int pos = COLUMNS * i + j;

            if(obj->arr[pos] == 1 && !isVec2inList(&temp,&vectors))
            {
                obj->arr[pos] = 0;
                obj->arr[COLUMNS * (i+1) + j] = 1;

                Vec2 vec = (Vec2){.x = i+1,.y=j};
                LIST_ADD(Vec2,&vectors,vec);
            }
                
        }
    }
}
