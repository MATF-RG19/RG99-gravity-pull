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

//main funkcija
int main(int argc, char **argv)
{   
    //inicializacija glut-a
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    //Podesavanje velicine prozora
    glutInitWindowSize(1400, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    
    //Funkcije za podesavanje kontrola na tastaturi
    glutKeyboardFunc(onKeyboardMove);
    glutKeyboardUpFunc(onKeyboardMoveUp);
    
    //Glavna timer funkcija za kolizije i azuriranje koordinata tela na sceni
    glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
    
    //Timer funkcija koja je zaduzena za ubrzanje paltformi tokom vremena
    glutTimerFunc(TIMER_INTERVAL1, on_timerSpeedUp, TIMER_ID1);
    
    //Funkcija za promenu velicine glavnog prozora
    glutReshapeFunc(on_reshape);
    
    //Glavna display funkcija
    glutDisplayFunc(on_display);

    //Podesavanje boje pozadine 
    glClearColor(0.61, 0.82, 1, 0);
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glLineWidth(2);

    //Funkcija zaduzena za inicializaciju bitnh promenljivih
    initialize();
    
    //Funkcija za inicializaciju texture
    init_texture();

    glutMainLoop();

    return 0;
}

static void on_reshape(int width, int height)
{
    window_width = width;
    window_height = height;
}

