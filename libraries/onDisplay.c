#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>
#include <math.h>
#include "header.h"
#include "onDisplay.h"
#include <string.h>
#include "image.h"

/*
    Ovde se nalaze definicije funckija koje su bitne za iscrtavanje i ispis na sceni
*/
//Putanja i ime do fajla gde se nalazi tekstura
#define FILENAME0 "./../libraries/texture1.bmp"

static GLuint names[1];

//Promenljiva gde se smesta sta se ispisuje na ekran
char ispis[50];
//Promenljiva gde se ispisuje natpis same igre
char nazivIgre[50];
//Promenljive gde se ispisuje rezultat koji je ostvario igrac
char rezultat[50];

//Promneljive koje opisuju velicinu ekrana
int window_width, window_height;

//Promenljiva koja opisuje poziciju glavnog kraktera na sceni
positionOfCharacter pos;

//Funkcija za prikaz teksta
static void renderStrokeString(int x, int y,int z,void* font, char *string)
{
    int len;
    //Translacija teksta na zeljenu poziciju
    glTranslatef(x,y,z);
    //Skaliranje teksta
    glScalef(0.03,0.03,10);
    //Dodela vrednosti promenljivoj za duzinu reci za ispis
    len = strlen(string);
    for (int i = 0; i < len; i++)
    {
        //Funkcija koja definise font i slovo
        glutStrokeCharacter(font, string[i]);
    }
}


// Glavna funkcija za iscrtavanje na ekranu
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

    // Podesava se tacka pogleda.
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
            1, 2, 3,
            1, 1, 1,
            0, 1, 0
        );

    //Nmestaju se koordinate dve ravni odsecanja
    GLdouble ClipPlaneLeft [] = {1,0,0,2.5};
    GLdouble ClipPlaneRigh [] = {-1,0,0,4.5};

    //Ovde se vrsi ispis teksta za ulazni ekran u igricu
    if(!gameAcrivatedFirstTime){
        glClearColor(0,0,0,0);
        glPushMatrix();
            //Koordinate koje opisujuju poziciju teksta na ekranu
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
             y -= 10;
             x-=2;
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
             y -= 10;
             z = 0;
             x-=2;
            glScalef(0.05,0.05,5);
                glPushAttrib(GL_LINE_BIT);
                    glLineWidth(4); //Postavljamo debljinu linije
                    sprintf(ispis,"To restart the game press 'r' or 'R'");
                    glColor3f(1,0,0);
                    renderStrokeString(x,y,z,GLUT_STROKE_MONO_ROMAN,ispis);
                glPopAttrib();
        glPopMatrix();
        glPushMatrix();
            y = 28;
            x = -10;
            glScalef(0.05,0.05,5);
            glPushAttrib(GL_LINE_BIT);
                glLineWidth(4); //Postavljamo debljinu linije
                sprintf(nazivIgre,"****Gravitiy Pull****");
                 glColor3f(1,1,0);
                renderStrokeString(x,y,z,GLUT_STROKE_MONO_ROMAN,nazivIgre);
            glPopAttrib();
        glPopMatrix();
    }

    //Ispis teksta kada se igra zavrsi
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
        glScalef(0.05,0.05,5);
        y-=8;
        x-=8;
            glPushAttrib(GL_LINE_BIT);
                glLineWidth(4); //Postavljamo debljinu linije
                sprintf(rezultat,"Your score is %d",animationParameter/100);
                 glColor3f(0,0,1);
                renderStrokeString(x,y,z,GLUT_STROKE_MONO_ROMAN,rezultat);
            glPopAttrib();
        glPopMatrix();
    }
    //Iscrtavanje svih delova scene kada je igra aktivna
    if(gameAcrivatedFirstTime && !gameOver){
        
        glClearColor(0.61, 0.82, 1, 0);
        drawPyramidBlockTop();
        displayScoore();
        glPushMatrix();
        //Podesavanje ravni odsecanja
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
    glTranslatef(100,100,100);
    glBindTexture(GL_TEXTURE_2D, names[0]);
    glBegin(GL_QUADS);
        glColor3f(1,1,1);
        glTexCoord2f(0,0);
        glVertex2f(0,0);
        glTexCoord2f(0,1);
        glVertex2f(0,1);
        glTexCoord2f(1,1);
        glVertex2f(1,1);
        glTexCoord2f(1,0);
        glVertex2f(1,0);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glutPostRedisplay();
    glutSwapBuffers();
    
}

