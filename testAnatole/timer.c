#include<stdlib.h>
#include <stdio.h>
#include "include/timer.h"
#define CYCLE 1000000L


/*
void initRectNoirTimer(rect* rectNoirTemps, segment* segment){

    rectNoirTemps->x = segment->a;
	rectNoirTemps->y = segment->hauteur -((segment->b)-(segment->a));
	rectNoirTemps->l = segment->c;
	rectNoirTemps->h = segment->b;

	infoTimer-> xtimer = segment->a;
	infoTimer-> ytimer = segment->hauteur - (int)(segment->b/3);

}
*/

void initTimer(infoTimer* infoTimer,unsigned long Microsecondes){

	sprintf(infoTimer->stringTemps, "%02d:%02d",0,0);
    infoTimer->secBorneSup = Microsecondes + CYCLE;

}

int timer(unsigned long Microsecondes, int i,infoTimer* infoTimer){


	if (!(Microsecondes < infoTimer->secBorneSup)){

		infoTimer->secBorneSup += CYCLE;
		i++;
		sprintf(infoTimer->stringTemps, "%02d:%02d",(int)(i/60),i%60);
		/*ChoisirCouleurDessin(color->noir);
		RemplirRectangle(rectNoirTemps->x,rectNoirTemps->y,rectNoirTemps->l,rectNoirTemps->h);
		ChoisirCouleurDessin(color->blanc);
		EcrireTexte(infoTimer->xtimer,infoTimer->ytimer,infoTimer->stringTemps,2);*/
		return 1;

	}else{
		return 0;
	}


}
