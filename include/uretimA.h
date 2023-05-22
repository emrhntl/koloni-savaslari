#ifndef URETIMA_H
#define URETIMA_H

#include "uretim.h"

// uretimA sınıfı
struct uretimA
{
    Uretim super;
};

typedef struct uretimA *UretimA;

// UretimA sınıfı için metotların bildirimleri
UretimA new_UretimA();
void delete_UretimA(UretimA);
int uretA();

#endif
