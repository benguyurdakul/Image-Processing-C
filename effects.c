#include "effects.h"
#include <stdlib.h>

void effect_random_noise(unsigned char *pixels, int width, int height) {
    int nr_noisy_pixel = (width * height) / 5; // %5 oraninda noise ekle
    int i;

    for (i = 0; i < nr_noisy_pixel-1; ++i ) {
        int which_pixel = (rand() % (width * height));
        pixels[which_pixel] = (rand() % 256);
    }
}

/* TODO: Invert efekti her pikselin degerinin tumleyenini o pikselin
 * yeni degeri olarak belirler.
 */
void effect_invert(unsigned char *pixels, int width, int height) {
	int i;
	for(i=0;i<height*width;i++){
		pixels[i]=255-pixels[i];
	}

}

/* TODO: Verilen bir esik degerin altinda kalan pikselleri siyah,
 * uzerinde kalanlari ise beyaz yaparak 2 renkli bir resim olusturur.
 */
void effect_threshold(unsigned char *pixels, int width, int height, int threshold) {
	int i;
	for(i=0;i<height*width;i++){
		if(pixels[i]<threshold)
			pixels[i]=255;
		else
			pixels[i]=0;
	}

}

void upside_down(unsigned char *pixels,int width,int height){
	int i;
	for(i=0;i<height*width;i++){
		pixels[i]=pixels[height*width-(i+1)];
	}
}



void mirror_effect(unsigned char *pixels,int width,int height){
	int i,k;
	if(width%2==0){
		int j=width/2;
	}
	else
		j=(width-1)/2;
    for(i=0;i<height-1;i++){
    	for(k=0;k<j;k++){
    		pixels[i]=pixels[width-1];
    	}

    }

}


void dark_effect(unsigned char *pixels,int width,int height,int dark){
	int i;
	for(i=0;i<height*width;i++){
		pixels[i]=pixels[i]-dark;
	}
}

