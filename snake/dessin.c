#include "include/dessin.h"


void initSegment(segment* seg, int largeur,rect* rectVertClair){

	seg->largeur = largeur;
	seg->a = (int)(0.02*seg->largeur); 	/*a = 2% de la longeuret coresond au bande noir  a droite et gauche*/
	rectVertClair->l = seg->largeur - 2*seg->a; 
	seg->b = (int)rectVertClair->l/60;
	rectVertClair->h = 40*seg->b;
	seg->hauteur = seg->a + rectVertClair->h + 5*seg->a;

	rectVertClair->x = seg->a;
	rectVertClair->y = seg->a;	
}

void initColor(color* color){

    color->jaune = CouleurParNom("yellow");
	color->noir = CouleurParNom("black");
	color->rouge = CouleurParNom("red");
	color->bleu = CouleurParNom("blue");
	color->grisBis = CouleurParComposante(118, 111, 100);
	color->blanc = CouleurParNom("white");
	color->vertClair = CouleurParComposante(141,199,63);

}

void initTimer(rect* rectNoirTimer, segment* seg,text* positionTimer, infoTimer* infoTimer,unsigned long microsecondes){

	/*---RECT NOIR DE CAHCHE---*/
    rectNoirTimer->x = seg->a;
	rectNoirTimer->y = seg->hauteur -5*seg->a;
	rectNoirTimer->l = 7*seg->b;
	rectNoirTimer->h = 5*seg->a;

	/*---AFFICHAGE TIMER---*/
	positionTimer-> x = 2*seg->a;
	positionTimer-> y = seg->hauteur - 2*seg->a;
	sprintf(positionTimer->string, "%02d:%02d",0,0);

	/*---INFO COMPLEMENTAIRE---*/
	infoTimer->compteurMicrosec = microsecondes + CYCLE;
	infoTimer->compteurSec = 0;

	infoTimer->compteurMicrosecVitesse = microsecondes;
	infoTimer->acceleration = ACCELERATION_SNAKE;
	infoTimer->compteurVitesse = 1;

}

void initScore(rect* rectNoirScore, segment* seg,text* positionScore){

	/*---RECT NOIR DE CAHCHE---*/
    rectNoirScore->x = seg->largeur - 9*seg->a;
	rectNoirScore->y = seg->hauteur -5*seg->a;
	rectNoirScore->l = 9*seg->a;
	rectNoirScore->h = 5*seg->a;

	/*---AFFICHAGE TIMER---*/
	positionScore-> x = seg->largeur - 8*seg->a;
	positionScore-> y = seg->hauteur - 2*seg->a;
	sprintf(positionScore->string, "0000000");

}

void initfenetre(color* color, rect* rectVertClair, segment* seg,text* positionTimer,text* positionScore){

    /*-------------CREATION FENETRE----------------------*/

    InitialiserGraphique();
	CreerFenetre(400,150,seg->largeur,seg->hauteur);
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
	ChoisirCouleurDessin(color->blanc);
    EcrireTexte(positionScore->x,positionScore->y,positionScore->string,2);

}

void initAffichageSnake(body* body,position* pos, color* color,segment* seg){

	int i, j;
    initCursor(body); 

	for (i = 0; i < INIT_SNAKE_SIZE; i++){
		*pos = getCursor(body);
		ChoisirCouleurDessin(color->jaune);
		RemplirRectangle(seg->a + ((int)pos->m_X)*(seg->b), seg->a + ((int)pos->m_Y)*(seg->b) ,  seg->b,  seg->b );
		cursorNext(body);
   	}

}

