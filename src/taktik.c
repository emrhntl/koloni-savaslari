// taktik.c dosyası
#include "taktik.h"
#include <stdlib.h>
#include <stdio.h>

Taktik new_Taktik() {
 Taktik this; // this adında bir Taktik tipinde değişken tanımlama
 this = (Taktik)malloc(sizeof(struct taktik)); // bellekten yer ayırma

 // metotları tanımlama
 this->delete_Taktik = &delete_Taktik; // yıkıcı metodu bağlama
 this->savas = NULL; // abstract metodu NULL olarak bırakma

 return this; // oluşturulan nesneyi döndürme
}

void delete_Taktik(Taktik this) {
 if (this != NULL) {
 free(this); // bellekten yer bırakma
 }
}

// saf sanal metot tanımı yoktur, çünkü bu sınıf soyut sınıftır.
