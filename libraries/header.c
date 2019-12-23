#include "header.h"

move vec;
float x_pos, y_pos;
float y_pom_filed;
int gameActive;
int gameOver;

void initialize (void){
    x_pos=0;
    y_pos=0;
    y_pom_filed = 0;
    vec.x=0;
    vec.y=0;
    gameActive = 0;
    gameOver = 0;
}