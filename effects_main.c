#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Kendi baslik dosyalarimizi include ediyoruz */
#include "pgm.h"
#include "effects.h"
#include <time.h>
/* PROGRAMIN ORNEK KULLANIMI:
 *
 *      $ ./pgm_efekt
 *      Usage: ./pgm_efekt <invert|binarize|noise|smooth> <PGM image 1> <PGM image 2> ... <PGM image N>
 *
 *      $ ./pgm_efekt invert effect_images/man_ascii.pgm
 *      (Invert efekti uygulanan resim effect_images/man_ascii.pgm.invert olarak kaydedilir)
 */

int main(int argc, char *argv[])
{
    /* TODO: Program efekt adi ve EN AZ 1 resim dosyasi olmak uzere EN AZ
     * 2 arguman istemektedir. Bu bilgiye gore asagidaki if()'in icerisini
     * doldurun.
     */

    /* Komut satirindan gelen efekt adi */
    char *effect_name = argv[1];
    
    

    /* TODO: Bazi efektlerin ihtiyac duyabilecegi rand() rassal
     * sayi uretecini seed edin. */
    

    


    /* argv[0]:     Programin adi
     * argv[1]:     Efekt cesidi: invert, binarize, noise, smooth
     * argv[2] ...  argv[argc-1]: Dosya adi veya adlari
     */

      //strcat fonksiyonu dongunun ikinci adiminda hata veriyor
      //hata vermesinin nedeni sanirim ilkini atarken ikincinin yapisini bozmasi
      //sscanfi arastirirken sprintf i buldum.

      
      
    

    /* Butun argumanlari gez. Her biri bir resim dosyasi adi */
        /* TODO: PGM dosyasini oku */
        /* Hata olduysa ekrana hata mesajini yazdir */
        /* Hata yoksa resmin baslik bilgisini ekrana yazdir,
         * resme efekt uygula ve yeni dosyaya kaydet. */
            /* Yeni bir string olustur. Bu string efekt uygulanmis
             * dosyanin adini tutacaktir. */

            /* Hangi efekt istendiyse ilgili fonksiyon cagir*/

            /* TODO: Yeni PGM dosyasini olusturun. Eger basarisiz olursa
             * ekrana yazdirin. */

            /* TODO: pgm_info'daki pixels dizisini free() etmeliyiz. */

    return 0;
}
