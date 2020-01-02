#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "./../libraries/header.h"
#include "./../libraries/onKeyboard.h"
#include "./../libraries/onTimer.h"
#include "./../libraries/onDisplay.h"


extern int window_width, window_height;
static void on_reshape(int width, int height);

int main(int argc, char **argv)
{   
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    glutInitWindowSize(1400, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    
    glutKeyboardFunc(onKeyboardMove);
    glutKeyboardUpFunc(onKeyboardMoveUp);
    glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
    glutTimerFunc(TIMER_INTERVAL1, on_timerSpeedUp, TIMER_ID1);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);

    glClearColor(0.61, 0.82, 1, 0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glLineWidth(2);

    initialize();
    init_texture();

    glutMainLoop();

    return 0;
}

static void on_reshape(int width, int height)
{
    window_width = width;
    window_height = height;
}

