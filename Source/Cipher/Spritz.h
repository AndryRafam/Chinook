#ifndef _Spritz_h
#define _Spritz_h

void KSA (char *key, unsigned char Sbox[256]);

void PRG (unsigned char Sbox[256], unsigned char *plaintext, unsigned char *ciphertext);

void SPRITZ_Encrypt (unsigned char *plaintext, char *key, unsigned char *ciphertext);

char *SPRITZ_Key();

#endif
