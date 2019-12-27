#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>
#include <math.h>
#include "header.h"
#include "onDisplay.h"

int window_width, window_height;
positionOfCharacter pos;
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

    GLdouble ClipPlaneLeft [] = {1,0,0,2.5};
    GLdouble ClipPlaneRigh [] = {-1,0,0,4.5};
    //Ako treba ubaci cu jos jednu ravan ali za  sada nije potrebana

    drawPyramidBlockTop();
    //drawPyramidBlockDown();
    glPushMatrix();
        glTranslatef(0,y_pom_filed, 0);

        glEnable (GL_CLIP_PLANE0);
        glEnable (GL_CLIP_PLANE1);
        glClipPlane(GL_CLIP_PLANE0, ClipPlaneLeft);
        glClipPlane(GL_CLIP_PLANE1, ClipPlaneRigh);

        drawFivePlatforms();

        glDisable(GL_CLIP_PLANE0);
        glDisable(GL_CLIP_PLANE1);
    glPopMatrix();
    
    drawCaracter();
    glutPostRedisplay();
    glutSwapBuffers();
}
//Crtanje karaktera i inicializacija negovih pozicija
void drawCaracter(void){
    pos.YGornjaKoordinata = 0.3;
    pos.YDonjaKoordinata = -0.425;
    pos.XKoordinataLeveNoge = -0.08;
    pos.XKoordinataDesneNoge = 0.03;
    glColor3f(0.2, 0.2, 1);
    glTranslatef(x_pos,y_pos, 0);

    //Iscrtavanje Tela
    glPushMatrix();
        glTranslatef(0,-0.05,0);
        glScalef(1,1.5,1);
        glutSolidCube(0.2);
    glPopMatrix();

    //Iscrtavanje glave;
    glPushMatrix();
        glColor3f(0.2,0.8,0.5);
        glTranslatef(0,0.15,0);
        glutSolidSphere(0.075,10,10);
    glPopMatrix();

    //Iscrtavanje nogu
    glPushMatrix();
        glColor3f(0.6,0.7,0.8);
        glTranslatef(0.075,-0.2875,0);
        glScalef(0.181818,1,0.181818);
        glutSolidCube(0.275);
    glPopMatrix();
        
    glPushMatrix();
        glColor3f(0.6,0.7,0.8);
        glTranslatef(-0.055,-0.2875,0);
        glScalef(0.181818,1,0.181818);
        glutSolidCube(0.275);
    glPopMatrix();
    
    //Iscrtavanje ruku
    glPushMatrix();
        glColor3f(0.9,0.6,0.7);
        glTranslatef(0.1,-0.05,0);
        glScalef(0.5,2,1);
        glRotatef(45,0,1,0);
        glutSolidCube(0.1);
    glPopMatrix();
    
    glPushMatrix();
        glColor3f(0.9,0.6,0.7);
        glTranslatef(-0.1,-0.05,0);
        glScalef(0.5,2,1);
        glRotatef(45,0,1,0);
        glutSolidCube(0.1);
    glPopMatrix();
}
//************************************************************************************************************
//Ovaj deo koda se ne koristi vise bice obrisan u poslednjem komitu
int randomNumber(void){
    int x = 1;
    int y = 10;

    srand(time(0));

    return rand()%(y-x+1) + x;
}

void drawBlockArena(void){
    int k = 0;
    printf("%d \n",randomNumber());
    for(int i=0; i<10; i++){
        drawArena(k);
        k=k+2;
    }
}
//************************************************************************************************************
void drawFivePlatforms(void){

    glColor3f(1,1,1);
    //Prvi red platformi
    glPushMatrix();
        glTranslatef(-2.5,0,0);
        glScalef(scale[0],0.5,1.5);
        glutSolidCube(0.5);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(4.5,0,0);
        glScalef(scale[1],0.5,1.5);
        glutSolidCube(0.5);
    glPopMatrix();
    platformPos[0].XLeveIvice = 4.5;
    platformPos[0].XdesneIvice = 4.5;
    //Drugi red Platformi
    glPushMatrix();
        glTranslatef(-2.5,-2,0);
        glScalef(scale[2],0.5,1.5);
        glutSolidCube(0.5);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(4.5,-2,0);
        glScalef(scale[3],0.5,1.5);
        glutSolidCube(0.5);
    glPopMatrix();

    //Treci red Platformi
    glPushMatrix();
        glTranslatef(-2.5,-4,0);
        glScalef(scale[4],0.5,1.5);
        glutSolidCube(0.5);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(4.5,-4,0);
        glScalef(scale[5],0.5,1.5);
        glutSolidCube(0.5);
    glPopMatrix();

    //Cetvrti red platformi
    glPushMatrix();
        glTranslatef(-2.5,-6,0);
        glScalef(scale[6],0.5,1.5);
        glutSolidCube(0.5);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(4.5,-6,0);
        glScalef(scale[7],0.5,1.5);
        glutSolidCube(0.5);
    glPopMatrix();

    //Peti red paltformi
    glPushMatrix();
        glTranslatef(-2.5,-8,0);
        glScalef(scale[8],0.5,1.5);
        glutSolidCube(0.5);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(4.5,-8,0);
        glScalef(scale[9],0.5,1.5);
        glutSolidCube(0.5);
    glPopMatrix();
}

//************************************************************************************************************
//Ovaj deo koda se vise ne koristi bice obrisan ako ne bude trebao u poslednjem komitu
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
// ************************************************************************************************************

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


