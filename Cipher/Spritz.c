/* Spritz implementation */

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "../Header/function.h"

void KSA (char *key, unsigned char S[256]) // Key scheduling algorithm
{
	for (int i = 0; i < 256; i++)
		S[i] = i;

	int j = 0;
	
	for (int i = 0; i < 256; i++) {
		j = (j + S[i] + key[i % strlen(key)]) % 256;
		swap (&S[i], &S[j]);
	}
}

void PRG (unsigned char S[256], unsigned char *plaintext, unsigned char *ciphertext) // Pseudo random generator
{
	int i = 0, j = 0, k = 0, w = 0;
	srand(time(NULL));
	
	for (int n = 0; n < strlen(plaintext); n++) {
		do {
			w = rand() % 256 + 1; // w is relatively prime with S array size, which is 256.
		} while (GCD(w,256) != 1);

		i = (i + w) % 256;
		j = (k + S[j] + S[i]) % 256;
		k = (k + i + S[j]) % 256;

		swap (&S[i],&S[j]);

		int z = S[(j + S[i + S[z + k]]) % 256];

		ciphertext[n] = z^plaintext[n];
	}
}

void SPRITZ_Encrypt (unsigned char *plaintext, char *key, unsigned char *ciphertext)
{
	unsigned char S[256];

	KSA (key, S);

	PRG (S, plaintext, ciphertext);

}

// Generate a 128 Bytes (1024 bits) key long
char *SPRITZ_Key()
{
	srand(time(NULL));
	char *result = malloc(sizeof(char) * 128);
	assert (result != NULL);

	for (int p = 0; p < 128; p++)
	{
		int random = rand() % 2;
		int key = rand() % 26;

		if (random == 0)
			result[p] = (char)((key-65) % 26 + 65);
		else if (random == 1)
			result[p] = (char)((key-97) % 26 + 97);
	}
	return result;
}
