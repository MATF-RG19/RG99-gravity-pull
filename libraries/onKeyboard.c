#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>

#include "onKeyboard.h"
#include "header.h"
#include "onTimer.h"


/*
    Ovde se nalaze definicje funkcije iz istoimenog .h fajla
*/

//U ovoj funkciji odredjujemo nacin ponasanja pri pritisku odredjenih tastera
void onKeyboardMove(unsigned char key, int x, int y){
	
    switch (key) {
        //Pritiskom ovog tastera izlazimo iz igre
        case 27:
            exit(0);
            break;
        //Pritiskom ovog tastera igra se aktivira    
        case 'g':
        case 'G':
        if(!gameActive){
            gameActive = 1;
            gameAcrivatedFirstTime = 1;
            glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
        }
            break;

        //Pritiskom ovog tastera igra se pauzira
        case 'p':
        case 'P':
            gameActive = 0;
            break;
        case 'r':
        case 'R':
            initialize();
            glutTimerFunc(TIMER_INTERVAL1, on_timerSpeedUp, TIMER_ID1);
            break;

        //Pritiskom ostalih karaktera se definise kretanje glavnog cikice na ekranu
        case 'w':
        if(onPlatform){
            vec.y=4+speedUpFactor*100;
            onPlatform = 0;
        }
            break;

        case 's':
            if (vec.y==-1)
                break;
                    vec.y-=1;
            break;

        case 'a':
            if (vec.x==-1)
                break;
                    vec.x-=1;
            break;

        case 'd':
            if (vec.x==1)
                break;
                    vec.x+=1;
            break;
    }
   //Forsiramo iscrtavanje ekrana
   glutPostRedisplay();
}

void onKeyboardMoveUp(unsigned char key, int x,int y){

    switch (key) {
        case 27:
            exit(0);
            break;

        case 's':
                    vec.y+=1;
            break;

        case 'a':
                    vec.x+=1;
            break;

        case 'd':
                    vec.x-=1;
            break;
    }

    //Forsiramo iscrtavanje ekrana
    glutPostRedisplay();
}