#ifndef SNAKE_H
#define SNAKE_H
#include <stdio.h>
#include <stdlib.h>

#define ALLOC_FAIL -1

typedef struct snakePart
{
	unsigned char m_posX;
	unsigned char m_posY;
	struct snakePart* m_next;
}snakePart;

typedef struct 
{
	snakePart* m_head;
	snakePart* m_tail;
	snakePart* m_buffer;
	int m_size;
}snakeBody;

int enqueue(unsigned char posX, unsigned char posY, snakeBody* body);

int multipleEnqueue(unsigned char posX, unsigned char posY, snakeBody* body, int nb);

int addFirst(unsigned char posX, unsigned char posY, snakeBody* body);

void dequeue(snakeBody* body);

void setValues(unsigned char posX, unsigned char posY, snakePart* part);

void showSnake(snakeBody* body);

#endif