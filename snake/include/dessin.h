#ifndef DESSIN_H
#define DESSIN_H

#include<stdlib.h>
#include <stdio.h>
#include<graph.h>
#include "gameMap.h"
#define CYCLE 1000000UL
#define VITESSE_SNAKE_DEMARAGE 75000UL 
#define ACCELERATION_SNAKE 15UL
#define NOMBRE_DE_POMME 5
#define NOMBRE_DE_CAILLOU 8
#define ALLONGEMENT_SNAKE 2
#define SCORE_PAR_POMME 5

#define HAUT 8
#define BAS 2
#define GAUCHE 4
#define DROITE 6
#define STOP 1

typedef struct segment{

    int largeur;
    int hauteur;
    int a;
    int b;
    
}segment;

typedef struct color{

 int noir;
 int jaune; 
 int rouge;
 int bleu;
 int grisBis;
 int vertClair;
 int blanc;

}color;

typedef struct rect{

 int x;
 int y; 
 int l;
 int h;

}rect;

typedef struct text{

    int x;
    int y;
    char string[30];
    int taille;

}text;

typedef struct infoTimer{

 int compteurSec;
 int compteurVitesse;
 unsigned long microsecondes;
 unsigned long compteurMicrosec;
 unsigned long compteurMicrosecVitesse;
 unsigned long acceleration;

}infoTimer;


/*calcule les segment nécessaire au placement des differentes formes en fonction de la longeur, 
permet d'avoir en fonction de la longeur un hauteur permetant des carré de coté b*/
void initSegment(segment* seg, int largeur, rect* rectVertClair); 

/*calcule les couleur par composante et par noms a l'avance"*/
void initColor(color* color);

/*calcule le placement du timer selon les segments et differente inforation nécessaire au timer et a la vitesse*/
void initTimer(rect* rectNoirTimer, segment* seg,text* positionTimer, infoTimer* infoTimer,unsigned long microsecondes);

/*calcule le placement du timer et la string 000000*/
void initScore(rect* rectNoirScore, segment* seg,text* positionScore);

/*initialise la fenetre + affiche le score et le temps a 0 pour eviter de les voir apparaitre ensuite + affichage rectangle vert*/
void initfenetre(color* color, rect* rectVertClair, segment* seg,text* positionTimer,text* positionScore);

/*crée et affiche les pommes sur la map*/
void initAffichagePomme(color* color, segment* seg,grid* grid);

/*crée et affiche les caillou sur la map*/
void initSpawnCaillou(color* color, segment* seg,grid* grid);

/*affiche snake au millieu*/
void initAffichageSnake(body* body,position* pos, color* color,segment* seg);

/*fonction qui gère les touches et reagis en fonction des obstacle rencontrer */
void afficherSnake(body* body,position* pos, color* color,segment* seg, grid*  grid,int *sensDeplacement, int* score,int* startGo);

/*fait avancé le nake(de 1) en fonction de la direction choisi*/
void fonctionSensDeplacement(position* pos, int sensDeplacement);

/*affiche une pommes*/
void affichagePomme(color* color, segment* seg,grid* grid);

/*gère le timer et la vitesse*/
void timer(unsigned long microsecondes, infoTimer* infoTimer,text* positionTimer,color* color,rect* rectNoirTimer);

void affichageScore(color* color, rect* rectNoirScore, text* positionScore, int score );

void pause();

/*affiche le GAME OVER et propose a l'utilisateur de quitter*/
void exitFunction(int *startGo, segment* seg,color* color);

#endif
