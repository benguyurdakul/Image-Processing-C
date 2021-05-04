#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Kendi baslik dosyalarimizi include ediyoruz */
#include "pgm.h"
#include "effects.h"
#include<time.h>


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
    if(argc < 3) {
	printf("invalid command!\n Usage: ./pgm_efekt <invert|binarize|noise|smooth> <PGM image 1> <PGM image 2> ... <PGM image N>");
	exit(1);
    }



    int i;
    /* Komut satirindan gelen efekt adi */
    char *effect_name = argv[1];

    /* TODO: Bazi efektlerin ihtiyac duyabilecegi rand() rassal
     * sayi uretecini seed edin. */
    srand(time(NULL));
    int rand_value = rand() % 256;


    /* argv[0]:     Programin adi
     * argv[1]:     Efekt cesidi: invert, binarize, noise
     * argv[2] ...  argv[argc-1]: Dosya adi veya adlari
     */

    /* Butun argumanlari gez. Her biri bir resim dosyasi adi */
        /* TODO: PGM dosyasini oku */
        /* Hata olduysa ekrana hata mesajini yazdir */
        /* Hata yoksa resmin baslik bilgisini ekrana yazdir,
         * resme efekt uygula ve yeni dosyaya kaydet. */
            /* Yeni bir string olustur. Bu string efekt uygulanmis
             * dosyanin adini tutacaktir. */

    PGMInfo retval;  //geridonus degeri
    char *new_doc;   //saklanacak string
    for (i=2; i<argc; i=i+1) {
	retval = pgm_read(argv[i]);
        if (retval.error == 1 || retval.error == 2 || retval.error == 3) {
		printf("ERROR! THE PGM FILE CANNOT BE READ\n");
                exit(1);
        }

	pgm_print_header(retval);
  
	if (strcmp(effect_name, "invert") == 0) {
		effect_invert(retval.pixels, retval.width, retval.height);
        }
        else if (strcmp(effect_name, "binarize") == 0) {
		effect_threshold(retval.pixels, retval.width, retval.height, rand_value);
        }
        else if (strcmp(effect_name, "noise") == 0) {
		effect_random_noise(retval.pixels, retval.width, retval.height);
        }
        /*else { //new effect 1
		effect_smooth(retval.pixels, retval.width, retval.height);
        } */
	pgm_write(new_doc, retval);
        if (new_doc == NULL) {
        	printf("ERROR! THE PGM FILE COULD NOT BE CREATED");
		exit(1);
        }

    }

            /* Hangi efekt istendiyse ilgili fonksiyon cagir*/

            /* TODO: Yeni PGM dosyasini olusturun. Eger basarisiz olursa
             * ekrana yazdirin. */
  

            /* TODO: pgm_info'daki pixels dizisini free() etmeliyiz. */
    int size = retval.height * retval.width;
    for (i=0; i<size; i=i+1) {
	free(&retval.pixels[i]);
    }


    return 0;
}
