#ifndef _ON_TIMER_C_
#define _ON_TIMER_C_

#include "header.h"

/*
    Ovde se nalaze deklaracije timer funckija koje upotrebljavamo u programu
*/

//Glavna timer funkcija
void on_timer (int value);
//Funkcija za detekciju kolizije
void onPlatformCheck(void);
//Timer za ubrzavanje kretanja platformi
void on_timerSpeedUp(int value);


#endif
