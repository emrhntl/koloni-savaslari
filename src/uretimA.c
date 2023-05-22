#include "uretimA.h"
#include <stdlib.h>

UretimA new_UretimA()
{
    UretimA this = (UretimA)malloc(sizeof(struct uretimA));

    this->super = new_Uretim();
    this->super->uret = &uretA;

    return this;
}

void delete_UretimA(UretimA this)
{
    if (this != NULL)
    {
        free(this);
    }
}

int uretA()
{
    return (rand() % 10) + 1;
}
