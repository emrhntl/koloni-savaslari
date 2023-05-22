#include <stdio.h>
#include "koloni.h"
#include "oyun.h"
#include "stdlib.h"
#include <time.h>

int main()
{
    int koloniSayisi;
    printf("Koloni sayisini giriniz: \n");
    scanf("%d", &koloniSayisi);
    getchar(); // Yeni satır karakterini temizle

    srand(time(NULL));

    Koloni *koloniler = (Koloni *)malloc(koloniSayisi * sizeof(Koloni)); // Bellekte koloniSayisi kadar yer ayırma

    for (int i = 0; i < koloniSayisi; i++)
    {
        int populasyon;
        char sembol[2]; // Karakter dizisi olarak sembolü tanımla
        printf("%d. koloninin sembolunu giriniz: ", i + 1);
        scanf("%s", sembol); // %c yerine %s kullan
        getchar();           // Yeni satır karakterini temizle
        printf("%d. koloninin populasyonunu giriniz: ", i + 1);
        scanf("%d", &populasyon);
        koloniler[i] = new_Koloni(populasyon, sembol[0]); // sembolü sembol[0] olarak geçir
    }

    system("cls"); // system("cls") yerine system("clear") kullanılabilir (Windows yerine Linux)

    Oyun oyun = new_Oyun(koloniler, koloniSayisi);
    oyun->savasBaslat(oyun);
    // Belleği serbest bırakma
    for (int i = 0; i < koloniSayisi; i++)
    {
        delete_Koloni(koloniler[i]);
    }
    free(koloniler);
    free(oyun);
    return 0;
}
