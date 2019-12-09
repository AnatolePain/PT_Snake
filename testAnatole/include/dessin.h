#ifndef DESSIN_H
#define DESSIN_H
#include<stdlib.h>
#include <stdio.h>

typedef struct segment{

    int largeur;
    int hauteur;
    int a;
    int b;
    int c;
    
}segment;

typedef struct color{

 int noir;
 int jaune; 
 int rouge;
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
 unsigned long microsecondes;
 unsigned long compteurMicrosec;

}infoTimer;


void initSegment(segment* segment, int largeur);

void initColor(color* color);

void initRectVertClair(rect* rect, segment* segment);

void initTimer(rect* rectNoirTimer, segment* segment,text* positionTimer, infoTimer* infoTimer,unsigned long microsecondes);

void initfenetre(color* color, rect* rectVertClair, segment* segment,text* positionTimer);

void timer(unsigned long microsecondes, infoTimer* infoTimer,text* positionTimer,color* color,rect* rectNoirTimer);


#endif
