#include "include/snake.h"

void initSnakeBody(body* body)
{
    body->m_cursor = NULL;
    body->m_head = NULL;
    body->m_queue = NULL;
    body->m_size = 0;
}

int empty(body* body)
{
    if (body->m_size == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int firstEnqueue(body* body, position position)
{
    if(empty(body))
    {
        body->m_head = (element*) malloc(sizeof(element)); /* on alloue un nouvel élement pointé par la tête */
        if(body->m_head == NULL)
        {
            return ALLOC_ERROR;
        }

        body->m_queue = body->m_head; /* on pointe la queue sur cet élement (car il est unique au départ) */
        body->m_size += 1;
        setCoord(body->m_head, position);
        body->m_head->m_next = NULL; /* on initialise le pointeur de l'élement à NULL */ 
    }
    return SUCCESS;
}

int enqueue(body* body, position position)
{
    if (!empty(body))
    {
        body->m_head->m_next = (element*) malloc(sizeof(element)); /* on alloue un nouvel élement pointé par le premier élement */
        if(body->m_head->m_next == NULL)
        {
            return ALLOC_ERROR;
        }

        body->m_head = body->m_head->m_next; /* on fait pointer la tête sur le nouveau première élement */
        body->m_size += 1;
        setCoord(body->m_head, position);
        body->m_head->m_next = NULL; /* on initialise le pointeur de l'élement à NULL */
    }
    return SUCCESS;
}

void dequeue(body* body)
{
    if (!empty(body))
    {
        body->m_cursor = body->m_queue; /* on pointe le curseur sur le dernier élement */
        body->m_queue = body->m_queue->m_next; /* on pointe la queue sur l'avant dernier élement */
        free(body->m_cursor); /* on désalloue le dernier élement */
        body->m_size -= 1;
        body->m_cursor = NULL; /* on pointe le curseur sur NULL */
    }
}

void initCursor(body* body)
{
    body->m_cursor = body->m_queue; /* on pointe le curseur sur le dernier élement */
}

void cursorNext(body* body)
{
    if(body->m_cursor != NULL) 
    {
        if(body->m_cursor->m_next != NULL)
        {
            body->m_cursor = body->m_cursor->m_next; /* on pointe le curseur sur l'élement précédent celui où il se situe */
        }
    }
}

position getHead(body* body)
{
    if (body->m_head != NULL)
    {
        return body->m_head->m_position;
    }
}

position getCursor(body* body)
{
    if(body->m_cursor != NULL)
    {
        return body->m_cursor->m_position;
    }
}
void setCoord(element* Element, position position)
{
    Element->m_position = position;
}

void queueToHead(body* body, position position)
{
    if (!empty(body))
    {
        body->m_cursor = body->m_queue; /* le curseur pointe sur le dernier élement */
        body->m_queue = body->m_queue->m_next; /* la queue pointe sur l'avant dernier élement */
        body->m_head->m_next = body->m_cursor; /* le pointeur du première élement pointe sur le dernière élement*/
        body->m_head = body->m_head->m_next; /* la tête pointe sur le nouveau premier élement */
        body->m_head->m_next = NULL; /* le pointeur du premier élement est pointé sur NULL */
        body->m_cursor = NULL; /* le curseur est pointé sur NULL */
        setCoord(body->m_head, position); 
    }
}

void setHead(body* body, position position)
{
    if (body->m_head != NULL)
    {
        setCoord(body->m_head, position);
    }
}