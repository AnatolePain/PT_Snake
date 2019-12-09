#include <stdio.h>
#include <stdlib.h>
#include "include/snake.h"

int main(int argc, char* argv[])
{
    int i;
    body body;
    position testCoord = {5, 5};
    initSnakeBody(&body);
    if(firstEnqueue(&body, testCoord) == ALLOC_ERROR)
    {
        puts("Erreur d'allocation\n");
        return EXIT_FAILURE;
    }
    for (i = 0; i < 9; i++)
    {
        testCoord.m_X = i;
        testCoord.m_Y = i *2;
        enqueue(&body, testCoord);
    }

    initCursor(&body);
    
    for (i = 0; i < 10; i++)
    {
        testCoord = getCursor(&body);
        printf(" %3hhd| %3hhd\n", testCoord.m_X, testCoord.m_Y);
        cursorNext(&body);
    }
    
    return EXIT_SUCCESS;
}