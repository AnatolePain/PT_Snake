#include "include/dessin.h"


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
	color->bleu = CouleurParNom("blue");
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
	infoTimer->compteurMicrosecVitesse = microsecondes + VITESSE_SNAKE;
	infoTimer->compteurSec= 0;
	infoTimer->stop = 0;

}

void initScore(rect* rectNoirScore, segment* segment,text* positionScore){

	/*---RECT NOIR DE CAHCHE---*/
    rectNoirScore->x = segment->largeur - 7*segment->a;
	rectNoirScore->y = segment->hauteur -5*segment->a;
	rectNoirScore->l = 7*segment->b;
	rectNoirScore->h = 5*segment->a;

	/*---AFFICHAGE TIMER---*/
	positionScore-> x = segment->largeur - 8*segment->a;
	positionScore-> y = segment->hauteur - 2*segment->a;
	sprintf(positionScore->string, "07d",0);

}

void initfenetre(color* color, rect* rectVertClair, segment* segment,text* positionTimer){

	int i = 0;
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

void initAffichageSnake(body* body,position* pos, color* color,segment* segment){

	int i, j;

    initCursor(body); 

	for (i = 0; i < 10; i++){
		*pos = getCursor(body);
		printf("TEST 01 %3hhd| %3hhd\n", pos->m_X, pos->m_Y);
		ChoisirCouleurDessin(color->jaune);
		RemplirRectangle(segment->a + ((int)pos->m_X)*(segment->b), segment->a + ((int)pos->m_Y)*(segment->b) ,  segment->b,  segment->b );
		cursorNext(body);
   	}


}

void afficherSnake(body* body,position* pos, color* color,segment* segment, grid*  grid,int *sensDeplacement, int* score){

	int t;

	position sauvegardePos; /*sauvegarde la queu*/	
	
	initCursor(body);
	sauvegardePos = getCursor(body);

	if(getValue(grid,*pos) == APPLE){
		setValue(grid,*pos, GRASS);
		*score += 5;
		enqueue(body, *pos);
    	
		
	}else if (getValue(grid,*pos) == SNAKE){
		printf("perdue\n");

	}else if (isOutside(body)){
		printf("perdue\n");
	}else{
		move(grid,body, *pos); /*les coordonnés de la tête est égale a 'pos'*/
	}
		
	if(ToucheEnAttente() == 1){
	t = Touche();

		if(t == XK_Left && *sensDeplacement != DROITE){
			*sensDeplacement = GAUCHE;
			fonctionSensDeplacement(pos,*sensDeplacement);
		}else if(t == XK_Right && *sensDeplacement != GAUCHE){
			*sensDeplacement = DROITE;
			fonctionSensDeplacement(pos,*sensDeplacement);
		}else if(t == XK_Up && *sensDeplacement != BAS){
			*sensDeplacement = HAUT;
			fonctionSensDeplacement(pos,*sensDeplacement);
		}else if(t == XK_Down && *sensDeplacement != HAUT){
			*sensDeplacement = BAS;
			fonctionSensDeplacement(pos,*sensDeplacement);
		}else if(t == XK_Escape){
			escape();
		}else{
			fonctionSensDeplacement(pos,*sensDeplacement);
		}

	}else{
		fonctionSensDeplacement(pos,*sensDeplacement);
	}

	

	ChoisirCouleurDessin(color->vertClair);
	RemplirRectangle(segment->a + ((int)sauvegardePos.m_X)*(segment->b), segment->a + ((int)sauvegardePos.m_Y)*(segment->b) ,  segment->b,  segment->b ); /*queu*/

	ChoisirCouleurDessin(color->jaune);
	RemplirRectangle(segment->a + ((int)pos->m_X)*(segment->b), segment->a + ((int)pos->m_Y)*(segment->b) ,  segment->b,  segment->b ); 	/*tete*/


}

void fonctionSensDeplacement(position* pos, int sensDeplacement){

	if(sensDeplacement == DROITE){
		pos->m_X++;
	}else if(sensDeplacement == GAUCHE){
		pos->m_X--;
	}else if(sensDeplacement == BAS){
		pos->m_Y++;
	}else if(sensDeplacement == HAUT){
		pos->m_Y--;
	}

}


void affichagePomme(color* color, segment* segment,grid* grid){

	int i;
	position posPomme;
	printf("\nTEST 404\n");


	for(i=0;i<NOMBRE_DE_POMME;i++){
		posPomme = spawnApple(grid);
		ChoisirCouleurDessin(color->bleu);
		RemplirRectangle(segment->a + ((int)posPomme.m_X)*(segment->b), segment->a + ((int)posPomme.m_Y)*(segment->b) ,  segment->b,  segment->b );
		printf("\nTEST 405\n");
		printf("TEST 406 %3hhd| %3hhd\n", posPomme.m_X, posPomme.m_Y);
	}
}






void timer(unsigned long microsecondes, infoTimer* infoTimer,text* positionTimer,color* color,rect* rectNoirTimer){

	if (!(microsecondes < infoTimer->compteurMicrosec)  && infoTimer->stop !=1 ){

		infoTimer->compteurMicrosec += CYCLE;
		infoTimer->compteurSec++;
		sprintf(positionTimer->string, "%02d:%02d",(int)(infoTimer->compteurSec/60),infoTimer->compteurSec%60);
		ChoisirCouleurDessin(color->noir);
		RemplirRectangle(rectNoirTimer->x,rectNoirTimer->y,rectNoirTimer->l,rectNoirTimer->h);
		ChoisirCouleurDessin(color->blanc);
		EcrireTexte(positionTimer->x,positionTimer->y,positionTimer->string,2);

	}

	if (!(microsecondes < infoTimer->compteurMicrosecVitesse)){
		infoTimer->compteurMicrosecVitesse += VITESSE_SNAKE;
		infoTimer->compteurVitesse++;
	}


}

void fonctionScore(color* color, rect* rectNoirScore, text* positionScore, int score ){

	sprintf(positionScore->string, "%07d",score);
	ChoisirCouleurDessin(color->noir);
	RemplirRectangle(rectNoirScore->x,rectNoirScore->y,rectNoirScore->l,rectNoirScore->h);
	ChoisirCouleurDessin(color->blanc);
	EcrireTexte(positionScore->x,positionScore->y,positionScore->string,2);

}

void escape(infoTimer* infoTimer){

	int t;
	int i = 1;

	
	
	while(i == 1 ){

		if(ToucheEnAttente() == 1){
			t = Touche();
			if(t == XK_Escape){
				i = 0;
			}
		}

	}


}


