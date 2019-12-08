#ifndef TIMER_H
#define TIMER_H

#include<stdlib.h>
#include <stdio.h>

typedef struct infoTimer{

    unsigned long secBorneSup;
	char stringTemps[10];
	
}infoTimer;


void initTimer(infoTimer* infoTimer,unsigned long Microsecondes);

int timer(unsigned long Microsecondes, int i,infoTimer* infoTimer);


#endif
