#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "header.h"
#include "onTimer.h"


void on_timer (int value){
    if(value != TIMER_ID)
        return;
    x_pos +=vec.x*0.01;
    y_pos +=vec.y*0.01;
    
    y_pom_filed+=0.01;
    
    vec.y -=0.1;
    
    glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
    
}