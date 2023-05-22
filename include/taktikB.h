#ifndef TAKTIKB_H
#define TAKTIKB_H

#include "taktik.h"

struct taktikB
{
    Taktik super; // Taktik sınıfından kalıtım
};

typedef struct taktikB *TaktikB;

TaktikB new_TaktikB();
void delete_TaktikB(TaktikB);
int savasB();

#endif
