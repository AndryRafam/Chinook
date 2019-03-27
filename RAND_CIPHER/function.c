// Basic function used in the program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "Blowfish.h"
#include "function.h"
#include "hash.h"
#include "ORIG_S_P.h"
#include "Spritz.h"
#include "VMPC.h"
#include "Colors.h"

void swap (unsigned char *a, unsigned char *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int GCD (int a, int b)
{
	if (a > b)
	{
		if (a%b == 0)
			return b;
		else
			return GCD (b, a%b);
	}
	else
	{
		if (b%a == 0)
			return a;
		else
			return GCD (a, b%a);
	}
}

// Salt the clear message
char *Salt()
{
	
	unsigned char *string = malloc(sizeof(unsigned char) * 16);
	srand(time(NULL));
	int i = 0;

	while (i < 16)
	{
		int random = rand() % 2;
		int key = rand() % 26;

		if (random == 0)
			string[i] = (char)((key-65) % 26 + 65);
		else if (random == 1)
			string[i] = (char)((key-97) % 26 + 97);
		i += 1;
	}
	return string;
}

// Crack function
void crack_text (unsigned char *text, uint32_t *Left, uint32_t *Right, int len_text)
{
	int block_len;
	while (len_text)
	{
		Left = Right = 0UL;

		// Crack the plaintext string into two 32-bit blocks; pad with zeros if necessary
		for (block_len = 0; block_len < 4; block_len++)
		{
			if (len_text)
			{
				Left += *text++; // Copy string
				len_text--;
			}
			else Left += 0; // Pad with zero
		}
		for (block_len = 0; block_len < 4; block_len++)
		{
			if (len_text)
			{
				Right += *text++; // Copy string
				len_text--;
			}
			else Right += 0; // Pad with zero
		}
	}
}

// Print Function
void print (char *argument)
{
	uint32_t L, R;
	unsigned char *salt_text = malloc(sizeof(unsigned char) * (16 + strlen(argument)));
	strcpy (salt_text, argument);
	strcat (salt_text, Salt());
	unsigned char *ciphertext_spritz = malloc(sizeof(int) * strlen(salt_text));
	unsigned char *ciphertext_vmpc = malloc(sizeof(int) * strlen(salt_text));		
	
	fprintf(stdout, Red "[ Your salt text ] >> "); printf(Reset);
	for (int j = 0; j < strlen(salt_text); j++)
		fprintf(stdout, "%c", *(salt_text + j));
	printf("\n\n");
	srand(time(0));	
	int random = rand() % 3;
	int select = rand() % 3;	
	
	// Digital signature		
	if (random == 0)
	{
		printf(Red "[ Digital Signature - SHA 256 ] >> "); printf(Reset); SHA_256(salt_text);
		printf("\n\n");
	}
	else if (random == 1)
	{
		printf(Red "[ Digital Signature- SHA 384 ] >> "); printf(Reset); SHA_384(salt_text);
		printf("\n\n");
	}
	else
	{
		printf(Red "[ Digital Signature - SHA 512 ] >> "); printf(Reset); SHA_512(salt_text);
		printf("\n\n");	
	}
	
	// Encryption part
	fprintf(stdout, Red "[ Encrypted Message ] >> "); printf(Reset);
	if (select == 0) // Blowfish 
	{
		int len_Blowfish_key = strlen(Blowfish_key());
		Blowfish_Init(Blowfish_key(), len_Blowfish_key);
		crack_text(salt_text,&L,&R,strlen(salt_text));
		Blowfish_Encipher(&L, &R);
		printf("%08X %08X\n\n", R, L);
	}
	else if (select == 1) // Spritz
	{
		SPRITZ_Encrypt (salt_text, SPRITZ_Key(), ciphertext_spritz);		
		for (int i = 0; i < strlen(salt_text); i++)
			fprintf(stdout,"%02X%c", *(ciphertext_spritz + i), i < (strlen(salt_text)-1) ? ' ' : '\n');
		printf("\n");
	}
	else if (select == 2) // VMPC
	{
		VMPC_Encrypt (salt_text, VMPC_key(), ciphertext_vmpc);
		for (int x = 0; x < strlen(salt_text); x++)
			fprintf(stdout,"%02X%c", *(ciphertext_vmpc + x), x < (strlen(salt_text)-1) ? ' ' : '\n');
		printf("\n");	
	}
	fprintf(stdout, Cyan "\t***********************************************************\n\n"); printf(Reset);	

	free(ciphertext_spritz);
	free(ciphertext_vmpc);
}
