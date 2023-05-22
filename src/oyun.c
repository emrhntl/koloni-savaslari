#include "oyun.h"
Oyun new_Oyun(Koloni *koloniler, int koloniSayisi)
{
    Oyun this = (Oyun)malloc(sizeof(struct oyun));
    this->koloniSayisi = koloniSayisi;
    this->kaybedenKoloniSayisi = 0;
    this->koloniler = (Koloni *)malloc(koloniSayisi * sizeof(Koloni));
    for (int i = 0; i < koloniSayisi; i++)
    {
        this->koloniler[i] = koloniler[i];
    }
    this->kaybedenKoloniler = (Koloni *)malloc((koloniSayisi - 1) * sizeof(Koloni));
    this->savasBaslat = &savasBaslat;
    this->delete_Oyun = &delete_Oyun;
    return this;
}
void savasBaslat(Oyun this)
{
    int turSayisi = 0;
    durumYazdir(this, turSayisi);
    while ((this->koloniSayisi) - (this->kaybedenKoloniSayisi) > 1)
    {
        for (int i = 0; i < this->koloniSayisi; i++)
        {
            if (this->koloniler[i] != NULL)
            {
                for (int j = i + 1; j < this->koloniSayisi; j++)
                {
                    if (this->koloniler[j] != NULL)
                    {
                        savastir(this, this->koloniler[i], this->koloniler[j]);
                    }
                }
            }
        }
        turSayisi++;
        for (int i = 0; i < this->koloniSayisi; i++)
        {
            if (this->koloniler[i] != NULL)
            {
                turSonu(this, this->koloniler[i]);
                if (this->koloniler[i] != NULL)
                {
                    this->koloniler[i]->stokUret(this->koloniler[i]);
                }
            }
        }
        durumYazdir(this, turSayisi);
    }
}

void savastir(Oyun this, Koloni koloni1, Koloni koloni2)
{
    int deger1 = koloni1->savasDegerGetir(koloni1);
    int deger2 = koloni2->savasDegerGetir(koloni2);
    int yuzde = abs(deger1 - deger2) / 10;
    int kazanan;

    if (deger1 > deger2)
    {
        koloni1->kazan(koloni1, (koloni2->yemekStogu * yuzde) / 100);
        koloni2->kaybet(koloni2, yuzde);
        kazanan = 0;
    }
    else if (deger2 > deger1)
    {
        koloni2->kazan(koloni2, (koloni1->yemekStogu * yuzde) / 100);
        koloni1->kaybet(koloni1, yuzde);
        kazanan = 1;
    }
    else
    {
        if (koloni1->populasyon > koloni2->populasyon)
        {
            koloni1->kazan(koloni1, 0);
            koloni2->kaybet(koloni2, 0);
            kazanan = 0;
        }
        else if (koloni2->populasyon > koloni1->populasyon)
        {
            koloni1->kaybet(koloni1, 0);
            koloni2->kazan(koloni2, 0);
            kazanan = 1;
        }
        else
        {
            int random = rand() % 2;
            if (random % 2)
            {
                koloni1->kazan(koloni1, 0);
                koloni2->kaybet(koloni2, 0);
                kazanan = 0;
            }
            else
            {
                koloni1->kaybet(koloni1, 0);
                koloni2->kazan(koloni2, 0);
                kazanan = 1;
            }
        }
    }
    if (kazanan)
    {
        koloniKontrol(this, koloni2);
    }
    else
    {
        koloniKontrol(this, koloni1);
    }
}

void koloniKontrol(Oyun this, Koloni koloni)
{
    if (koloni->populasyon <= 0 || koloni->yemekStogu <= 0)
    {
        this->kaybedenKoloniler[this->kaybedenKoloniSayisi] = koloni;
        this->kaybedenKoloniSayisi = this->kaybedenKoloniSayisi + 1;
        Koloni *guncelKoloniDizisi = (Koloni *)malloc((this->koloniSayisi) * sizeof(Koloni));
        for (int i = 0; i < this->koloniSayisi; i++)
        {
            if (this->koloniler[i] != koloni)
            {
                guncelKoloniDizisi[i] = this->koloniler[i];
            }
            else
            {
                guncelKoloniDizisi[i] = NULL;
            }
        }
        this->koloniler = guncelKoloniDizisi;
    }
}

void turSonu(Oyun this, Koloni koloni)
{
    koloni->populasyon = koloni->populasyon * 1.2;
    koloni->yemekStogu = koloni->yemekStogu - ((koloni->populasyon) * 2);
    koloniKontrol(this, koloni);
}
void yasayanYazdir(Koloni koloni)
{
    printf("%-12c\t", koloni->sembol);
    printf("%-19d\t", koloni->populasyon);
    printf("%-19d\t", koloni->yemekStogu);
    printf("%-13d\t", koloni->kazanmaSayisi);
    printf("%-14d\n", koloni->kaybetmeSayisi);
}

void kaybedenYazdir(Koloni koloni)
{
    printf("%-12c\t", koloni->sembol);
    printf("%-19s\t", "--");
    printf("%-19s\t", "--");
    printf("%-13s\t", "--");
    printf("%-24s\n", "--");
}



void durumYazdir(Oyun this, int turSayisi)
{
    printf("----------------------------------------------------------------------------------------------------------\n");
    printf("Tur Sayisi: %d\n", turSayisi);
    printf("Koloni\t\tPopulasyon\t\tYemek stogu\t\tKazanma\t\tKaybetme\n");
    for (int i = 0, j = 0; i < this->koloniSayisi; i++)
    {
        if (this->koloniler[i] != NULL)
        {
            yasayanYazdir(this->koloniler[i]);
        }
        else
        {
            kaybedenYazdir(this->kaybedenKoloniler[j]);
            j++;
        }
    }
    printf("----------------------------------------------------------------------------------------------------------\n");
}

void delete_Oyun(struct oyun *game)
{
    if (game)
    {
        if (game->koloniler)
        {
            free(game->koloniler);
        }
        if (game->kaybedenKoloniler)
        {
            free(game->kaybedenKoloniler);
        }
        free(game);
    }
}
