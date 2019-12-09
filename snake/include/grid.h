#ifndef GRID_H
#define GRID_H

#include "snake.h"
#define X_SIZE 62
#define Y_SIZE 42
#define ARGUMENT_ERROR 255;

typedef struct
{
    unsigned char m_grid[60][40];
}grid;

void initGrid(grid* grid, unsigned char value);

int setValue(grid* grid, position position, unsigned char value);

unsigned char getValue(grid* grid, position position);

#endif