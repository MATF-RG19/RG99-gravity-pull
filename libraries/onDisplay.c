#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "header.h"
#include "onDisplay.h"

int window_width, window_height;

void on_display(void)
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
            1, 1, 1,
            0, 1, 0
        );
    drawPyramidBlockTop();
    //drawPyramidBlockDown();
    glTranslatef(0,y_pom_filed, 0);
    drawBlockArena();
    drawCaracter();
    glutPostRedisplay();
    glutSwapBuffers();
}

void drawCaracter(void){
    glColor3f(0.2, 0.2, 1);
    glTranslatef(x_pos,y_pos, 0);
    glPushMatrix();
        glScalef(1,1.5,1);
        glutSolidCube(0.2);
    glPopMatrix();
//    glScalef(1,1/1.5,1);
    glPushMatrix();
        glTranslatef(0,0.22,0);
        glColor3f(0.2,0.8,0.5);
        glutSolidSphere(0.075,10, 10);
        glScalef(0.5,2.75,0.5);
        glTranslatef(-0.07,-0.15,0.1);
        glColor3f(0.6,0.7,0.8);
        glutSolidCube(0.1);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(0,0.22,0);
        glColor3f(0.2,0.8,0.5);
        glScalef(0.5,2.75,0.5);
        glTranslatef(0.13,-0.15,0.1);
        glColor3f(0.6,0.7,0.8);
        glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.9,0.6,0.7);
        glTranslatef(0.1,0,0);
        glScalef(0.5,2,1);
        glRotatef(45,0,1,0);
        glutSolidCube(0.1);
    glPopMatrix();
    
    glPushMatrix();
        glColor3f(0.9,0.6,0.7);
        glTranslatef(-0.1,0,0);
        glScalef(0.5,2,1);
        glRotatef(45,0,1,0);
        glutSolidCube(0.1);
    glPopMatrix();
}

void drawBlockArena(void){
    int k = 0;
    for(int i=0; i<100; i++){
        drawArena(k);
        k=k+2;
    }
}

void drawArena(int k){
    glColor3f(0.5,0.5,0.5);
    glPushMatrix();
        glTranslatef(3.5,-k,0);
        glScalef(3,0.5,1.5);
        glutSolidCube(0.5);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(-0.5,-k,0);
        glScalef(3,0.5,1.5);
        glutSolidCube(0.5);
    glPopMatrix();
}

//Ne koristi se bas ali neka stoji mozda bude zatreabalo
void pyramid(void)
{
glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f(1.0f, -1.0f, 1.0f);
 
      
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f(0.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, -1.0f, 1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
 
      
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f(0.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
 
     
      glColor3f(1.0f,0.0f,0.0f);
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glVertex3f(-1.0f,-1.0f,-1.0f);
      glVertex3f(-1.0f,-1.0f, 1.0f);
   glEnd();

}

void drawPyramid(int ind){
    if(ind == 1){
        glPushMatrix();
            glScalef(0.1,0.1,0.1);
            pyramidR();
        glPopMatrix();
    }
    else
    {
        glPushMatrix();
            glScalef(0.1,0.1,0.1);
            pyramid();
        glPopMatrix();        
    }
    
}

void drawPyramidBlockTop(void){
    glPushMatrix();
        glTranslatef(0,2.055,0.5);
        glPushMatrix();
            for (int i = 0; i<16; i++){
                glTranslatef(0.201,0,0);
                drawPyramid(1);
            }
        glPopMatrix();

        glPushMatrix();
            drawPyramid(1);
            for (int i = 0; i<8; i++){
                glTranslatef(-0.20001,0,0);
                drawPyramid(1);
            }
        glPopMatrix();
    glPopMatrix();
}

void pyramidR(void){
glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f( -0.0f, -1.0f, -0.0f);
      glVertex3f(1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
 
      
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f(-0.0f, -1.0f, -0.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, 1.0f);
 
      
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f(-0.0f, -1.0f, -0.0f);
      glVertex3f(-1.0f, 1.0f, 1.0f);
      glVertex3f(1.0f, 1.0f, 1.0f);
 
     
      glColor3f(1.0f,0.0f,0.0f);
      glVertex3f( -0.0f, -1.0f, -0.0f);
      glVertex3f(1.0f,1.0f,1.0f);
      glVertex3f(1.0f,1.0f, -1.0f);
   glEnd();
}

void drawPyramidBlockDown(void){
    glPushMatrix();
        glTranslatef(0,-1.055,0.5);
        glScalef(1.5,1,-1.5);
        glPushMatrix();
            for (int i = 0; i<16; i++){
                glTranslatef(0.201,0,0);
                drawPyramid(0);
            }
        glPopMatrix();

        glPushMatrix();
            drawPyramid(0);
            for (int i = 0; i<8; i++){
                glTranslatef(-0.20001,0,0);
                drawPyramid(0);
            }
        glPopMatrix();
    glPopMatrix();
}


