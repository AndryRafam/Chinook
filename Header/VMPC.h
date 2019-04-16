#ifndef _VMPC_h
#define _VMPC_h

void VMPC_Encrypt (unsigned char *plaintext, char *key, unsigned char *ciphertext);
void VMPC_KSA (char *key, unsigned char *Sbox);
void VMPC_PRGA (unsigned char *Sbox, unsigned char *plaintext, unsigned char *ciphertext);
char *VMPC_key();

#endif
