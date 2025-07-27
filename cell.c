#include <SDL2/SDL.h>
#include "macro.h"
#include <stdio.h>
#include "cell.h"

Cell createCell(int x,int y,int v)
{
    return(Cell)
    {
        .x_pos = x,
        .y_pos = y,
        .velocity = v,
        .state = DOWN,
    };
}

void drawCells(List_Cell* cells,SDL_Surface* surface,int x,int y)
{
    Cell cell = createCell(x,y,1); 
    //Cell* cell = (Cell*)malloc(sizeof(Cell));

    //*cell = createCell(x,y,1);

    SDL_Rect cell_rect = (SDL_Rect)
    {
        .x = cell.x_pos * CELL_WIDTH+1,
        .y = cell.y_pos * CELL_HEIGHT+1,
        .h = CELL_HEIGHT-1,
        .w = CELL_WIDTH-1,
    };

    ADD_LIST(Cell,cells,cell);
    SDL_FillRect(surface,&cell_rect,RED);
}

void updateCellsPos(List_Cell* cells,SDL_Surface* surface)
{
    int k = 0;


    for(int i = 0;i < cells->count;i++)
    {
        Cell* cell = GET_ITEM(Cell,cells,i);

        if(cell->y_pos == ROWS - 1)
        {
            cell->state = COLLIDE;
            continue;
        }

        SDL_Rect cell_rect = (SDL_Rect)
        {
            .x = (cell->x_pos) * CELL_WIDTH+1,
            .y = (cell->y_pos) * CELL_HEIGHT+1,
            .h = CELL_HEIGHT-1,
            .w = CELL_WIDTH-1,
        };

        SDL_FillRect(surface,&cell_rect,WHITE);

        switch(cell->state)
        {
            case REST:
                cell->state = DOWN;
            break;
            case DOWN:
                cell->y_pos += cell->velocity;
            break;
            case COLLIDE:
                cell->state = DEAD;
            break;
            case DEAD:
                DELL_LIST(Cell,cells,i);
            break;
        }

        cell_rect.x = (cell->x_pos) * CELL_WIDTH+1,
        cell_rect.y = (cell->y_pos) * CELL_HEIGHT+1,
    
        SDL_FillRect(surface,&cell_rect,RED);
    }
}

