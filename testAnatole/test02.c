#include<stdlib.h>
#include <stdio.h>
#include<graph.h>
#include "include/dessin.h"
#include "include/timer.h"

#define CYCLE 1000000L
#define LARGEUR 1000

 
int main(int argc, char * argv[]){

	int i,j,k = 0;


	segment segment;
	color color;
	infoTimer infoTimer;
	rect rectVertClair;
	rect rectNoirTimer;
	text positionTimer;

	initSegment(&segment, LARGEUR);
	initRectVertClair(&rectVertClair, &segment);
	initPositionTimer(&rectNoirTimer, &segment,&positionTimer);
	initTimer(&infoTimer,Microsecondes());
	initPositionTimer(&rectNoirTimer, &segment,&positionTimer);


	/*---AFFICHAGE TEMPS---*/
	/*unsigned long secBorneSup;
	char stringTemps[10];
	sprintf(stringTemps, "%02d:%02d",i,i);
	int xtimer = segment.a;
	int ytimer = segment.hauteur - (int)(segment.b/3);*/

	/*---RECT NOIR DE CAHCHE (TEMPS)---*/
	/*int xRectNoirTemps = segment.a;
	int yRectNoirTemps = segment.hauteur -(segment.b-segment.a);
	int xxRectNoirTemps = segment.c;
	int yyRectNoirTemps = segment.b;*/


	initfenetre(&color,&rectVertClair,&segment,&infoTimer,&positionTimer);
	/*EcrireTexte(xtimer,ytimer,stringTemps,2);
	secBorneSup = Microsecondes() + CYCLE;*/



	/*--------------BOUCLE WHILE DESSIN-----------------*/

	while (True){


		afficherTimer(&color,&positionTimer,&infoTimer,&rectNoirTimer,Microsecondes(), int i);

		

	}



    Touche();
    FermerGraphique();
    return EXIT_SUCCESS;

}
