#ifndef SNAKE_H
#define SNAKE_H
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define ALLOC_ERROR -1

typedef struct 
{
    unsigned char m_X; /* position X */
    unsigned char m_Y; /* position Y*/
}position;

typedef struct snakeElement
{
    struct snakeElement* m_next; /* pointe l'élement qui le précède */
    position m_position; /* position X et Y de l'élement */ 
}snakeElement;

typedef struct 
{
    snakeElement* m_head; /* pointe le premier élement du serpent */
    snakeElement* m_queue; /* pointe le dernier élement */
    snakeElement* m_cursor; /* peut pointer un élement (initialement pointe sur NULL) */
    int m_size; /* taille du snake */
}snakeBody;

void initSnakeBody(snakeBody* body); /* initialise tout les membres de la structure de type snakeBody à NULL ou 0 */

int empty(snakeBody* body); /* Vérifie si le serpent est vide (aucun élements de corps) */

int firstEnqueue(snakeBody* body, position position); /* ajoute le première élement au serpent */

int enqueue(snakeBody* body, position position); /* ajout un élement à un serpent ayant au moins un élement */

void dequeue(snakeBody* body); /* enlève un élement à un serpent qui est composé d'au moins un élement */

void initCursor(snakeBody* body); /* place le curseur au niveau de la queue du serpent */

void cursorNext(snakeBody* body); /* déplace le curseur d'un élement */

position getHead(snakeBody* body); /* retourne les coordonnées de la tête du serpent */

position getCursor(snakeBody* body); /* retourne les coordonnée de l'élément pointé par le curseur */

void setCoord(snakeElement* Element, position position); /* détermine la position de l'élément pointé par le curseur */

void queueToHead(snakeBody* body, position position); /* passe le dernier élement en premier élement */

void setHead(snakeBody* body, position position); /* détermine la position de la tête */

#endif