void afficherSnake(body* body,position* pos, color* color,segment* seg, grid*  grid,int *sensDeplacement, int* score, int* startGo){

	int t, i;
	int indicateur = 0;
	position savePos; /*sauvegarde la queu*/	
	
	initCursor(body);				/*|*/
	savePos = getCursor(body);		/*| met le curseur sur la queu*/ 
		
	if(ToucheEnAttente() == 1){
		t = Touche();

		if(t == XK_space){
			pause();
			indicateur = 1;
		}else if(t == XK_Escape){
			indicateur = 1;
			*startGo = STOP;
		}else if(t == XK_Left && *sensDeplacement != DROITE){
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
		}else{
			fonctionSensDeplacement(pos,*sensDeplacement);
		}

	}else{
		fonctionSensDeplacement(pos,*sensDeplacement);
	}

	if(getValue(grid,*pos) == APPLE ){

		setValue(grid,*pos, GRASS);
		affichagePomme(color,seg,grid);
		*score += SCORE_PAR_POMME;
	
		for(i=0 ; i<ALLONGEMENT_SNAKE; i++){

		setValue(grid,*pos, GRASS);
		enqueue(body, *pos);
		setValue(grid, *pos, (unsigned char)SNAKE);
		ChoisirCouleurDessin(color->vertClair);
		RemplirRectangle(seg->a + ((int)savePos.m_X)*(seg->b), seg->a + ((int)savePos.m_Y)*(seg->b) ,  seg->b,  seg->b ); /*queu*/

		ChoisirCouleurDessin(color->jaune);
		RemplirRectangle(seg->a + ((int)pos->m_X)*(seg->b), seg->a + ((int)pos->m_Y)*(seg->b) ,  seg->b,  seg->b ); 	/*tete*/

		}

		
	}else if ( getValue(grid,*pos) == SNAKE && indicateur != 1){
		exitFunction(startGo, seg, color);
	}else if (isOutside(body)){		
		exitFunction(startGo, seg, color);
	}else if(getValue(grid,*pos) == WALL){
		exitFunction(startGo, seg, color);
	}else{
		move(grid,body, *pos); /*les coordonnés de la tête est égale a 'pos'*/
		ChoisirCouleurDessin(color->vertClair);
		RemplirRectangle(seg->a + ((int)savePos.m_X)*(seg->b), seg->a + ((int)savePos.m_Y)*(seg->b) ,  seg->b,  seg->b ); /*queu*/

		ChoisirCouleurDessin(color->jaune);
		RemplirRectangle(seg->a + ((int)pos->m_X)*(seg->b), seg->a + ((int)pos->m_Y)*(seg->b) ,  seg->b,  seg->b ); 	/*tete*/
	}

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

void initAffichagePomme(color* color, segment* seg,grid* grid){

	int i;
	position posPomme;

	for(i=0;i<NOMBRE_DE_POMME;i++){
		posPomme = spawnApple(grid);
		ChoisirCouleurDessin(color->rouge);
		RemplirRectangle(seg->a + ((int)posPomme.m_X)*(seg->b), seg->a + ((int)posPomme.m_Y)*(seg->b) ,  seg->b,  seg->b );
	}
}

void affichagePomme(color* color, segment* seg,grid* grid){

	position posPomme;
	posPomme = spawnApple(grid);
	ChoisirCouleurDessin(color->rouge);
	RemplirRectangle(seg->a + ((int)posPomme.m_X)*(seg->b), seg->a + ((int)posPomme.m_Y)*(seg->b) ,  seg->b,  seg->b );
}

void initSpawnCaillou(color* color, segment* seg,grid* grid){

	int i;
	position posCaillou;

	for(i=0;i<NOMBRE_DE_CAILLOU;i++){
		posCaillou = spawnWall(grid);
		ChoisirCouleurDessin(color->grisBis);
		RemplirRectangle(seg->a + ((int)posCaillou.m_X)*(seg->b), seg->a + ((int)posCaillou.m_Y)*(seg->b) ,  seg->b,  seg->b );
	}

}

void timer(unsigned long microsecondes, infoTimer* infoTimer,text* positionTimer,color* color,rect* rectNoirTimer){

	if (microsecondes > infoTimer->compteurMicrosec){

		infoTimer->compteurMicrosec = microsecondes + CYCLE;
		infoTimer->compteurSec++;
		sprintf(positionTimer->string, "%02d:%02d",(int)(infoTimer->compteurSec/60),infoTimer->compteurSec%60);
		ChoisirCouleurDessin(color->noir);
		RemplirRectangle(rectNoirTimer->x,rectNoirTimer->y,rectNoirTimer->l,rectNoirTimer->h);
		ChoisirCouleurDessin(color->blanc);
		EcrireTexte(positionTimer->x,positionTimer->y,positionTimer->string,2);

	}

	if (microsecondes > infoTimer->compteurMicrosecVitesse){
		infoTimer->compteurMicrosecVitesse = microsecondes + (VITESSE_SNAKE_DEMARAGE - infoTimer->acceleration);
		infoTimer->compteurVitesse++;
		infoTimer->acceleration += ACCELERATION_SNAKE;
	}


}

void affichageScore(color* color, rect* rectNoirScore, text* positionScore, int score ){

	sprintf(positionScore->string, "%07d",score);
	ChoisirCouleurDessin(color->noir);
	RemplirRectangle(rectNoirScore->x,rectNoirScore->y,rectNoirScore->l,rectNoirScore->h);
	ChoisirCouleurDessin(color->blanc);
	EcrireTexte(positionScore->x,positionScore->y,positionScore->string,2);

}

void pause(){

	int indicateur = 1;
	int t;
	while(indicateur == 1){

		if(ToucheEnAttente() == 1){
			t = Touche();
			if(t == XK_space){
			 indicateur = 0;
			}
		}

	}
}

void exitFunction(int *startGo, segment* seg, color* color){

	int indicateur = 1;
	int t;
	char string1[50] = "GAME OVER";
	char string2[50] = "press q to exit";

	int tailleString1 = TailleChaineEcran(string1,2);
	int tailleString2 = TailleChaineEcran(string2,2);

	int texteAuMilieu1 =  (int)( ( (seg->largeur) - tailleString1 ) / 2 );
	int texteAuMilieu2 =  (int)( ( (seg->largeur) - tailleString2 ) / 2 );

	ChoisirCouleurDessin(color->blanc);
	EcrireTexte(texteAuMilieu1,(int)(seg->a + 40*seg->b /2),string1,2);
	EcrireTexte(texteAuMilieu2,(int)(seg->a + 40*seg->b /2) + 2*seg->a ,string2,2);

	while(indicateur == 1){

		if(ToucheEnAttente() == 1){
			t = Touche();
			if(t == XK_q || t == XK_Q){
			 indicateur = 0;
			}
		}

	}

	*startGo = STOP;

}
