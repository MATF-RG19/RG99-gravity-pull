#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>
#include <math.h>
#include "header.h"
#include "onDisplay.h"
#include <string.h>

char ispis[50];
char nazivIgre[50];

int window_width, window_height;
positionOfCharacter pos;
static void renderStrokeString(int x, int y,int z,void* font, char *string)
{
    int len;
    glDisable(GL_LIGHTING);
    glTranslatef(x,y,z);
    glScalef(0.03,0.03,10);
    len = strlen(string);
    for (int i = 0; i < len; i++)
    {
        glutStrokeCharacter(font, string[i]);
    }
}

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
    if(!gameAcrivatedFirstTime){
        glClearColor(0,0,0,0);
        glPushMatrix();
            int x = -25;
            int y = 12;
            int z = 0;
            glScalef(0.05,0.05,5);
                glPushAttrib(GL_LINE_BIT);
                    glLineWidth(4); //Postavljamo debljinu linije
                    sprintf(ispis,"To start the game press 'g' or 'G'");
                    glColor3f(1,0,0);
                    renderStrokeString(x,y,z,GLUT_STROKE_MONO_ROMAN,ispis);
                glPopAttrib();
        glPopMatrix();
        glPushMatrix();
             y = -2;
             z = 0;
            glScalef(0.05,0.05,5);
                glPushAttrib(GL_LINE_BIT);
                    glLineWidth(4); //Postavljamo debljinu linije
                    sprintf(ispis,"To pause the game press 'p' or 'P'");
                    glColor3f(1,0,0);
                    renderStrokeString(x,y,z,GLUT_STROKE_MONO_ROMAN,ispis);
                glPopAttrib();
        glPopMatrix();
        glPushMatrix();
             y = -12;
             z = 0;
            glScalef(0.05,0.05,5);
                glPushAttrib(GL_LINE_BIT);
                    glLineWidth(4); //Postavljamo debljinu linije
                    sprintf(ispis,"To restart the game press 'r' or 'R'");
                    glColor3f(1,0,0);
                    renderStrokeString(x,y,z,GLUT_STROKE_MONO_ROMAN,ispis);
                glPopAttrib();
        glPopMatrix();
        glPushMatrix();
            y = 35;
            x = -12;
            glScalef(0.05,0.05,5);
            glPushAttrib(GL_LINE_BIT);
                glLineWidth(4); //Postavljamo debljinu linije
                sprintf(nazivIgre,"****Gravitiy Pull****");
                 glColor3f(1,1,0);
                renderStrokeString(x,y,z,GLUT_STROKE_MONO_ROMAN,nazivIgre);
            glPopAttrib();
        glPopMatrix();
    }
    if(gameOver){
        glClearColor(0,0,0,0);
        glPushMatrix();
            int x = 3;
            int y = 12;
            int z = 0;
        glScalef(0.05,0.05,5);
            glPushAttrib(GL_LINE_BIT);
                glLineWidth(4); //Postavljamo debljinu linije
                sprintf(ispis,"GAME OVER :(");
                 glColor3f(1,0,0);
                renderStrokeString(x,y,z,GLUT_STROKE_MONO_ROMAN,ispis);
            glPopAttrib();
        glPopMatrix();
    }
    if(gameAcrivatedFirstTime && !gameOver){
        glClearColor(0.61, 0.82, 1, 0);
        drawPyramidBlockTop();
        //drawPyramidBlockDown();
        glPushMatrix();
            glEnable (GL_CLIP_PLANE0);
            glEnable (GL_CLIP_PLANE1);
            glClipPlane(GL_CLIP_PLANE0, ClipPlaneLeft);
            glClipPlane(GL_CLIP_PLANE1, ClipPlaneRigh);

            drawFivePlatforms();

            glDisable(GL_CLIP_PLANE0);
            glDisable(GL_CLIP_PLANE1);
        glPopMatrix();
        
        drawCaracter();
    }
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
        glTranslatef(-2.5,-translate[0],0);
        glScalef(scale[0],0.5,1.5);
        glutSolidCube(0.5);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(4.5,-translate[0],0);
        glScalef(scale[1],0.5,1.5);
        glutSolidCube(0.5);
    glPopMatrix();
    
    //Drugi red Platformi
    glPushMatrix();
        glTranslatef(-2.5,-translate[1],0);
        glScalef(scale[2],0.5,1.5);
        glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(4.5,-translate[1],0);
        glScalef(scale[3],0.5,1.5);
        glutSolidCube(0.5);
    glPopMatrix();

    //Treci red Platformi
    glPushMatrix();
        glTranslatef(-2.5,-translate[2],0);
        glScalef(scale[4],0.5,1.5);
        glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(4.5,-translate[2],0);
        glScalef(scale[5],0.5,1.5);
        glutSolidCube(0.5);
    glPopMatrix();

    //Cetvrti red platformi
    glPushMatrix();
        glTranslatef(-2.5,-translate[3],0);
        glScalef(scale[6],0.5,1.5);
        glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(4.5,-translate[3],0);
        glScalef(scale[7],0.5,1.5);
        glutSolidCube(0.5);
    glPopMatrix();

    //Peti red paltformi
    glPushMatrix();
        glTranslatef(-2.5,-translate[4],0);
        glScalef(scale[8],0.5,1.5);
        glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(4.5,-translate[4],0);
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


void printMirko(void){
    printf("Skaliranja za platforme: \n");
    for(int i=0; i<10;  i++){
        printf("Skaliranje za parametar: %d\n", scale[i]);
    }
    
    printf("Pozicije platformi: \n");
    for(int j=0; j<10; j++){
        printf("Pozicija x leve ivice: %f\n",platformPos[j].XLeveIvice);
        printf("Pozicija x desne ivice: %f\n",platformPos[j].XdesneIvice);
        printf("Pozicija y gornje ivice: %f\n",platformPos[j].YGornjeStrane);
        printf("Pozicija y donje ivice: %f\n",platformPos[j].YDonjeStrane);
    }
}
