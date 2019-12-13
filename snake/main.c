#include<stdlib.h>
#include <stdio.h>
#include<graph.h>
#include "include/dessin.h"
#include "include/gameMap.h"
#define LARGEUR 1000

 
int main(int argc, char * argv[]){

	int i,j,k = 0;
	int indicateur = 0;
	int sensDeplacement = DROITE;
	int score = 0;
	srand(time(NULL));

	/*--------------------------PARTIE B---------------------------*/
    body body;
    grid grid;
	position pos;

	/*---------------------------PARTIE A---------------------------*/

	segment segment;
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


	initSegment(&segment, LARGEUR,&rectVertClair);
	initTimer(&rectNoirTimer, &segment,&positionTimer,&infoTimer,Microsecondes());
	initScore(&rectNoirScore,&segment,&positionScore);
	initfenetre(&color,&rectVertClair,&segment,&positionTimer);


    /*---------------------------PARTIE B---------------------------*/

	initAffichageSnake(&body,&pos,&color,&segment);
	affichagePomme(&color, &segment,&grid);

	/*---------------BOUCLE WHILE DESSIN------------*/

	while (True){

	    timer(Microsecondes(), &infoTimer,&positionTimer,&color,&rectNoirTimer);

	
		if(infoTimer.compteurVitesse != indicateur && infoTimer.stop !=1){

			afficherSnake(&body,&pos,&color,&segment,&grid,&sensDeplacement,&score);
			fonctionScore(&color, &rectNoirScore, &positionScore,score);
			indicateur = infoTimer.compteurVitesse;

		}


		ChoisirCouleurDessin(color.rouge);
		RemplirRectangle(31*segment.b,25*segment.b, segment.b, segment.b );
		RemplirRectangle(29*segment.b,45*segment.b, segment.b, segment.b );
	}

    //Touche();
	destroySnake(&body);
    FermerGraphique();
    return EXIT_SUCCESS;

}
