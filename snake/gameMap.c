#include "include/gameMap.h"

int spawnSnake(grid* grid, body* body)
{
    int i;
    position pos = {(unsigned char)(X_SIZE/2), (unsigned char)(Y_SIZE/2)};

    if(firstEnqueue(body, pos) == ALLOC_ERROR)
    {
        return ALLOC_ERROR;
    }
    setValue(grid, pos, 2);

    for (i = 0; i < INIT_SNAKE_SIZE - 1; i++)
    {
        pos.m_X += 1;
        if(enqueue(body, pos) == ALLOC_ERROR)
        {
            return ALLOC_ERROR;
        }
        setValue(grid, pos, 2);
        printf(" vvv %hhd\n", getValue(grid, pos));
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

position spawnApple(grid* grid)
{
    position pos;
    while (getValue(grid, pos) != (unsigned char)GRASS)
    {
        pos = RandPos(grid);
    }
    setValue(grid, pos, (unsigned char)APPLE);
    printf("bite %hhd, %hhd ", pos.m_X, pos.m_Y);
    return pos;
}

position RandPos(grid* grid)
{
    position pos;
    pos.m_X = (unsigned char)(rand() % X_SIZE);
    pos.m_Y = (unsigned char)(rand() % Y_SIZE);
    return pos;
}

void move(grid* grid, body* body, position position)
{
    initCursor(body);
    setValue(grid,getCursor(body),(unsigned char)GRASS);
    queueToHead(body, position);
    setValue(grid, position, (unsigned char)SNAKE);
}

int isOutside(body* body)
{
	if(body->m_head->m_position.m_X < 0 || body->m_head->m_position.m_X >= X_SIZE || body->m_head->m_position.m_Y < 0 || body->m_head->m_position.m_Y >= Y_SIZE)
	{
		return TRUE;
	} else
	{
		return FALSE;
	}
}