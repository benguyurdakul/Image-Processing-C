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
    if(argc < 3) {
	printf("invalid command!\n Usage: ./pgm_efekt <invert|binarize|noise|smooth> <PGM image 1> <PGM image 2> ... <PGM image N>\n");
	exit(1);
    }



    int i;
    /* Komut satirindan gelen efekt adi */
    char *effect_name = argv[1];

    /* TODO: Bazi efektlerin ihtiyac duyabilecegi rand() rassal
     * sayi uretecini seed edin. */
    srand(time(NULL));
    int rand_value = 1 + rand() % 254; //0 ve 255 dahil olmasin diye
    printf("rand value : %d\n",rand_value);


    /* argv[0]:     Programin adi
     * argv[1]:     Efekt cesidi: invert, binarize, noise, darker, turn
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

            /* TODO: Yeni PGM dosyasini olusturun. Eger basarisiz olursa
             * ekrana yazdirin. */

    PGMInfo retval;    //geridonus degeri
    char new_doc[100]; //saklanacak string
    int user_value;    //kullanicidan alinacak deger
    int a;             //uyariyi yok etmek -> scanf icin

    for (i=2; i<argc; i=i+1) {
	retval = pgm_read(argv[i]);
        if (retval.error > 0) {
		printf("ERROR! THE PGM FILE CANNOT BE READ\n");
                exit(1);
        }

	pgm_print_header(retval);

        sprintf(new_doc, "%s.%s",argv[i],effect_name); //NEDEN?
  
	if (strcmp(effect_name, "invert") == 0) {
		effect_invert(retval.pixels, retval.width, retval.height);
        }

        else if (strcmp(effect_name, "binarize") == 0) {
		effect_threshold(retval.pixels, retval.width, retval.height, rand_value);
        }

        else if (strcmp(effect_name, "noise") == 0) {
		effect_random_noise(retval.pixels, retval.width, retval.height);
        }
	
	else if (strcmp(effect_name, "darker") == 0) {
               //koyulastirma yuzdesini kullanicidan alip fonksiyona gonderecegiz
		printf("\nEnter the percentage: \n"); 
		a = scanf("%d", &user_value);
               //uyariyi yok etmek icin a ya atadim, onemsiz
		effect_darker(retval.pixels, retval.width, retval.height, user_value);
        } 

	else if (strcmp(effect_name, "turn") == 0) {
               //iki secenek var, kullanicidan secim yapmasini istiyoruz (90 yada 180)
		printf("\nselect the degree of rotation (90 or 180) : \n");
		a = scanf("%d", &user_value);
	       //uyariyi yok etmek icin a ya atadim, onemsiz

		switch (user_value) {
		case 90 :
			effect_turn_90(retval.pixels, retval.width, retval.height);
//Yeni olusturulan dosyanın width ve height degerleri guncellenmeli!
//Bu sebeple retval.width ve retval.height degerlerini guncelliyorum
			int temp = retval.width;   
			retval.width = retval.height; 
			retval.height = temp; 
			break;

		case 180 :
			effect_turn_180(retval.pixels, retval.width, retval.height);
			break;
                }
	}  
     
	if (pgm_write(new_doc, retval) != 0) {
        	printf("ERROR! THE PGM FILE COULD NOT BE CREATED");
		exit(1);
        }

    }

            /* TODO: pgm_info'daki pixels dizisini free() etmeliyiz. */
    free(retval.pixels);


    return 0;
}
