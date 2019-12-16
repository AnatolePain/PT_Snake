#include<stdlib.h>
#include <stdio.h>
#include<graph.h>
#include "include/dessin.h"
#include "include/gameMap.h"
#define LARGEUR 1000

 
int main(int argc, char * argv[]){

	int i,j,k = 0;
	int sensDeplacement = DROITE;
	int score = 0;
	int startGo = 0;
	int indicateur2 = 0;
	srand(time(NULL));

	/*--------------------------PARTIE B---------------------------*/
    body body;
    grid grid;
	position pos;

	/*---------------------------PARTIE A---------------------------*/

	segment seg;
	color color;
	rect rectVertClair;
	rect rectNoirTimer;
	rect rectNoirScore;
	text positionTimer;
	text positionScore;
	infoTimer infoTimer;

	/*--------------------------PARTIE B---------------------------*/

	initSnakeBody(&body);
	initGrid(&grid, (unsigned char)GRASS);
	
    if(spawnSnake(&grid,&body) == ALLOC_ERROR)
    {
    	perror("erreur d'allocation\n");
    	return EXIT_FAILURE;
    }
    pos.m_X = (unsigned char)(X_SIZE/2);
    pos.m_Y = (unsigned char)(Y_SIZE/2);
	pos = getHead(&body);
	
	/*---------------------------PARTIE A---------------------------*/

	initSegment(&seg, LARGEUR,&rectVertClair);
	initTimer(&rectNoirTimer, &seg,&positionTimer,&infoTimer,Microsecondes());
	initScore(&rectNoirScore,&seg,&positionScore);
	initfenetre(&color,&rectVertClair,&seg,&positionTimer);
	initAffichageSnake(&body,&pos,&color,&seg);
	initAffichagePomme(&color, &seg,&grid);
	initSpawnCaillou(&color, &seg,&grid);


	/*---------------BOUCLE WHILE DESSIN------------*/

	while (startGo != STOP ){

	    timer(Microsecondes(), &infoTimer,&positionTimer,&color,&rectNoirTimer);

	
		if(infoTimer.compteurVitesse > i){

			afficherSnake(&body,&pos,&color,&seg,&grid,&sensDeplacement,&score,&startGo,&indicateur2);
			affichageScore(&color, &rectNoirScore, &positionScore,score);
			i = infoTimer.compteurVitesse;


		}

		ChoisirCouleurDessin(color.rouge);
	}

	for (i = 0; i < Y_SIZE; i++)
	{
		for (j = 0; j < X_SIZE; j++)
		{
			pos.m_X = j;
			pos.m_Y = i;
			printf("%hhd|", getValue(&grid, pos));
		}
		puts("");
	}

	

	destroySnake(&body);
    FermerGraphique();
    return EXIT_SUCCESS;

}
