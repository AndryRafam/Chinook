/* RC4A implementation */

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "function.h"

void RC4A_KSA (char *key, unsigned char Sbox[256])
{
	for (int i = 0; i < 256; i++)
		Sbox[i] = i;

	int j = 0;

	for (int i = 0; i < 256; i++)
	{
		j = (j + Sbox[i] + key[i % strlen(key)]) % 256;
		swap(&Sbox[i], &Sbox[j]);
	}
	return;
}

void RC4A_PRG (unsigned char Sbox1[256], unsigned char Sbox2[256], unsigned char *plaintext, unsigned char *ciphertext_RC4A)
{
	int i = 0;
	int j1 = 0, j2 = 0;
	
	for (int n = 0; n < strlen(plaintext); n++)
	{
		i = (i + 1) % 256;
		j1 = (j1 + Sbox1[i]) % 256;
		swap(&Sbox1[i], &Sbox1[j1]);
		int K1 = Sbox2[(Sbox1[i] + Sbox1[j1]) % 256];
		ciphertext_RC4A[n] = K1^plaintext[n];
	}
	
	for (int k = 0; k < strlen(plaintext); k++)
	{
		i = (i + 1) % 256;
		j2 = (j2 + Sbox2[i]) % 256;
		swap(&Sbox2[i], &Sbox2[j2]);
		int K2 = Sbox1[(Sbox2[i] + Sbox2[j2]) % 256];
		ciphertext_RC4A[k] = K2^plaintext[k];
	}
	return;
}

void RC4A_Encrypt (unsigned char *plaintext, char *key, unsigned char *ciphertext_RC4A)
{
	unsigned char Sbox1[256];
	unsigned char Sbox2[256];

	RC4A_KSA (key,Sbox1);
	RC4A_KSA (key,Sbox2);

	RC4A_PRG (Sbox1,Sbox2,plaintext,ciphertext_RC4A);

	return;
}

/* Generating 128 bit key long */
char *RC4A_Key()
{
	srand(time(NULL));
	int key, count;

	char *result = malloc(sizeof(char) * 128);
	assert(result != NULL);

	for (int i = 0; i < 128; i++)
	{
		count = rand() % 2;
		key = rand() % 128;

		if (count == 0)
			result[i] = (char)((key-65) % 26 + 65);
		else
			result[i] = (char)((key-97) % 26 + 97);
	}
	return result;
}
