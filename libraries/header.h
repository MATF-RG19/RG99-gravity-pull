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

typedef struct positionOfCharacter{
    double YGornjaKoordinata;
    double YDonjaKoordinata;
    double XKoordinataLeveNoge;
    double XKoordinataDesneNoge;
}positionOfCharacter;

typedef struct positionOfPlatform{
    double YGornjeStrane;
    double YDonjeStrane;
    double XLeveIvice;
    double XdesneIvice;
}positionOfPlatform;

extern positionOfCharacter pos;
extern positionOfPlatform *platformPos;
extern int scale [10];
extern move vec;
extern float x_pos, y_pos;
extern float y_pom_filed;
extern int gameActive;
extern int gameOver;

void initialize (void);
#endif
