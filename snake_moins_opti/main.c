#include <stdio.h>
#include <stdlib.h>
#include "include/snake.h"

int main(int argc, char* argv[])
{
    int i;
    snake snake;
    initSnakeBody(&snake);
    position pos = {10, 2};
    
    firstEnqueue(&snake, pos);
    printf("%hhd\n", snake.m_body[snake.m_head].m_X);

    for (i = 0; i < 10; i++)
    {
        pos.m_X = i;
        pos.m_Y = i + 2;
        enqueue(&snake, pos);
    }

    initCursor(&snake);
    for (i = 0; i < 15; i++)
    {
        pos = getCursor(&snake);
        printf("(%3hhd|%3hhd , %d, %d)\n", pos.m_X, pos.m_Y, snake.m_cursor, snake.m_head);
        cursorNext(&snake);
    }
    return EXIT_SUCCESS;
}