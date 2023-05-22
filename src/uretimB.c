#include "uretimB.h"
#include <stdlib.h>

UretimB new_UretimB()
{
    UretimB this = (UretimB)malloc(sizeof(struct uretimB));

    this->super = new_Uretim();
    this->super->uret = &uretB;

    return this;
}

void delete_UretimB(UretimB this)
{
    if (this != NULL)
    {
        free(this);
    }
}

int uretB()
{
    return (rand() % 8) + 3;
}
