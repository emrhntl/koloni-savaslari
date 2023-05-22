// taktik.h dosyası
#ifndef TAKTIK_H
#define TAKTIK_H

struct taktik
{
    // sınıfın metotları
    void (*delete_Taktik)(struct taktik *); // yıkıcı metot
    int (*savas)();                         // saf sanal metot bildirimi
};

typedef struct taktik *Taktik; // struct taktik* tipine Taktik takma adı verme

Taktik new_Taktik();        // kurucu metot prototipi
void delete_Taktik(Taktik); // yıkıcı metot prototipi
int savas();                // saf sanal metot bildirimi

#endif
