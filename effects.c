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
