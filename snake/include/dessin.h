#ifndef DESSIN_H
#define DESSIN_H

#include<stdlib.h>
#include <stdio.h>
#include<graph.h>
#include "gameMap.h"
#define CYCLE 1000000L
#define VITESSE_SNAKE 66666L 
#define NOMBRE_DE_POMME 5
#define NOMBRE_DE_CAILLOU 8

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

}infoTimer;


void initSegment(segment* seg, int largeur, rect* rectVertClair);

void initColor(color* color);

void initTimer(rect* rectNoirTimer, segment* seg,text* positionTimer, infoTimer* infoTimer,unsigned long microsecondes);

void initScore(rect* rectNoirScore, segment* seg,text* positionScore);

void initfenetre(color* color, rect* rectVertClair, segment* seg,text* positionTimer);

void initAffichageSnake(body* body,position* pos, color* color,segment* seg);

void afficherSnake(body* body,position* pos, color* color,segment* seg, grid*  grid,int *sensDeplacement, int* score,int* startGo);

void initAffichagePomme(color* color, segment* seg,grid* grid);

void initSpawnCaillou(color* color, segment* seg,grid* grid);

void affichagePomme(color* color, segment* seg,grid* grid);

void fonctionSensDeplacement(position* pos, int sensDeplacement);

void timer(unsigned long microsecondes, infoTimer* infoTimer,text* positionTimer,color* color,rect* rectNoirTimer);

void affichageScore(color* color, rect* rectNoirScore, text* positionScore, int score );

void pause();

void exitFunction(int *startGo, segment* seg,color* color);

#endif
