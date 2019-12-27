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

void initialize (void){
    x_pos=0;
    y_pos=0;
    y_pom_filed = 0;
    vec.x=0;
    vec.y=0;
    gameActive = 0;
    gameOver = 0;

    for(int i =0; i<10; i++){
        int x = 3+i;
        int y = 13;

        srand(time(0));

        scale[i] = rand()%(y-x+1) + x;
    }
    for (int i = 0; i<10; i++)
        printf("%d \n",scale[i]);

    platformPos = malloc(10*sizeof(positionOfPlatform));
    if(platformPos == NULL){
        printf("Nije uspeo malloc\n");
        gameOver = 1;
    }
}