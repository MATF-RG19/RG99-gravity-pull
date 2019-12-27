#ifndef _ON_DISPLAY_C_
#define _ON_DISPLAY_C_

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "header.h"

extern int window_width, window_height;

void on_display(void);
void drawCaracter(void);

void drawBlockArena(void);
void drawArena(int k);

void pyramid(void);
void drawPyramid(int ind);
void drawPyramidBlockTop(void);
void pyramidR(void);
void drawPyramidBlockDown (void);
int randomNumber(void);
void drawFivePlatforms(void);

#endif