/* Blowfish implementation */

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include "Blowfish.h"
#include "ORIG_S_P.h"
#include "function.h"

#define N 16
#define MaxBytes 56

uint32_t P[N+2];
uint32_t S[4][256];

uint32_t F(uint32_t x)
{
	unsigned short a, b, c, d;
	uint32_t y;

	d = x & 0X00FF;
	x >>= 8;
	c = x & 0X00FF;
	x >>= 8;
	b = x & 0X00FF;
	x >>= 8;
	a = x & 0X00FF;

	y = ((S[0][a] + S[1][b]^S[2][c]) + S[3][d]);
	return y;
}

void Blowfish_Encipher (uint32_t *L, uint32_t *R)
{
	uint32_t Xl, Xr, temp;
	Xl = *L;
	Xr = *R;

	for (int i = 0; i < N; ++i)
	{
		Xl = Xl^P[i];
		Xr = F(Xl)^Xr;
		
		temp = Xl;
		Xl = Xr;
		Xr = temp;
	}
	
	temp = Xl;
	Xl = Xr;
	Xr = temp;
	
	Xr = Xr^P[N];
	Xl = Xl^P[N+1];

	*L = Xl;
	*R = Xr;

	return;
}

void Blowfish_Init (unsigned char *key, int keybytes)
{
	uint32_t data, dataL, dataR;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 256; j++)
			S[i][j] = ORIG_S[i][j];
	}

	int j = 0;
	for (int i = 0; i < N+2; ++i)
	{
		data = 0x00000000;
		for (int k = 0; k < 4; ++k)
		{
			data = (data << 8) | key[j];
			j = j + 1;
			if (j >= keybytes)
				j = 0;
		}
		P[i] = ORIG_P[i]^data;
	}

	dataL = 0x00000000;
	dataR = 0x00000000;

	for (int i = 0; i < N; i += 2)
	{
		Blowfish_Encipher(&dataL, &dataR);
		P[i] = dataL;
		P[i+1] = dataR;
	}

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 256; j += 2)
		{
			Blowfish_Encipher (&dataL, &dataR);
			S[i][j] = dataL;
			S[i][j+1] = dataR;
		}
	}
	return;
}

// Generate randomly Blowfish key
unsigned char *Blowfish_key()
{
	srand(time(0));
	int key_random = rand() % MaxBytes + 4;
	unsigned char *key = malloc(sizeof(unsigned char[key_random]));
	int count, key1, key2;

	for (int i = 0; i < key_random; i++)
	{
		count = rand() % 2;
		key1 = rand() % 26;
		key2 = rand() % 26;

		if (count == 0)
			key[i] = (char)((key1 - 65) % 26 + 65);
		else
			key[i] = (char)((key2 - 97) % 26 + 97);
	}
	return key;
}


		
