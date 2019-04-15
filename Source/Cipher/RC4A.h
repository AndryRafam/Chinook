#ifndef _RC4A_h
#define _RC4A_h

void RC4A_KSA (char *key, unsigned char Sbox[256]);

void RC4A_PRG (unsigned char Sbox1[256], unsigned char Sbox2[256], unsigned char *plaintext, unsigned char *ciphertext);

void RC4A_Encrypt (unsigned char *plaintext, char *key, unsigned char *ciphertext);

char *RC4A_Key();

#endif
