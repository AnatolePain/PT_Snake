#include "include/gameMap.h"

int spawnSnake(grid* grid, body* body)
{
    int i;
    position pos = {(unsigned char)(X_SIZE/2), (unsigned char)(Y_SIZE/2)}; /* affecte à 'position' case "central" de la grille  */

    if(firstEnqueue(body, pos) == ALLOC_ERROR) /* créé le premet élément du serpent */
    {
        return ALLOC_ERROR;
    }
    setValue(grid, pos, 2);
 
    for (i = 0; i < INIT_SNAKE_SIZE - 1; i++) /* créé les 9 autres élément qui constituent la queue du serpent */
    {
        pos.m_X += 1;
        if(enqueue(body, pos) == ALLOC_ERROR)
        {
            return ALLOC_ERROR;
        }
        setValue(grid, pos, 2);
    }
}

void destroySnake(body* body) 
{
    int i;
    for (i = 0; i < body->m_size - 1; i++) /* on désalloue les éléments de la queue un part un */
    {
        dequeue(body);
    }
    free(body->m_head); /* on désalloue la tête du serpent */
    body->m_head = NULL;
    body->m_queue = NULL;
}

position spawnApple(grid* grid) 
{
    position pos;
    while (getValue(grid, pos) != (unsigned char)GRASS) /* tant que la valeur de la case générée aléatoirement n'est pas vide */
    {
        pos = RandPos(grid);
    }
    setValue(grid, pos, (unsigned char)APPLE); /* on met la case à la valeur de 'APPLE' */
    return pos; /* on renvoie la position de la pomme */
}

position spawnWall(grid* grid){

    position pos;
    while (getValue(grid, pos) != (unsigned char)GRASS){ /* tant que la valeur de la case générée aléatoirement n'est pas vide */
        pos = RandPos(grid);
    }
    
    setValue(grid, pos, (unsigned char)WALL); /* on met la case à la valeur de 'WALL' */
    return pos; /* on renvoie la position de l'obstacle' */
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
    initCursor(body); /* on place le curseur sur la queue du serpent */
    setValue(grid,getCursor(body),(unsigned char)GRASS); /* on met la valeur de la case où est situé la queue du serpent à la valeur 'GRASS' */
    queueToHead(body, position); /* on place la nouvelle tête du serpent */
    setValue(grid, position, (unsigned char)SNAKE); /* on met la valeur de la case où est situé la nouvelle tête à la valeur 'SNAKE' */
}

int isOutside(body* body)
{
	if(body->m_head->m_position.m_X < 0 || body->m_head->m_position.m_X >= X_SIZE - 1 || body->m_head->m_position.m_Y < 0 || body->m_head->m_position.m_Y >= Y_SIZE - 1)
	{
		return TRUE;
	} else
	{
		return FALSE;
	}
}