#ifndef KOLONI_H
#define KOLONI_H

#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "taktikA.h"
#include "taktikB.h"
#include "uretimA.h"
#include "uretimB.h"

struct koloni
{
    // savas taktiği
    TaktikA taktikA;
    TaktikB taktikB;

    // uretim
    UretimA uretimA;
    UretimB uretimB;

    int populasyon;
    int yemekStogu;
    int kazanmaSayisi;
    int kaybetmeSayisi;
    char sembol;

    void (*kazan)(struct koloni *, int);
    void (*kaybet)(struct koloni *, int);
    void (*delete_Koloni)(struct koloni *);
    void (*stokUret)(struct koloni *);
    int (*savasDegerGetir)(struct koloni *);
};

typedef struct koloni *Koloni;

Koloni new_Koloni(int, char);
void kazan(Koloni, int);
void kaybet(Koloni, int);
void stokUret(Koloni);
int savasDegerGetir(Koloni);
// taktik belirle

void delete_Koloni(Koloni); // parametre Koloni olarak değiştirildi

#endif
