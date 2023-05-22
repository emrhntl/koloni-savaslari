#include "taktikA.h"
#include <stdlib.h>
#include <stdio.h>

TaktikA new_TaktikA()
{
    TaktikA this = (TaktikA)malloc(sizeof(struct taktikA));
    this->super = new_Taktik(); // taktikA sınıfının üst sınıfı olan taktik'in bir örneğini oluştur
    this->super->savas = &savasA; // savas fonksiyonunu atama
    // Taktik sınıfından kalıtılan metotları bağlama
    return this;
}

void delete_TaktikA(TaktikA this)
{
    if (this != NULL)
    {
        delete_Taktik(this->super); // Taktik sınıfının belleğini serbest bırakma
        free(this);
    }
}

int savasA()
{   
    // 0 ile 1000 arasında rastgele bir sayı üretme
    int random_number = rand() % 1001;
    return random_number;
}
