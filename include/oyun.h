#ifndef OYUN_H
#define OYUN_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "koloni.h"

struct oyun
{
    int koloniSayisi;
    int kaybedenKoloniSayisi;
    Koloni *koloniler;
    Koloni *kaybedenKoloniler;
    // sınıfın metotları
    void (*savasBaslat)(struct oyun *);
    void (*delete_Oyun)(struct oyun *); // yıkıcı metot
};

typedef struct oyun *Oyun; // struct oyun* tipine Oyun takma adı verme

Oyun new_Oyun(Koloni[], int); // kurucu metot prototipi
void savasBaslat(Oyun);
void savastir(Oyun, Koloni, Koloni);
void koloniKontrol(Oyun, Koloni);
void turSonu(Oyun, Koloni);
void durumYazdir(Oyun, int);
void yasayanYazdir(Koloni);
void kaybedenYazdir(Koloni);

void delete_Oyun(Oyun); // yıkıcı metot prototipi

#endif
