#ifndef URETIMB_H
#define URETIMB_H

#include "uretim.h"

// uretimA sınıfı
struct uretimB
{
    Uretim super;
};

typedef struct uretimB *UretimB;

// UretimA sınıfı için metotların bildirimleri
UretimB new_UretimB();
void delete_UretimB(UretimB);
int uretB();

#endif
