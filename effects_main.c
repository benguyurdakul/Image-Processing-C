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

  if(argc<3){
    
    printf("Usage:<effect> <PGM image 1 >.......<PGM image n>\n\n");
    exit(1);
  }

    int i;
    int errno;
    int x;
    /* Komut satirindan gelen efekt adi */
    char *effect_name = argv[1];
    char new_filename[100];
    

    /* TODO: Bazi efektlerin ihtiyac duyabilecegi rand() rassal
     * sayi uretecini seed edin. */
    srand(time(NULL));

    


    /* argv[0]:     Programin adi
     * argv[1]:     Efekt cesidi: invert, binarize, noise, smooth
     * argv[2] ...  argv[argc-1]: Dosya adi veya adlari
     */

    for(i=2;i<argc;i++){

     PGMInfo new_pgm = pgm_read(argv[i]);
      errno = new_pgm.error;
      
      if(errno>0){

	pgm_print_error(new_pgm);
	
      }

      pgm_print_header(new_pgm);

      sprintf(new_filename,"%s.%s",argv[i],effect_name);
      //strcat fonksiyonu dongunun ikinci adiminda hata veriyor
      //hata vermesinin nedeni sanirim ilkini atarken ikincinin yapisini bozmasi
      //sscanfi arastirirken sprintf i buldum.

      if(strcmp(effect_name,"invert")==0){

	effect_invert(new_pgm.pixels,new_pgm.width,new_pgm.height);
      }

      if(strcmp(effect_name,"binarize")==0){

	effect_threshold(new_pgm.pixels,new_pgm.width,new_pgm.height,190);
      }

      x = pgm_write(new_filename,new_pgm);
      
      if(x)printf("Error  writing %s ",new_filename);

      free(new_pgm.pixels);

      
    }

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