//Crtanje karaktera i inicializacija njegovih pozicija i podesavanje osvetljenja
void drawCaracter(void){
    pos.YGornjaKoordinata = 0.3;
    pos.YDonjaKoordinata = -0.425;
    pos.XKoordinataLeveNoge = -0.08;
    pos.XKoordinataDesneNoge = 0.03;

    glEnable(GL_LIGHTING);

    GLfloat light_diffuse[] = {1,1,0,1};
    GLfloat light_diffuse1[] = {1,0,0,1};
    GLfloat light_diffuse3[] = {0,0,0.8,1};

    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse1);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, light_diffuse3);


    GLfloat  diffuse_coefs[] = {0.8,0.8,0,1};
    GLfloat  diffuse_coefs1[] = {0.8,0,0,1};
    GLfloat  diffuse_coefs3[] = {0.8,0.8,0.8,1};
    GLfloat shine = 100;

    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);

    glTranslatef(x_pos,y_pos, 0);

    //Iscrtavanje Tela
    glEnable(GL_LIGHT2);
    glPushMatrix();
        glTranslatef(0,-0.05,0);
        glScalef(1,1.5,1);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,diffuse_coefs1);
        glutSolidCube(0.2);
    glPopMatrix();
    glDisable(GL_LIGHT2);

    //Iscrtavanje glave;
    glEnable(GL_LIGHT1);
    glPushMatrix();
        glTranslatef(0,0.15,0);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,diffuse_coefs);
        glutSolidSphere(0.075,10,10);
    glPopMatrix();
    glDisable(GL_LIGHT1);
    
    
    //Iscrtavanje nogu
    GLfloat light_diffuse2[] = {0.4,0.2,0,1};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse2);
    GLfloat coefs_diffuse[] = {0.5,0.5,0,1};

    glDisable(GL_LIGHTING); 
    glPushMatrix();
        glColor3f(0.4,0.2,0.001);
        glPushMatrix();
            glTranslatef(0.075,-0.2875,0);
            glScalef(0.181818,1,0.181818);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,coefs_diffuse);
            glutSolidCube(0.275);
        glPopMatrix();

    
        glPushMatrix();
            glTranslatef(-0.055,-0.2875,0);
            glScalef(0.181818,1,0.181818);
            glutSolidCube(0.275);
        glPopMatrix();
    glPopMatrix();
    glEnable(GL_LIGHTING);


    //Iscrtavanje ruku
    glEnable(GL_LIGHT4);
    glPushMatrix();
        glRotatef(animationParameter, 1,0,0);
        glPushMatrix();
            glTranslatef(0.1,-0.05,0);
            glScalef(0.5,2,1);
            glRotatef(45,0,1,0);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_coefs3);
            glutSolidCube(0.1);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef(-0.1,-0.05,0);
            glScalef(0.5,2,1);
            glRotatef(45,0,1,0);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_coefs3);
            glutSolidCube(0.1);
        glPopMatrix();
    glPopMatrix();
    glDisable(GL_LIGHT4);
    glDisable(GL_LIGHTING);
}

