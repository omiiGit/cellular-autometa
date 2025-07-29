#include <stdio.h>
#include <SDL2/SDL.h>
#include "Macro.h"
#include "utils.h"
#include "matrix.h" 
#include "window.h"

int main()
{

    /*const char* title = "AUTOMATA";
    Window window = createWindow(
            title,
            SCREEN_WIDTH,
            SCREEN_HEIGHT
            );

    GET_WINDOW_DETAILS;

    startWindow(&window);
    updateWindowSurface(&window);
    closeWindow(&window);*/ 


    Matrix matrix = createMatrix();
    int x = 2;
    int y = 1;
    initMatrix(&matrix);
    setCell(&matrix,x,y);
    setCell(&matrix,0,4);
    setCell(&matrix,0,6);

    printMatrix(&matrix);
    updateCells(&matrix);
    printf("\n");
    printMatrix(&matrix);

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
    Vec2 vec = {2,1};
    if(isVec2inList(&vec,&vecList))
        printf("Vec is present");
    else
        printf("Vec is absent");*/

    
    return 0;
}
