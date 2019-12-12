#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>

#include "onKeyboard.h"
#include "header.h"

void onKeyboardMove(unsigned char key, int x, int y){
	
    switch (key) {
        case 27:
            exit(0);
            break;

        case 'w':
            vec.y=3;
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

    glutPostRedisplay();
}