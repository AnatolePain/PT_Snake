#include<stdlib.h>
#include <stdio.h>

#include "include/dessin.h"
#include "include/timer.h"
#include<graph.h>



void initSegment(segment* segment, int largeur){

    segment->largeur = largeur;
	segment->hauteur = (int)(0.7*largeur);

    segment->a = (int)(0.02*segment->largeur);	/*a = 2% de la largeur*/
	segment->b = (int)(0.15*segment->hauteur);	/*b =15% de la hauteur*/
	segment->c = (int)(0.15*segment->largeur);	/*c =15% de la largeur*/
}


void initColor(color* color){

    color->jaune = CouleurParNom("yellow");
	color->noir = CouleurParNom("black");
	color->rouge = CouleurParNom("red");
	color->blanc = CouleurParNom("white");
	color->vertClair = CouleurParComposante(141,199,63);

}

void initRectVertClair(rect* rect, segment* segment){

    rect->x = segment->a;
	rect-> y = segment->a;
	rect-> l = segment->largeur - 2*segment->a;
	rect-> h = segment->hauteur - segment->b;

}

void initPositionTimer(rect* rectNoirTimer, segment* segment,text* positionTimer){

	/*---RECT NOIR DE CAHCHE---*/
    rectNoirTimer->x = segment->a;
	rectNoirTimer->y = segment->hauteur -((segment->b)-(segment->a));
	rectNoirTimer->l = segment->c;
	rectNoirTimer->h = segment->b;

	/*---POSITION TIMER (affichage text)---*/
	positionTimer-> x = segment->a;
	positionTimer-> y = segment->hauteur - (int)(segment->b/3);

}


void initfenetre(color* color, rect* rectVertClair, segment* segment,infoTimer* infoTimer,text* positionTimer){

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
    EcrireTexte(positionTimer->x,positionTimer->y,infoTimer->stringTemps,2);

    /*---SCORES (A completer)---*/

}


void afficherTimer(color* color,text* positionTimer,infoTimer* infoTimer, rect* rectNoirTimer,unsigned long microsecondes, int i){

	if(timer(microsecondes,i,infoTimer) == 1){
	ChoisirCouleurDessin(color->noir);
	RemplirRectangle(rectNoirTimer->x,rectNoirTimer->y,rectNoirTimer->l,rectNoirTimer->h);
	ChoisirCouleurDessin(color->blanc);
	EcrireTexte(positionTimer->x,positionTimer->y,infoTimer->stringTemps,2);
	}


}