//Funkcija za iscrtavanje platformi i podesavanje osvetljena platformi
void drawFivePlatforms(void){
    glEnable(GL_LIGHTING);

    glEnable(GL_LIGHT0);

    GLfloat light_ambient[] = {1,1,1,1};

    GLfloat ambient_coefs[] = {0.4,0.9,1, 1};

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    
    GLfloat light_diffuse[] = {0.61,0.82,1,1};

    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);

    GLfloat  diffuse_coefs[] = {0.5,0.8,0.5,1};

    GLfloat light_specular[] = {1,1,1,0};

    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    GLfloat specular_coefs[] ={1,0.5,0.5,1};
    
    GLfloat shine = 100;

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_coefs);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,diffuse_coefs);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_coefs);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);
   
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
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);
}

//Funkcija u kojoj se iscrtava piramida
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
// Ovde se iscrtava red piramida koji se nalazi na vrhu ekrana
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
//Iscrtavanje okrenute piramide
void pyramidR(void){
glBindTexture(GL_TEXTURE_2D,names[0]);
glBegin(GL_TRIANGLES);
    
     
      glTexCoord2f(0,1);
      glVertex3f( -0.0f, -1.0f, -0.0f);
      glTexCoord2f(1,1);
      glVertex3f(1.0f, 1.0f, -1.0f);
      glTexCoord2f(0.5,0.5);
      glVertex3f(-1.0f, 1.0f, -1.0f);

      glTexCoord2f(0,1);
      glVertex3f(-0.0f, -1.0f, -0.0f);
      glTexCoord2f(1,1);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glTexCoord2f(0.5,0.5);
      glVertex3f(-1.0f, 1.0f, 1.0f);

      glTexCoord2f(0,1);
      glVertex3f(-0.0f, -1.0f, -0.0f);
      glTexCoord2f(1,1);
      glVertex3f(-1.0f, 1.0f, 1.0f);
      glTexCoord2f(0.5,0.5);
      glVertex3f(1.0f, 1.0f, 1.0f);
      
      glTexCoord2f(0,1);
      glVertex3f( -0.0f, -1.0f, -0.0f);
      glTexCoord2f(1,1);
      glVertex3f(1.0f,1.0f,1.0f);
      glTexCoord2f(0.5,0.5);
      glVertex3f(1.0f,1.0f, -1.0f);
   glEnd();
   glBindTexture(GL_TEXTURE_2D,0);
}

//Iscrtavanje donjeg reda piramida mozda se ne koristi :)
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

//Funkcija za inicializaciju teksture
void init_texture(void){
    /* Objekat koji predstavlja teskturu ucitanu iz fajla. */
    Image * image;

    /* Ukljucuje se testiranje z-koordinate piksela. */
    glEnable(GL_DEPTH_TEST);
    /* Ukljucujemo opciju koriscenja tekstura. */
    glEnable(GL_TEXTURE_2D);

    glTexEnvf(GL_TEXTURE_ENV,
              GL_TEXTURE_ENV_MODE,
              GL_MODULATE);

    /*
        Ucitavamo sliku koja predstavlja teksturu
    */
    image = image_init(0, 0);

    image_read(image, FILENAME0);

    /* Generisu se identifikatori tekstura. */
    glGenTextures(1, names);

    glBindTexture(GL_TEXTURE_2D, names[0]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    // Iskljucujemo teksturu 
    glBindTexture(GL_TEXTURE_2D, 0);

    //oslobadjamo image
    image_done(image);

}

//Fuunckija koja sluzi za debagovanje
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
//Funkcija za ispis rezultata u toku igre
void displayScoore(void){
        glPushMatrix();
            //Koordinate koje opisujuju poziciju teksta na ekranu
            int x = -55;
            int y = 25;
            int z = 0;
            glTranslatef(0,0, -1.5);
            glScalef(0.05,0.05,5);
                glPushAttrib(GL_LINE_BIT);
                    glLineWidth(4); //Postavljamo debljinu linije
                    sprintf(rezultat,"SCOORE: %d", animationParameter/100);
                    glColor3f(0,0,1);
                    renderStrokeString(x,y,z,GLUT_STROKE_MONO_ROMAN,rezultat);
                glPopAttrib();
        glPopMatrix();
}