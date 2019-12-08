#include "include/snake.h"

void initSnakeBody(snake* snake)
{
    snake->m_cursor = 0;
    snake->m_head = 0;
    snake->m_queue = 0;
    snake->m_size = 0;
}

int empty(snake* snake)
{
    if (snake->m_size == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int firstEnqueue(snake* snake, position coords)
{
    if(empty(snake))
    {
        snake->m_body[snake->m_head] = coords; /* place les élements de coords dans l'élement "pointé" par la tête du snake */
        snake->m_size += 1;
    }
}

int enqueue(snake* snake, position coords)
{
    if (!empty(snake))
    {
        snake->m_head = moduloMoving(snake->m_head); /* cf fonction 'moduloMoving' */

        snake->m_body[snake->m_head + 1] = coords; /* place les élements de coords dans l'élement au dessus de celui "pointé" par la tête du snake */
        snake->m_head += 1; /* déplace la tête vers le bouvel élement créé */
        snake->m_size += 1; 
    }
}

void dequeue(snake* snake)
{
    snake->m_queue = moduloMoving(snake->m_queue);
    
    if (!empty(snake))
    {
        snake->m_queue += 1; /* déplace la queue vers l'élement juste au dessus de celui qu'elle "pointe" */
        snake->m_size -= 1;
    }
}

void initCursor(snake* snake)
{
    snake->m_cursor = snake->m_queue;  /* met la valeur du curseur a celle de la queue */
}

int cursorNext(snake* snake)
{
    if (snake->m_cursor != snake->m_head)
    {
        snake->m_cursor = moduloMoving(snake->m_cursor); /* cf fonction 'moduloMoving' */

        snake->m_cursor += 1; /* déplace le curseur d'un élement */
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

position getHead(snake* snake)
{
    return snake->m_body[snake->m_head]; 
}

position getCursor(snake* snake)
{
    return snake->m_body[snake->m_cursor];
}

void setCursor(snake* snake, position coords)
{
    snake->m_body[snake->m_cursor] = coords; /* place les élements de coords dans l'élement "pointé" par le curseur */
}

void move(snake* snake, position coords)
{
    if (!empty(snake))
    {
        snake->m_head = moduloMoving(snake->m_head); /* cf fonction 'moduloMoving' */
        snake->m_queue = moduloMoving(snake->m_queue); /* cf fonction 'moduloMoving' */
        
        snake->m_head += 1; /* déplace la tête d'un élement */
        snake->m_queue += 1; /* déplace la queue d'un élement */
        snake->m_body[snake->m_head] = coords; /* place les élements de coords dans l'élement "pointé" par la tête */
    }
}

void setHead(snake* snake, position coords)
{
    if (!empty(snake))
    {
        snake->m_body[snake->m_head] = coords; /* place les élements de coords dans l'élement "pointé" par la tête */
    }
}

int moduloMoving(int indice)
{
    if (indice >= MAX_SIZE_OF_SNAKE - 1) /* vérifie si l'indice n'est pas supérieur ou égale à MAX_SIZE_OF_SNAKE */ /*- 1 si c'est le cas il met la valeur de l'indice à -1 (retour au début du tableau) */
    {
        return -1; /*- 1 si c'est le cas il retourne -1 (retour au début du tableau) pour fonctionner l'élement qui est utiliser comme indice doit également prendre la valeur renvoyé par la fonction ici -1 */
    }
    else
    {
        return indice; /* sinon la valeur de l'indice n'est pas changé */
    }
    
}