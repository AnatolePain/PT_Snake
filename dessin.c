#include<stdlib.h>
#include <stdio.h>
#include "include/dessin.h"
#include<graph.h>
#define CYCLE 1000000L


void initSegment(segment* segment, int largeur,rect* rectVertClair){

	segment->largeur = largeur;
	segment->a = (int)(0.02*segment->largeur);	/*a = 2% de la largeur*/
	rectVertClair->l = segment->largeur - 2*segment->a;
	segment->b = (int)rectVertClair->l/60;
	rectVertClair->h = 40*segment->b;
	segment->hauteur = segment->a + rectVertClair->h + 5*segment->a;

	rectVertClair->x = segment->a;
	rectVertClair->y = segment->a;	
}


void initColor(color* color){

    color->jaune = CouleurParNom("yellow");
	color->noir = CouleurParNom("black");
	color->rouge = CouleurParNom("red");
	color->blanc = CouleurParNom("white");
	color->vertClair = CouleurParComposante(141,199,63);

}

void initTimer(rect* rectNoirTimer, segment* segment,text* positionTimer, infoTimer* infoTimer,unsigned long microsecondes){

	/*---RECT NOIR DE CAHCHE---*/
    rectNoirTimer->x = segment->a;
	rectNoirTimer->y = segment->hauteur -5*segment->a;
	rectNoirTimer->l = 7*segment->b;
	rectNoirTimer->h = 5*segment->a;

	/*---AFFICHAGE TIMER---*/
	positionTimer-> x = 2*segment->a;
	positionTimer-> y = segment->hauteur - 2*segment->a;
	sprintf(positionTimer->string, "%02d:%02d",0,0);

	/*---INFO COMPLEMENTAIRE---*/
	infoTimer->compteurMicrosec = microsecondes + CYCLE;
	infoTimer->compteurSec= 0;

}

void initfenetre(color* color, rect* rectVertClair, segment* segment,text* positionTimer){

    /*-------------CREATION FENETRE----------------------*/

    InitialiserGraphique();
	CreerFenetre(400,150,segment->largeur,segment->hauteur);
	initColor(color);
    EffacerEcran(color->noir);


	/*----------------SET DEBUT FENETRE----------------*/

    /*---RECTANGLE VERT CLAIR----*/
	ChoisirCouleurDessin(color->vertClair);
	RemplirRectangle( rectVertClair->x,rectVertClair->y, rectVertClair->l, rectVertClair->h );

    /*---TIMER--*/
    ChoisirCouleurDessin(color->blanc);
    EcrireTexte(positionTimer->x,positionTimer->y,positionTimer->string,2);

    /*---SCORES (A completer)---*/

}

void timer(unsigned long microsecondes, infoTimer* infoTimer,text* positionTimer,color* color,rect* rectNoirTimer){

	if (!(microsecondes < infoTimer->compteurMicrosec)){

		infoTimer->compteurMicrosec += CYCLE;
		infoTimer->compteurSec++;
		sprintf(positionTimer->string, "%02d:%02d",(int)(infoTimer->compteurSec/60),infoTimer->compteurSec%60);
		ChoisirCouleurDessin(color->noir);
		RemplirRectangle(rectNoirTimer->x,rectNoirTimer->y,rectNoirTimer->l,rectNoirTimer->h);
		ChoisirCouleurDessin(color->blanc);
		EcrireTexte(positionTimer->x,positionTimer->y,positionTimer->string,2);

	}

}


