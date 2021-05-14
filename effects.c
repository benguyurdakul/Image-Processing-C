#include "effects.h"
#include <stdlib.h>

void effect_random_noise(unsigned char *pixels, int width, int height) {
    int nr_noisy_pixel = (width * height) / 5; // %20 oraninda noise ekle
    int i;

    for (i = 0; i < nr_noisy_pixel; ++i ) {
        int which_pixel = (rand() % (width * height));
        pixels[which_pixel] = (rand() % 256);
    }
}

/* TODO: Invert efekti her pikselin degerinin tumleyenini o pikselin
 * yeni degeri olarak belirler.
 */
void effect_invert(unsigned char *pixels, int width, int height) {
    int i;
    for (i=0; i<(width*height); i=i+1) {
	pixels[i] = 255-pixels[i];
    }

}

/* TODO: Verilen bir esik degerin altinda kalan pikselleri siyah,
 * uzerinde kalanlari ise beyaz yaparak 2 renkli bir resim olusturur.
 */
void effect_threshold(unsigned char *pixels, int width, int height, int threshold) {
    int i;
    for (i=0; i<(width*height); i=i+1) {
	if (pixels[i] > threshold) {
		pixels[i] = 255;
        }
        else {
		pixels[i] = 0;
        }
    }

}

//kullanicinin istedigi yuzdelikle her pikselin rengini siyaha (0)
//yakinlastirarak grilestirme/koyulastirma efekti
void effect_darker(unsigned char *pixels, int width, int height, int percentage) {
	int dark_value, i;
	int size = width * height;
	for (i=0; i<size; i=i+1) {
        	dark_value = (pixels[i] * percentage)/100;
		pixels[i] = pixels[i]-dark_value;		
        }

}


//fotografi sag 90 derece donduren efekt
void effect_turn_90 (unsigned char *pixels, int width, int height) {
	int i, k, j=0;
	int size = width*height;
//orijinal diziyi saklamak icin yeni yer aciyoruz. 
	unsigned char *copy_pixels = malloc(size); 
	if (copy_pixels == NULL) exit(1);
	for (i=0; i<size; i=i+1) {
		copy_pixels[i] = pixels[i];
	}
//orijinal diziyi, saklanmis diziyi kullanarak yeniden sekillendiriyoruz
	for (i=0; i<width; i=i+1) {
		for (k=(height-1); k>=0; k=k-1) {
			pixels[j] = copy_pixels[k*width + i]; 
			j = j + 1;
		}

        }
	free(copy_pixels); //yeri bosaltiyoruz
}

//fotografi 180 derece donduren efekt
void effect_turn_180 (unsigned char *pixels, int width, int height) {
	int temp, i, k, size = width*height;
	int end = size-1;  //sonuncu indeks
	for (i=0; i<size/2; i=i+1) { //yarisini degistirmek yetiyor
		temp = pixels[i]; 
		pixels[i] = pixels[end-i]; //yer degistiriyoruz
		pixels[end-i] = temp; 
        }
}

