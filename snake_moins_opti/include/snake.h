#ifndef SNAKE_H
#define SNAKE_H
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_SIZE_OF_SNAKE 2400

typedef struct
{
    unsigned char m_X; /* position en abscisse */
    unsigned char m_Y; /* position en ordonnée */
}position;

typedef struct
{
    int m_head; /* premier élement du serpent */
    int m_queue; /* dernier élement du serpent */
    int m_cursor; /* position d'un élement du snake */
    int m_size; /* taille du snake (nombre d'élements) */ 
    position m_body[2400];
}snake;

void initSnakeBody(snake* snake); /* initialise tout les membres de la structure de type snake à  0 */

int empty(snake* snake); /* Vérifie si le serpent est vide (aucun élements de corps) */

int firstEnqueue(snake* snake, position coords); /* ajoute le première élement au serpent */

int enqueue(snake* snake, position coords); /* ajout un élement à un serpent ayant au moins un élement */

void dequeue(snake* snake); /* enlève un élement à un serpent qui est composé d'au moins un élement */

void initCursor(snake* snake); /* place le curseur au niveau de la queue du serpent */

int cursorNext(snake* snake); /* déplace le curseur d'un élement */

position getHead(snake* snake); /* retourne les coordonnées de la tête du serpent */

position getCursor(snake* snake); /* retourne les coordonnée de l'élément "pointé" par le curseur */

void setCursor(snake* snake, position coords); /* détermine la position de l'élément "pointé" par le curseur */

void move(snake* snake, position coords); /* déplace le serpent d'une case (dans la mémoire) */

void setHead(snake* snake, position coords); /* détermine la position de la tête */

int moduloMoving(int indice); /* vérifie le déplacement correct du snake dans sa boucle mémoire */

#endif