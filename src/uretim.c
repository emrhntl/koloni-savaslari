// uretim.c dosyası
#include "uretim.h"
#include <stdlib.h>
#include <stdio.h>

Uretim new_Uretim()
{
    Uretim this;                                  // this adında bir Uretim tipinde değişken tanımlama
    this = (Uretim)malloc(sizeof(struct uretim)); // bellekten yer ayırma

    // metotları tanımlama
    this->delete_uretim = &delete_Uretim; // yıkıcı metodu bağlama
    this->uret = NULL;                    // abstract metodu NULL olarak bırakma

    return this; // oluşturulan nesneyi döndürme
}

void delete_Uretim(Uretim this)
{
    if (this != NULL)
    {
        free(this); // bellekten yer bırakma
    }
}

// saf sanal metot tanımı yoktur, çünkü bu sınıf soyut sınıftır.
