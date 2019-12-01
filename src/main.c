#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "./../libraries/header.h"
#include "./../libraries/onKeyboard.h"
#include "./../libraries/onTimer.h"


static int window_width, window_height;
static void on_reshape(int width, int height);
static void on_display(void);

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

    glClearColor(0.75, 0.75, 0.75, 0);
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

static void on_display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glViewport(0, 0, window_width, window_height);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(
            60,
            window_width/(float)window_height,
            1, 5);

    /* Podesava se tacka pogleda. */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
            1, 2, 3,
            0, 0, 0,
            0, 1, 0
        );

    
        glColor3f(1,0,0);
   	glBegin(GL_LINES);
   		glVertex3f(0,0,0);
   		glVertex3f(1,0,0);
   	glEnd();
   	
   	glColor3f(1,1,0);
   	glBegin(GL_LINES);
   		glVertex3f(0,0,0);
   		glVertex3f(0,1,0);
   	glEnd();
   	
   	glColor3f(0,1,1);
   	glBegin(GL_LINES);
   		glVertex3f(0,0,0);
   		glVertex3f(0,0,1);
   	glEnd();
   	

    glColor3f(25, 0, 1);
    glTranslatef(x_pos,y_pos, 0);
    glutWireCube(1);

    glutPostRedisplay();
    glutSwapBuffers();
}
