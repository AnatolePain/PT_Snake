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


}text;


void initSegment(segment* segment, int largeur);

void initColor(color* color);

void initRectVertClair(rect* rect, segment* segment);

void initPositionTimer(rect* rectNoirTimer, segment* segment,text* positionTimer);

void initfenetre(color* color, rect* rectVertClair, segment* segment,infoTimer* infoTimer,text* positionTimer);

void afficherTimer(color* color,text positionTimer,infoTimer* infoTimer, rect* rectNoirTimer,unsigned long microsecondes, int i);


#endif
