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

/*
    U ovom .h fajlu se nalaze bitne promenljive i strukture za celu igricu da bi sve ostale
    biblioteke koje sam napravio mogle da ih vide i da bi sve bile na jednom mestu. Tkaodje
    se nalaze deklaracije funckija.
*/

//Struktura koja opisuje dva vekrota kretanja u x, y ravni
typedef struct MOVE{
    double x;
    double y;
}move;

//Struktura koja opisuje poziciju karaktera tokom igrice
typedef struct positionOfCharacter{
    double YGornjaKoordinata;
    double YDonjaKoordinata;
    double XKoordinataLeveNoge;
    double XKoordinataDesneNoge;
}positionOfCharacter;

//Strukruta koja opisuje koordinate platformi tokom igrice
typedef struct positionOfPlatform{
    double YGornjeStrane;
    double YDonjeStrane;
    double XLeveIvice;
    double XdesneIvice;
}positionOfPlatform;

//Promenljiva koja se nadalje koristi kao pozicija karaktera gde je neophodno
extern positionOfCharacter pos;
//Pokazivac na strukturu pozicije paltformi gde ce biti cuvane pozicije platformi
extern positionOfPlatform *platformPos;
// Niz koji opisuje koliko je nepohodno skalirati svaku paltformu u toku igrice
extern int scale [10];
// Vektro kretanja
extern move vec;
extern float x_pos, y_pos;
//Promenljiva koja sluzi za kretanje paltformi
extern float y_pom_filed;
//Promenljiva koja je indikator da li je igra akrivna
extern int gameActive;
//Promenljiva koja je indikator da li je igrac zavrsio igru ili nije
extern int gameOver;
//Niz koji govori kojillo treba translirati svaku platformu
extern double translate[5];
//Faktor za koji se platforme ubrzavaju tokom vremena
extern double speedUpFactor;
//Indikatro da li se igrac nalazi na platformi ili ne
extern int onPlatform;
//Indkiator za ispis pocetnog ekrane igre
extern int gameAcrivatedFirstTime;
//Prametar koji sluzi za rotaciju ruku
extern int animationParameter;;
//Funkcija za inicializaciju 
void initialize (void);
//Funckija za inicializaciju pozicija platformi
void initPosition(int i, int nivo);
#endif
