#include "include/snake.h"

int enqueue(unsigned char posX, unsigned char posY, snakeBody* body) 
{
	body->m_head->m_next = malloc(sizeof(snakePart));
	if(body->m_head->m_next == NULL) 
	{
		puts("Erreur d'allocation\n");
		return ALLOC_FAIL;
	}
	body->m_head = body->m_head->m_next;
	body->m_size += 1;
	setValues(posX, posY, body->m_head);
}

int multipleEnqueue(unsigned char posX, unsigned char posY, snakeBody* body, int nb)
{
	int i;
	body->m_head->m_next = malloc(nb * sizeof(snakePart));
	if(body->m_head->m_next == NULL) 
	{
		puts("Erreur d'allocation\n");
		return ALLOC_FAIL;
	}

	for(i = 0; i < nb-1; i++)
	{
		body->m_head = body->m_head->m_next;
		setValues(posX, posY, body->m_head);
		body->m_head->m_next = body->m_head + sizeof(snakePart);
	}

	body->m_head = body->m_head->m_next;
	body->m_size += nb;
	setValues(posX, posY, body->m_head);
}

int addFirst(unsigned char posX, unsigned char posY, snakeBody* body)
{
	body->m_head = malloc(sizeof(snakePart));
	if(body->m_head == NULL)
	{
		puts("Erreur d'allocation\n");
		return ALLOC_FAIL;
	}
	body->m_tail = body->m_head;
	body->m_size += 1;
	setValues(posX, posY, body->m_head);
}

void dequeue(snakeBody* body)
{
	body->m_buffer = body->m_tail;
	body->m_tail = body->m_tail->m_next;
	free(body->m_buffer);
	body->m_size -= 1;
}

void showSnake(snakeBody* body)
{
	int i;
	printf("%c : %c\n", body->m_tail->m_posX, body->m_tail->m_posY);
	body->m_buffer = body->m_tail->m_next;
	printf("%c : %c\n", body->m_buffer->m_posX, body->m_buffer->m_posY);
	for(i = 0; i < body->m_size - 2; i++)
	{
		body->m_buffer = body->m_buffer->m_next;
		printf("%c : %c\n", body->m_buffer->m_posX, body->m_buffer->m_posY);
	}
}

void setValues(unsigned char posX, unsigned char posY, snakePart* part)
{
	part->m_posX = posX;
	part->m_posY = posY;
}