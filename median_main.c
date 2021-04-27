#include <stdio.h>
#include <stdlib.h>

#include "pgm.h"

#define N_IMAGES 9


/* TODO: Istediginiz bir siralama algoritmasiyla pixels dizisini
 * siralayin ve ortanca elemanin degerini geri dondurun. */
unsigned char sort_and_get_median(unsigned char *pixels, int size) {
}

int main(int argc, const char *argv[])
{
    int i;
    
    /* 9 adet resim var */
    PGMInfo images[N_IMAGES];
    
    /* Temizlenmis resim icin baslik kismini hazirlayalim */
    
    /* Temizlenmis resmin pikselleri icin yer ayiralim */
  
    /* Resimleri sirayla images[]'in ilgili elemanina okuyun.
     * Resimler median_images/ dizini altinda 1'den 9'a kadar adlandirilmis
     * olup uzantilari pgm'dir. Ornek: 1.pgm, 2.pgm, .. */
        
        /*  image_file'in icerisine okunacak dosya adini yazin (ipucu: sprintf()) */
        
        /* Resim dosyasini pgm_read() ile images[i] icerisine okuyun. */

        /* Hata olusursa programi sonlandir */

        /* Bilgileri ekrana yazdir */

    /* TODO: Median filtreleme */
    //for () {

    //}
    
    /* Temizlenmis resmi kaydedin. */
    // pgm_write("median_images/filtered.pgm", filtered);
    
    /*  Temizlenmis resmin piksel alanini free() edin */

    /* Tum fotograflarin piksel alanlarini free() edin */

    return 0;
}
