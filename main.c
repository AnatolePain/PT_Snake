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

	initSegment(&segment, LARGEUR,&rectVertClair);
	initTimer(&rectNoirTimer, &segment,&positionTimer,&infoTimer,Microsecondes());
	initfenetre(&color,&rectVertClair,&segment,&positionTimer);

	while (True){

		timer(Microsecondes(), &infoTimer,&positionTimer,&color,&rectNoirTimer);


		ChoisirCouleurDessin(color.rouge);
		RemplirRectangle(25*segment.b,26*segment.b, segment.b, segment.b );
		RemplirRectangle(15*segment.b,30*segment.b, segment.b, segment.b );

		/*for(i=;i<40;i++){

			for(j=0;j<60;j++){

			ChoisirCouleurDessin(color.rouge);
			RemplirRectangle(j*segment.b,i*segment.b, segment.b, segment.b );

			printf("test 01: j = %d et k = %d\n",j*segment.d, i*segment.d);
			printf("test 02: segment.d = %d\n",segment.d);

			}



		}*/




	}

    Touche();
    FermerGraphique();
    return EXIT_SUCCESS;

}
