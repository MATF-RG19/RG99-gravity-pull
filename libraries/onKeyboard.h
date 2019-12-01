#ifndef _ON_KEYBOARD_C_
#define _ON_KEYBOARD_C_

#include "header.h"

static void onKeyboardMove(unsigned char key, int x, int y){
	
    switch (key) {
        case 27:
            exit(0);
            break;

        case 'w':
            vec.y=5;
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

static void onKeyboardMoveUp(unsigned char key, int x,int y){

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

#endif
