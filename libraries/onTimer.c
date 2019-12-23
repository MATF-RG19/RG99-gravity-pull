#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "header.h"
#include "onTimer.h"
#include "onDisplay.h"


void on_timer (int value){
    if(value != TIMER_ID)
        return;
 
    if(gameActive && !gameOver){
        x_pos +=vec.x*0.01;
        y_pos +=vec.y*0.01;
        
        pos.YDonjaKoordinata+= y_pos;
        pos.YGornjaKoordinata+= y_pos;

        if(pos.YGornjaKoordinata>=2.05){
            gameOver = 1;
            printf("Poginuo si :)\n");
        }
        

        y_pom_filed+=0.01;

        vec.y -=0.1;
        printf("%f %f\n",pos.YDonjaKoordinata, pos.YGornjaKoordinata);
        glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
    }
}