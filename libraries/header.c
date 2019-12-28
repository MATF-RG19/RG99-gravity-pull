#include "header.h"
#include "onDisplay.h"
#include <time.h>

move vec;
float x_pos, y_pos;
float y_pom_filed;
int gameActive;
int gameOver;
positionOfPlatform *platformPos;
int scale [10];
int translateIndicator [5];
double translate[5];
int onPlatform;

void initPosition(int i, int nivo){
    double yBase = nivo *2;
    double xDesno = (0.5*scale[i])/2;
    if(i%2 == 0)
    {
        platformPos[i].XLeveIvice = -2.5;
        platformPos[i].XdesneIvice = -2.5 + xDesno;
    }
    
    else
    {   
        platformPos[i].XdesneIvice = 4.5;
        platformPos[i].XLeveIvice = 4.5 -xDesno;
    }

    int y = 0.125;
    platformPos[i].YDonjeStrane = -yBase - 0.125;
    platformPos[i].YGornjeStrane = -yBase + 0.125;
}

void initialize (void){
    x_pos=0;
    y_pos=0;
    y_pom_filed = 0;
    vec.x=0;
    vec.y=0;
    gameActive = 0;
    gameOver = 0;
    int k =0;
    onPlatform=0;
    for(int i = 0; i<5; i++){
        translate[i]=k;
        k+=2;
    }

    for(int i =0; i<10; i++){
        int x = 3+i;
        int y = 13;

        srand(time(0));

        scale[i] = rand()%(y-x+1) + x;
    }


    platformPos = malloc(10*sizeof(positionOfPlatform));
    if(platformPos == NULL){
        printf("Nije uspeo malloc\n");
        gameOver = 1;
    }


    for(int i=0; i<10; i++){
        int nivo = i/2;
        initPosition(i,nivo);
    }
}