#include "include/gameMap.h"
#define INIT_SNAKE_SIZE 5
#define GRASS 1
#define SNAKE 2
#define APPLE 3
#define WALL 4

int spawnSnake(grid* grid, body* body)
{
    int i;
    position pos = {(unsigned char)(X_SIZE/2), (unsigned char)(Y_SIZE/2)};

    if(firstEnqueue(body, pos))
    {
        return ALLOC_ERROR;
    }
    setValue(grid, pos, (unsigned char)SNAKE);

    for (i = 0; i < INIT_SNAKE_SIZE - 1; i++)
    {
        pos.m_X += 1;
        if(enqueue(body, pos) == ALLOC_ERROR)
        {
            return ALLOC_ERROR;
        }
        setValue(grid, pos, (unsigned char)SNAKE);
    }
}

void destroySnake(body* body)
{
    int i;
    for (i = 0; i < body->m_size - 1; i++)
    {
        dequeue(body);
    }
    free(body->m_head);
    body->m_head = NULL;
    body->m_queue = NULL;
}

void initGameMap(grid* grid)
{
    int i;
    position pos;
    initGrid(grid, (unsigned char)GRASS);

    pos.m_Y = 0;
    for(i = 0; i < X_SIZE; i++)
    {
        pos.m_X = i;
        setValue(grid, pos, (unsigned char)WALL);
    }

    pos.m_Y = Y_SIZE - 1;
    for(i = 0; i < X_SIZE; i++)
    {
        pos.m_X = i;
        setValue(grid, pos, (unsigned char)WALL);
    }

    pos.m_X = 0;
    for(i = 0; i < Y_SIZE; i++)
    {
        pos.m_Y = i;
        setValue(grid, pos, (unsigned char)WALL);
    }

    pos.m_X = Y_SIZE;
    for(i = 0; i < Y_SIZE; i++)
    {
        pos.m_Y = i;
        setValue(grid, pos, (unsigned char)WALL);
    }
}

void spawnApple(grid* grid)
{
    position pos;
    while (getValue(grid, pos) != (unsigned char)GRASS)
    {
        pos = RandPos(grid);
    }
    setValue(grid, pos, (unsigned char)APPLE);
}

position RandPos(grid* grid)
{
    position pos;
    srand(time(NULL));
    pos.m_X = (unsigned char)((rand() % (X_SIZE - 2)) + 1);
    pos.m_Y = (unsigned char)((rand() % (Y_SIZE - 2)) + 1);
    return pos;
}