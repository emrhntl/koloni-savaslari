#ifndef TAKTIKA_H
#define TAKTIKA_H

#include "taktik.h"

// TaktikA sınıfı
typedef struct taktikA {
    Taktik super; // Üst sınıf Taktik
} *TaktikA;

// TaktikA sınıfı için metotların bildirimleri

TaktikA new_TaktikA();
void delete_TaktikA(TaktikA this);
int savasA();

#endif /* TAKTIKA_H */
