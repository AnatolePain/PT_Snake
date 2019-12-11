#include<stdlib.h>
#include <stdio.h>
#include<graph.h>
#include "include/dessin.h"
#include "include/gameMap.h"
#define LARGEUR 1000

 
int main(int argc, char * argv[]){

	int i,j,k = 0;

	/*--------------------------PARTIE B---------------------------*/
	printf("TEST 01\n");
    body body;
    grid grid;
	position pos = {0,0};

	/*---------------------------PARTIE A---------------------------*/

	segment segment;
	color color;
	rect rectVertClair;
	rect rectNoirTimer;
	text positionTimer;
	infoTimer infoTimer;


	/*--------------------------PARTIE B---------------------------*/

	printf("TEST 02\n");
	initSnakeBody(&body);
	
	printf("TEST 03\n");
    initGameMap(&grid);
    spawnSnake(&grid,&body);
	printf("TEST 04\n");

	//pos = getHead(&body);
	printf("TEST 05\n");
	initCursor(&body); 
	printf("TEST 06\n");
	
	/*---------------------------PARTIE A---------------------------*/


	initSegment(&segment, LARGEUR,&rectVertClair);
	initTimer(&rectNoirTimer, &segment,&positionTimer,&infoTimer,Microsecondes());
	initfenetre(&color,&rectVertClair,&segment,&positionTimer);
    //initAffichageSnake(body* body,position* coord);

    /*--------------------------PARTIE B---------------------------*/

    
    /*for (i = 0; i < 10; i++)
    {
        //pos = getCursor(&body);
        //printf(" %3hhd| %3hhd\n", pos.m_X, pos.m_Y);
        cursorNext(&body);
    }*/


	

   
    /*---------------------------PARTIE A---------------------------*/

	while (True){

	    timer(Microsecondes(), &infoTimer,&positionTimer,&color,&rectNoirTimer);



        /*for (i = 0; i < 10; i++){

            testCoord = getCursor(&body);
            printf(" %3hhd| %3hhd\n", testCoord.m_X, testCoord.m_Y);
            ChoisirCouleurDessin(color.jaune);
            RemplirRectangle(segment.a + (int)testCoord.m_X*segment.b, segment.a + (int)testCoord.m_Y*segment.b ,  segment.b,  segment.b );
            printf(" %d ET %3d\n", (int)testCoord.m_X, (int)testCoord.m_Y);


            cursorNext(&body);
        }*/



		ChoisirCouleurDessin(color.rouge);
		RemplirRectangle(31*segment.b,25*segment.b, segment.b, segment.b );
		RemplirRectangle(29*segment.b,45*segment.b, segment.b, segment.b );
        //RemplirRectangle(segment.a,segment.a, segment.b, segment.b );

		/*for(i=;i<40;i++){

			for(j=0;j<60;j++){

			ChoisirCouleurDessin(color.rouge);
			RemplirRectangle(j*segment.b,i*segment.b, segment.b, segment.b );

			printf("test 01: j = %d et k = %d\n",j*segment.d, i*segment.d);
			printf("test 02: segment.d = %d\n",segment.d);

			}



		}*/




	}

    Touche();
	destroySnake(&body);
    FermerGraphique();
    return EXIT_SUCCESS;

}
