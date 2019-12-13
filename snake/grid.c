#include "include/grid.h"

void initGrid(grid* grid, unsigned char value)
{
    int i, j;
    if(value != 255)
    {
        for (i = 0; i < X_SIZE; i++)
        {
            for (j = 0; j < Y_SIZE; j++)
            {
                grid->m_grid[i][j] = value;
            }
        }
    }
}

int setValue(grid* grid, position position, unsigned char value)
{
    if (position.m_X < X_SIZE && position.m_Y < Y_SIZE && value != 255)
    {
        grid->m_grid[position.m_X][position.m_Y] = value;
        return SUCCESS;
    }
    else
    {
        return ARGUMENT_ERROR;
    }
}

unsigned char getValue(grid* grid, position position)
{
    if (position.m_X < X_SIZE && position.m_Y < Y_SIZE)
    {
        return grid->m_grid[position.m_X][position.m_Y];
    }
    else
    {
        return (unsigned char)ARGUMENT_ERROR;
    }
    
}