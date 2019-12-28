#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>
#include "header.h"
#include "onTimer.h"
#include "onDisplay.h"


void on_timer (int value){
    if(value != TIMER_ID)
        return;
    


    if(gameActive && !gameOver){
        x_pos +=vec.x*0.01;
        y_pos +=vec.y*0.01;
        for (int i =0; i<5; i++){
            translate[i] -=0.01;
        }

        pos.YDonjaKoordinata+= y_pos;
        pos.YGornjaKoordinata+= y_pos;
        pos.XKoordinataLeveNoge+=x_pos;
        pos.XKoordinataDesneNoge+=x_pos;

        for(int i=0; i<10; i++){
            platformPos[i].YDonjeStrane+=0.01;
            platformPos[i].YGornjeStrane+=0.01;
        }
        

        printMirko();

        //printf("%f %f\n",pos.XKoordinataDesneNoge,pos.XKoordinataLeveNoge);
        if(pos.YGornjaKoordinata>=2.05){
            gameOver = 1;
            printf("Poginuo si :)\n");
        }
        if(pos.YGornjaKoordinata<=-3.1){
            gameOver = 1;
            x_pos=-100;
            y_pos=-100;
        }

        for(int i=0; i<5; i++){
            if(platformPos[2*i].YDonjeStrane>2.25){


                int levo = i*2;
                int x = 3+levo;
                int y = 13;
                srand(time(0));

                scale[levo] = rand()%(y-x+1) + x;
                int indeks = (levo+8)%10;
                translate[i] = 8;
                
                platformPos[levo].YGornjeStrane = -translate[i] + 0.125;
                platformPos[levo].YDonjeStrane = -translate[i] - 0.125;

                platformPos[levo+1].YGornjeStrane = -translate[i] + 0.125;
                platformPos[levo+1].YDonjeStrane = -translate[i] - 0.125;

                scale[levo+1] = rand()%(y-x+2) + x+1;
                

                double xDesno = (0.5*scale[i])/2;

                platformPos[levo].XLeveIvice = -2.5;
                platformPos[levo].XdesneIvice = -2.5 + xDesno;

                platformPos[levo+1].XdesneIvice = 4.5;
                platformPos[levo+1].XLeveIvice = 4.5 -xDesno;

            }
        }
        
        vec.y -=0.1;
        //printf("%f %f\n",pos.YDonjaKoordinata, pos.YGornjaKoordinata);
        glutPostRedisplay();
        glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
    }
}