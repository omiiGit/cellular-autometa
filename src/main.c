#include <stdio.h>
#include <SDL2/SDL.h>
#include "Macro.h"
#include "time.h"
#include "utils.h"
#include "matrix.h" 
#include "window.h"

int main()
{
    srand(time(NULL));

    const char* title = "AUTOMATA";
    Window window = createWindow(
            title,
            SCREEN_WIDTH,
            SCREEN_HEIGHT
            );

    GET_WINDOW_DETAILS;
    foo();

    startWindow(&window);
    updateWindowSurface(&window);
    closeWindow(&window);

    return 0;

}

/*Matrix matrix = createMatrix();
    int x = 2;
    int y = 1;
    initMatrix(&matrix);
    setCell(&matrix,x,y);
    setCell(&matrix,1,0);
    setCell(&matrix,2,0);
    setCell(&matrix,3,0);
    setCell(&matrix,0,6);
    setCell(&matrix,3,6);

    for(int i = 0;i < 10;i++)
    {
        printMatrix(&matrix);
        updateCells(&matrix);
        printf("\n");
    }*/

/*List vecList = createList();
    for(int i = 0;i < 10;i++)
    {
        Vec2 vec = {i,0};

        LIST_ADD(Vec2,&vecList,vec);
    }
    for(int i = 0;i < 10;i++)
    {
        Vec2 vec = LIST_GET(Vec2,&vecList,i);

        printf("%d - %d\n",vec.x,vec.y);
    }

    LIST_FLUSH(Vec2,&vecList);

    for(int i = 0;i < 10;i++)
    {
        if(vecList.count != 0)
        {
            Vec2 vec = LIST_GET(Vec2,&vecList,i);
            printf("%d - %d\n",vec.x,vec.y);
        }
        else 
        {
            printf("List is empty\n");
        }
    }*/

    /*Vec2 vec = {2,1};
    if(isVec2inList(&vec,&vecList))
        printf("Vec is present");
    else
        printf("Vec is absent");*/

