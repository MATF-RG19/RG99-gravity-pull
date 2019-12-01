#ifndef _HEADER_H__
#define _HEADER_H__

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>

#define TIMER_ID 0
#define TIMER_INTERVAL 10

typedef struct MOVE{
    double x;
    double y;
}move;

move vec;
float x_pos=0, y_pos=0;

static void on_timer(int value);

static void onKeyboardMove(unsigned char key, int x, int y);
static void onKeyboardMoveUp(unsigned char key,int x,int y);


#endif
