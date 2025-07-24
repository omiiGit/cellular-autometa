#include <stdio.h>
#include "macro.h"
#include "window.h" 

int main(int argc, char* argv[])
{
    const char* title = "CELLULAR AUTOMETA";
    Window win = createWindow(title,SCREEN_WIDTH,SCREEN_HEIGHT);

    initWindow(&win);
    updateWindowSurface(&win);
    closeWindow(&win);

    return 0;
}
