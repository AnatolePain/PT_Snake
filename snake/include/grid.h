#ifndef GRID_H
#define GRID_H

#include "snake.h"
#define X_SIZE 60
#define Y_SIZE 40
#define ARGUMENT_ERROR 255;

typedef struct
{
    unsigned char m_grid[X_SIZE][Y_SIZE];
}grid;

void initGrid(grid* grid, unsigned char value); /* initialisation de la grille */

int setValue(grid* grid, position position, unsigned char value);/* met la valeur 'value' a la 'position' donnée */

unsigned char getValue(grid* grid, position position); /* retourne se qu'il y a sur la case dont la 'position' est donné en argument (pomme, serpent, etc...) */

#endif