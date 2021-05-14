#ifndef _EFFECTS_H_
#define _EFFECTS_H_

/* Efekt fonksiyonlari icin bildirimler */

void effect_invert(unsigned char *pixels, int width, int height);
void effect_threshold(unsigned char *pixels, int width, int height, int threshold);
void effect_random_noise(unsigned char *pixels, int width, int height);
void effect_darker(unsigned char *pixels, int width, int height, int percentage);
void effect_turn_90(unsigned char *pixels, int width, int height);
void effect_turn_180(unsigned char *pixels, int width, int height);

#endif

