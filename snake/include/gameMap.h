#ifndef GAMEMAP_H
#define GAMEMAP_h
#include "grid.h"
#include <time.h>

int spawnSnake(grid* grid, body* body); /* initialise le serpent au centre de la grille */

void destroySnake(body* body); /* "enlève" (free) le snake de la mémoire */

void initGameMap(grid* grid); /* initialise la grille avec la valeur pour les murs autour et le gazon au milieu */

void spawnApple(grid* grid); /* met une pomme à un endroit libre de la grille */

position RandPos(grid* grid); /* génère une position aléatoire */

#endif