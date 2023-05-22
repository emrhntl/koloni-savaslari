#include "taktikB.h"
#include <stdlib.h>
#include <stdio.h>

TaktikB new_TaktikB()
{
    TaktikB this = (TaktikB)malloc(sizeof(struct taktikB));

    this->super = new_Taktik();
    this->super->savas = &savasB;

    // Taktik sınıfından kalıtılan metotları bağlama

    return this;
}

void delete_TaktikB(TaktikB this)
{
    if (this != NULL)
    {
        free(this);
    }
}

int savasB()
{
    // 300 ile 700 arasında rastgele bir sayı üretme
    int random_number = rand() % 401 + 300;
    return random_number;
}
