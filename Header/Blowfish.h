#ifndef _Blowfish_h
#define _Blowfish_h

#include <stdint.h>

void Blowfish_Init (unsigned char *key, int keybytes);
void Blowfish_Encipher (uint32_t *L, uint32_t *R);
unsigned char *Blowfish_key();
uint32_t F (uint32_t x);

#endif
