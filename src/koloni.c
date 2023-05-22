#include "koloni.h"

Koloni new_Koloni(int populasyon, char sembol)
{
    Koloni this = (Koloni)malloc(sizeof(struct koloni));

    this->populasyon = populasyon;
    this->yemekStogu = this->populasyon * this->populasyon;
    this->sembol = sembol;
    this->kaybetmeSayisi = 0;
    this->kazanmaSayisi = 0;

    this->taktikA = new_TaktikA();
    this->taktikB = new_TaktikB();

    this->uretimA = new_UretimA();
    this->uretimB = new_UretimB();

    this->savasDegerGetir = &savasDegerGetir;
    this->stokUret = &stokUret;
    this->kazan = &kazan;
    this->kaybet = &kaybet;
    this->delete_Koloni = &delete_Koloni;

    return this;
}

void kazan(Koloni this, int eklenecekStok)
{
    this->kazanmaSayisi = this->kazanmaSayisi + 1;
    this->yemekStogu = this->yemekStogu + eklenecekStok;
}

void kaybet(Koloni this, int yuzde)
{
    const int yuzdeFark = 100 - yuzde;
    this->kaybetmeSayisi = this->kaybetmeSayisi + 1;
    this->yemekStogu = (int)(((this->yemekStogu) * yuzdeFark) / 100);
    this->populasyon = (int)(((this->populasyon) * yuzdeFark) / 100);
}

int savasDegerGetir(Koloni koloni)
{
    int sayi = rand() % 2;
    if (sayi % 2)
    {
        return koloni->taktikA->super->savas();
    }
    return koloni->taktikB->super->savas();
}
void stokUret(Koloni this)
{
    int sayi = rand() % 2;
    if (sayi % 2)
    {
        this->yemekStogu = (this->yemekStogu) + this->uretimA->super->uret();
    }
    else
    {
        this->yemekStogu = (this->yemekStogu) + this->uretimB->super->uret();
    }
}

void delete_Koloni(struct koloni *koloni)
{
    if (koloni)
    {
        delete_TaktikA(koloni->taktikA);
        delete_TaktikB(koloni->taktikB);
        delete_UretimA(koloni->uretimA);
        delete_UretimB(koloni->uretimB);
        free(koloni);
    }
}
