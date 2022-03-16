#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#include "pgm.h"

/* PGM dosyasinin baslik bilgilerini ekrana yazdiran fonksiyon */
void pgm_print_header(PGMInfo pgm_info) {
    printf("This is a %s type PGM image containing %d x %d pixels\n",
           pgm_info.signature,
           pgm_info.width,
           pgm_info.height);
}

PGMInfo pgm_read(const char *filename) {
    /* Bu fonksiyon filename stringi ile verilen dosyayi fopen()
     * ile read kipinde acmali ve PGM dosyasinin basligini ve
     * piksellerini PGMInfo turunden bir struct'a atmalidir.
     *
     * Fonksiyon geriye bu struct'i dondurmelidir.
     */

    /* PGMInfo turunden bir degisken yaratip, error uyesini 0 yaptik. */
    PGMInfo pgm_info = {.error = 0};

    /* Dosyadaki satirlari okumak icin bir tampon. */
    char line[LINE_MAX];
    char* buffer;
    char en_boy[LINE_MAX];
    int i = 0,x = 0;
    int read = 0;

    /* TODO: Dosyayi acin. Eger dosya acilamazsa pgm_info'nun error
     * uyesini PGM_ERROR_READ yapip fonksiyonu sonlandirin. */
    
    FILE* pgm = fopen(filename,"r");

    if(pgm==NULL){

      pgm_info.error = PGM_ERROR_READ;
      return pgm_info;
    }


    /* TODO: PGM imzasi P2 veya P5 degilse dosyayi kapatin, error'u
     * PGM_ERROR_SIGNATURE yapip fonksiyonu sonlandirin. */

    buffer = fgets(line,LINE_MAX,pgm);
    sscanf(line,"%s ",pgm_info.signature);
    
    

    if(strcmp(pgm_info.signature,"P5")!=0 && strcmp(pgm_info.signature,"P2")!=0){

      pgm_info.error = PGM_ERROR_SIGNATURE;
      return pgm_info;
    }
    
    /* Comment satirini oku. */
    buffer = fgets(line,LINE_MAX,pgm);
    sscanf(line,"%s",pgm_info.comment);

    /* TODO: En ve boyu oku */
    buffer = fgets(line,LINE_MAX,pgm);

    while (line[i]!=' '){

      en_boy[i] = line[i];
      i++;
    }
    pgm_info.width = atoi(en_boy);

    i++;

    while(line[i]!='\n'){
      en_boy[x] = line[i];
      i++;
      x++;
    }

    pgm_info.height = atoi(en_boy);

    /* Max piksel degerini oku */

    buffer = fgets(line,LINE_MAX,pgm);
    pgm_info.max_pixel_value = (char) atoi(line);

    /* TODO: pgm_info.pixels icin malloc() ile yer ayiralim.
     * Bir piksel bellekte 1 bayt yer istiyor, unutmayalim. */

    pgm_info.pixels = malloc(pgm_info.width*pgm_info.height);


    /* TODO: malloc() ile yer ayrilamazsa dosyayi kapatin, error'u
     * PGM_ERROR_MALLOC yapip fonksiyonu sonlandirin.*/

    if(pgm_info.pixels==NULL){

      pgm_info.error = PGM_ERROR_MALLOC;
      return pgm_info;
    }


    /* 2 farkli dosya bicimi, 2 farkli okuma bicimi.
     * P2 yani ASCII olanda dosyayi fgets() ile satir satir okuyoruz.
     * Okudugumuz satirin sonundaki '\n' karakterini kaldiriyoruz
     * ve elimizde kalan string'i atoi() ile sayiya cevirip pixels
     * dizisine kaydediyoruz.
     */
    
    if(strcmp(pgm_info.signature,"P2")==0){
      
      
      for(i=0;i<pgm_info.width*pgm_info.height;i++){

	buffer = fgets(line,LINE_MAX,pgm);
	
	line[strlen(line)-1] = '\0';

	pgm_info.pixels[i] = (char) atoi(line); 
      }

      read = i;
    }
     /* P5 yani binary olanda ise dogrudan fread() ile bir kerede pixels'in icerisine
     * okuma yapiyoruz.
     */

    else{

      read = fread(pgm_info.pixels,1,pgm_info.width*pgm_info.height,pgm);
    }

    /* Eger dogru okuma yapamadiysaniz programiniz assert() sayesinde
     * yarida kesilecek. */
    printf("Read %d bytes. (Should be: %d)\n", read, pgm_info.width * pgm_info.height);
    assert(read == (pgm_info.width * pgm_info.height));

    return pgm_info;
    
    fclose(pgm);
}

int pgm_write(const char *filename, PGMInfo pgm_info) {
    /* Bu fonksiyon filename stringiyle verilen dosyayi write kipinde acarak
     * pgm_info'nun icindeki baslik ve piksel bilgilerini dosyaya yazar.
     * Boylece yeni bir PGM resim dosyasi diske kaydedilmis olur.
     *
     * Fonksiyon herhangi bir hatada 1, basari durumunda 0 dondurmelidir.
     */

    int i;
    FILE *pgm;
    

    /* TODO: Dosyayi write kipinde acin. Acma basarisiz olursa fonksiyon
     * 1 dondurerek sonlanmalidir. */

    pgm = fopen(filename,"w");

    if(!pgm)return 1;

    /* TODO: Baslik yapisini fprintf() ile dosyaya yazin */
    fprintf(pgm,"%s\n%s\n%d %d\n%d\n",pgm_info.signature,pgm_info.comment,pgm_info.width,pgm_info.height,pgm_info.max_pixel_value);

    /* TODO: 2 farkli dosya bicimi, 2 farkli yazma bicimi */

    if(strcmp(pgm_info.signature,"P2")==0){

      for(i=0;i<pgm_info.width*pgm_info.height;i++){

	fprintf(pgm,"%d\n",pgm_info.pixels[i]);
      }
    }

    else{
      
      fwrite(pgm_info.pixels,1,pgm_info.width*pgm_info.height,pgm);
    }

    
    /* Dosyayi kapatalim. */
    fclose(pgm);
    return 0;
}

