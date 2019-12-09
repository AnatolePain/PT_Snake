#include<stdlib.h>
#include <stdio.h>
#include<graph.h>
#include "include/dessin.h"
#define LARGEUR 1000

 
int main(int argc, char * argv[]){

	int i,j,k = 0;

	segment segment;
	color color;
	rect rectVertClair;
	rect rectNoirTimer;
	text positionTimer;
	infoTimer infoTimer;

	initSegment(&segment, LARGEUR);
	initRectVertClair(&rectVertClair, &segment);
	initTimer(&rectNoirTimer, &segment,&positionTimer,&infoTimer,Microsecondes());
	initfenetre(&color,&rectVertClair,&segment,&positionTimer);

	while (True){

		timer(Microsecondes(), &infoTimer,&positionTimer,&color,&rectNoirTimer);

	}

    Touche();
    FermerGraphique();
    return EXIT_SUCCESS;

}
