#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "./../libraries/header.h"
#include "./../libraries/onKeyboard.h"
#include "./../libraries/onTimer.h"
#include "./../libraries/onDisplay.h"


static int window_width, window_height;
static void on_reshape(int width, int height);

int main(int argc, char **argv)
{

	x_pos=0;
	y_pos=0;
	vec.x=0;
	vec.y=0;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    
    glutKeyboardFunc(onKeyboardMove);
    glutKeyboardUpFunc(onKeyboardMoveUp);
    glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);

    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glLineWidth(2);

    glutMainLoop();

    return 0;
}

static void on_reshape(int width, int height)
{
    window_width = width;
    window_height = height;
}

