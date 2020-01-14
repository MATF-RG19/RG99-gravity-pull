#ifndef _ON_DISPLAY_C_
#define _ON_DISPLAY_C_

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "header.h"
/*
    U ovom .h fajlu nalaze se deklaracije funckija koje su bitne za iscrtavanje i ispis na ekran, a
    takdoje se nalaze i neke promenljive bitne za ispis i ostale stvari.
*/

// Promenljive koje opisuju velicinu ekrana
extern int window_width, window_height;

//Promenljiva u kojoj se nalazi tekst koji treba da se ispise
extern char ispis[50];

//Glavna funkcija za iscrtavanje
void on_display(void);
//Funckija u kojoj se iscrtava karakter
void drawCaracter(void);

//Funkcije za iscrtavanje priamida na vrhu ekrana
void pyramid(void);
void drawPyramid(int ind);
void drawPyramidBlockTop(void);
void pyramidR(void);
void drawPyramidBlockDown (void);
//Funckija koja crta paltforme
void drawFivePlatforms(void);
//Funkcija koja sluzi za ispis pri testiranju aplikacije
void printMirko (void);
//Funkcija koja sluzi za ispis teksta
static void renderStrokeString(int x, int y,int z,void* font, char *string);
//Funkcija za inicializaciju teksture
void init_texture(void);
//Funkcija za ispis rezultata u toku igre
void displayScoore(void);
#endif