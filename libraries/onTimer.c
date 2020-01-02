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
        animationParameter+=10;

        int vecyCopy;
        if(!onPlatform){
            vec.y -=0.1;
        }
        if(onPlatform){
            vecyCopy=vec.y;
            vec.y=1;
        }
        if (onPlatform && vecyCopy==3)
            vec.y+=3;

        x_pos +=vec.x*0.04;
        y_pos +=vec.y*(0.01+speedUpFactor);

        //Pomeranje platformi
        for (int i =0; i<5; i++){
            translate[i] -=(0.01+speedUpFactor);
        }
        //Azuriranje koordinata cikice
        pos.YDonjaKoordinata+= y_pos;
        pos.YGornjaKoordinata+= y_pos;
        pos.XKoordinataLeveNoge+=x_pos;
        pos.XKoordinataDesneNoge+=x_pos;


        for(int i=0; i<10; i++){
            platformPos[i].YDonjeStrane+=(0.01+speedUpFactor);
            platformPos[i].YGornjeStrane+=(0.01+speedUpFactor);
        }
        

        //printMirko();

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

                double xDesno = (0.5*scale[levo])/2;

                platformPos[levo].YGornjeStrane = -translate[i] + 0.125;
                platformPos[levo].YDonjeStrane = -translate[i] - 0.125;
                platformPos[levo].XLeveIvice = -2.5;
                platformPos[levo].XdesneIvice = -2.5 + xDesno;

                scale[levo+1] = rand()%(y-x+2) + x+1;
                

                xDesno = (0.5*scale[levo+1])/2;

                platformPos[levo+1].YGornjeStrane = -translate[i] + 0.125;
                platformPos[levo+1].YDonjeStrane = -translate[i] - 0.125;

                platformPos[levo+1].XdesneIvice = 4.5;
                platformPos[levo+1].XLeveIvice = 4.5 -xDesno;

            }
        }

        //printf("%f %f\n",pos.YDonjaKoordinata, pos.YGornjaKoordinata);
        onPlatformCheck();
        glutPostRedisplay();
        glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
    }
}

void onPlatformCheck(void){

    if(gameActive && !gameOver){
        int k =0;
        int biloKolizije=0;
        for (int i=0; i<5; i++){
            if(pos.YDonjaKoordinata <= platformPos[2*i].YGornjeStrane && pos.YDonjaKoordinata>=platformPos[2*i].YDonjeStrane)
            {
                if((pos.XKoordinataLeveNoge >= platformPos[2*i].XLeveIvice && pos.XKoordinataLeveNoge <= platformPos[2*i].XdesneIvice) 
                        || (pos.XKoordinataDesneNoge<=platformPos[2*i+1].XdesneIvice && pos.XKoordinataDesneNoge>=platformPos[2*i+1].XLeveIvice)){
                    onPlatform = 1;
                    biloKolizije=1;
                    /*Kod koji je sluzio za debagovanje mozda bude zatrebao :)
                    printf("Pera%d\n",i);
                    printf("Pozicija covecljka:\n");
                    printf("pozicija leve noge:%f\n pozicija desne noge:%f\n pozicija ygornje:%f pozicija ydonje:%f\n",pos.XKoordinataLeveNoge,pos.XKoordinataDesneNoge,pos.YGornjaKoordinata,pos.YDonjaKoordinata);
                    printf("Pozicija x leve ivice: %f\n",platformPos[2*i].XLeveIvice);
                    printf("Pozicija x desne ivice: %f\n",platformPos[2*i].XdesneIvice);
                    printf("Pozicija y gornje ivice: %f\n",platformPos[2*i].YGornjeStrane);
                    printf("Pozicija y donje ivice: %f\n",platformPos[2*i].YDonjeStrane);
                    printf("*************************************************************\n");
                    */
                }
            }
        }
        if (!biloKolizije)
            onPlatform=0;
    }
}

void on_timerSpeedUp(int value){
    if(value != TIMER_ID1)
        return;

    if(gameActive && !gameOver){
        speedUpFactor+=0.005;
        glutTimerFunc(TIMER_INTERVAL1, on_timerSpeedUp, TIMER_ID1);
    }
}