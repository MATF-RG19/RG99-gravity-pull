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

extern move vec;
extern float x_pos, y_pos;
extern float y_pom_filed;

void initialize (void);
#endif
