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
    int i = 0;
    int read = 0;

    /* TODO: Dosyayi acin. Eger dosya acilamazsa pgm_info'nun error
     * uyesini PGM_ERROR_READ yapip fonksiyonu sonlandirin. */
    FILE *fp=fopen(filename,"r");//dosya actik
    if(fp==NULL){//kontrol
    	pgm_info.error=1;//error kodunu dosya hatasina esitledik
    	return pgm_info;
    }


    /* TODO: PGM imzasi P2 veya P5 degilse dosyayi kapatin, error'u
     * PGM_ERROR_SIGNATURE yapip fonksiyonu sonlandirin. */
    if(strcmp(pgm_info.signature,"P2")!=0 || strcmp(pgm_info.signature,"P5")!=0){
    	pgm_info.error=2;
    	return pgm_info;
    }
    /*if((pgm_info.signature[1]!='2') || (pgm_info.signature[1]!='5') ){//kontrol
    	pgm_info.error=2;//error kodunu imza hatasina esitledik
    	return pgm_info;
    }*/

    /* Comment satirini oku. */
    //fscanf(pgm,"%s",pgm_info.comment);
    int ch=fgetc(fp);
    if(ch=='#'){
    	while(ch!=EOF){
    		fscanf(ch,"%c",pgm_info.comment);

    	}
    }

    /* TODO: En ve boyu oku */
    fscanf(pgm,"%d",pgm_info.widht);//en
    fscanf(pgm,"%d",pgm_info.height);//boy

    /* Max piksel degerini oku */
    fscanf(pgm,"%d",pgm_info.max_pixel_value);

    /* TODO: pgm_info.pixels icin malloc() ile yer ayiralim.
     * Bir piksel bellekte 1 bayt yer istiyor, unutmayalim. */
    pgm_info.pixels=malloc(pgm_info.width*pgm_info.height);


    /* TODO: malloc() ile yer ayrilamazsa dosyayi kapatin, error'u
     * PGM_ERROR_MALLOC yapip fonksiyonu sonlandirin.*/
    		if(pgm_info.pixels==NULL){
    			fclose(pgm);
    			pgm_info.error=3;
    			return pgm_info;
    		}


    /* 2 farkli dosya bicimi, 2 farkli okuma bicimi.
     * P2 yani ASCII olanda dosyayi fgets() ile satir satir okuyoruz.
     * Okudugumuz satirin sonundaki '\n' karakterini kaldiriyoruz
     * ve elimizde kalan string'i atoi() ile sayiya cevirip pixels
     * dizisine kaydediyoruz.
     *
     * P5 yani binary olanda ise dogrudan fread() ile bir kerede pixels'in icerisine
     * okuma yapiyoruz.
     */

    switch(pgm_info.signature[1]){
    case'2':
    	for(i=0;i<pgm_info.width*pgm_info.height;i++){
    		fgets(line,sizeof(line),pgm);

    		if(line!='\n'){
    			pgm_into.pixels[i]=atoi(line);
    			read++;
    		}

    	}

     break;

    case'5':
    read=fread(pgm_info.pixels,pgm_info.width*pgm_info.height,1,pgm);
    break;
    }
    fclose(pgm);

    /* Eger dogru okuma yapamadiysaniz programiniz assert() sayesinde
     * yarida kesilecek. */
    printf("Read %d bytes. (Should be: %d)\n", read, pgm_info.width * pgm_info.height);
    assert(read == (pgm_info.width * pgm_info.height));

    return pgm_info;
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
    pgm=fopen(filename,"w");
    if(pgm==NULL){
    	return 1;
    }

    /* TODO: Baslik yapisini fprintf() ile dosyaya yazin */
    fprintf(pgm,"%s\n",pgm_info,signature);
    fprintf(pgm,"%s",pgm_info.comment);
    fprintf(pgm,"%d\n",pgm_info.width);
    fprintf(pgm,"%d\n",pgm_info.height);
    fprintf(pgm,"%d\n",pgm_info.max_pixel_value);


    /* TODO: 2 farkli dosya bicimi, 2 farkli yazma bicimi */
    switch(pgm_info.signature[1]{
    case'2':
    for(i=0;i<pgm_info.width*pgm_info.height-1,i++){
    	fprintf(pgm,"%d\n",pgm_info.pixels[i])
    }
    break;
    case'5';
    fwrite(pgm_info.pixels,pgm_info.width*pgm_info.height,1,pgm);
    break;

    }
    /* Dosyayi kapatalim. */
    fclose(pgm);
    return 0;
}

