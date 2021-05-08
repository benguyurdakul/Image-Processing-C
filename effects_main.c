

   #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Kendi baslik dosyalarimizi include ediyoruz */
#include "pgm.h"
#include "effects.h"

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
	if(argc<3){
		fprintf(stderr," Usage: ./pgm_efekt %s <PGM image 1> <PGM image 2> ... <PGM image N>",argv[0]);
		return 1;
	}

    int i;
    /* Komut satirindan gelen efekt adi */
    char *effect_name = argv[1];
    char newfile[60];
    PGMInfo pgm_info;

    /* TODO: Bazi efektlerin ihtiyac duyabilecegi rand() rassal
     * sayi uretecini seed edin. */
    srand(time(NULL));
    //int rassal = rand();


    /* argv[0]:     Programin adi
     * argv[1]:     Efekt cesidi: invert, binarize, noise, smooth
     * argv[2] ...  argv[argc-1]: Dosya adi veya adlari
     */

    /* Butun argumanlari gez. Her biri bir resim dosyasi adi */
        /* TODO: PGM dosyasini oku */
        /* Hata olduysa ekrana hata mesajini yazdir */
        /* Hata yoksa resmin baslik bilgisini ekrana yazdir,
         * resme efekt uygula ve yeni dosyaya kaydet. */
            /* Yeni bir string olustur. Bu string efekt uygulanmis
             * dosyanin adini tutacaktir. */

            /* Hangi efekt istendiyse ilgili fonksiyon cagir*/
    for(i=2;i<argc;i++){
    	pgm_info=pgm_read(argv[i]);
    	if(pgm_info.error>0){
    		pgm_print_error(pgm_info);
    	}
    	else{
    		sprintf(newfile,"%s.%s",argv[i],effect_name);

    		if(strcmp(effect_name,"noise")==0){
    			effect_random_noise(pgm_info.pixels,pgm_info.width,pgm_info.height);
    		}
    		else if(strcmp(effect_name,"invert")==0){
    			effect_invert(pgm_info.pixels,pgm_info.width,pgm_info.height);
    		}
    		else if(strcmp(effect_name,"binarize")==0){
    			effect_threshold(pgm_info.pixels,pgm_info.width,pgm_info.height,160);
    		}
    	}
    }

            /* TODO: Yeni PGM dosyasini olusturun. Eger basarisiz olursa
             * ekrana yazdirin. */
    pgm_write(newfile,pgm_info);
    if(pgm_write(newfile,pgm_info)!=0){
    	fprintf(stderr,"Can't write %s\n",newfile);
    }

            /* TODO: pgm_info'daki pixels dizisini free() etmeliyiz. */
    free(pgm_info.pixels);

    return 0;
}
