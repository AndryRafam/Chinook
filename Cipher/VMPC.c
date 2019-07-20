// VMPC (Variably Modified Permutation Composition)

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../Header/function.h"
#include "../Header/VMPC.h"

void VMPC_KSA (char *key, unsigned char *Sbox) // Key scheduling algorithm
{
	int len = strlen(key);
	int j = 0;

	for (int i = 0; i < 256; i++)
		Sbox[i] = i;

	for (int i = 0; i < 256; i++)
	{
		j = ((j + Sbox[i] + key[i % len]) % 256);
		swap(&Sbox[i], &Sbox[j]);
	}
}

void VMPC_PRGA (unsigned char *Sbox, unsigned char *plaintext, unsigned char *ciphertext) // Pseudo random generator
{
	int i = 0;
	int j, K;
		
	for (size_t n = 0, len = strlen(plaintext); n < len; n++)
	{
		j = Sbox[(j + Sbox[i]) % 256];
		K = Sbox[Sbox[(Sbox[j] + 1) % 256]];
		ciphertext[n] = K^plaintext[n];
		swap (&Sbox[i], &Sbox[j]);
		i = (i + 1) % 256;			
	}
}

void VMPC_Encrypt (unsigned char *plaintext, char *key, unsigned char *ciphertext)
{
	unsigned char Sbox[256];
	VMPC_KSA (key, Sbox);
	VMPC_PRGA (Sbox, plaintext, ciphertext);
}

char *VMPC_key()
{
	srand(time(0));
	char *key = malloc(sizeof(char) * 128);
	int count, key_gen;

	for (int i = 0; i < 128; i++)
	{
		count = rand() % 2;
		key_gen = rand() % 26;

		if (count == 0)
			key[i] = (char)((key_gen - 65) % 26 + 65);
		else
			key[i] = (char)((key_gen - 97) % 26 + 97);
	}
	return key;
}
		
