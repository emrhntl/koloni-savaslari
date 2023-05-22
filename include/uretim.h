// uretim.h dosyası
#ifndef URETIM_H
#define URETIM_H

struct uretim
{
    // sınıfın metotları
    void (*delete_uretim)(struct uretim *); // yıkıcı metot
    int (*uret)();                          // saf sanal metot bildirimi
};

typedef struct uretim *Uretim; // struct uretim* tipine Uretim takma adı verme

Uretim new_Uretim();        // kurucu metot prototipi
void delete_Uretim(Uretim); // yıkıcı metot prototipi
int uret();                 // saf sanal metot bildirimi

#endif
