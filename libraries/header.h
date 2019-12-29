#ifndef _HEADER_H__
#define _HEADER_H__

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>

#define TIMER_ID 0
#define TIMER_INTERVAL 5
#define TIMER_ID1 1
#define TIMER_INTERVAL1 15000

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
extern double translate[5];
extern double speedUpFactor;
extern int onPlatform;
//extern int moveXDisable;
extern int gameAcrivatedFirstTime;
void initialize (void);
void initPosition(int i, int nivo);
#endif
