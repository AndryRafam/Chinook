/* Print function */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "Blowfish.h"
#include "function.h"
#include "hash.h"
#include "ORIG_S_P.h"
#include "Spritz.h"
#include "VMPC.h"
#include "RC4A.h"
#include "Colors.h"

void print (char *argument)
{
	uint32_t L, R;
	unsigned char *salt_text = malloc(sizeof(unsigned char) * (16 + strlen(argument)));
	strcpy (salt_text, argument);
	strcat (salt_text, Salt());
	unsigned char *ciphertext_spritz = malloc(sizeof(int) * strlen(salt_text));
	unsigned char *ciphertext_vmpc = malloc(sizeof(int) * strlen(salt_text));
	unsigned char *ciphertext_RC4A = malloc(sizeof(int) * strlen(salt_text));		
	
	fprintf(stdout, Red "[ Your salt text ] >> "); printf(Reset);
	for (int j = 0; j < strlen(salt_text); j++)
		fprintf(stdout, "%c", *(salt_text + j));
	printf("\n\n");
	
	srand(time(0));	
	int random = rand() % 3;
	int select = rand() % 4;	
	
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
	else if (select == 3)
	{
		RC4A_Encrypt (salt_text, RC4A_Key(), ciphertext_RC4A);
		for (int x = 0; x < strlen(salt_text); x++)
			fprintf(stdout, "%02X%c", *(ciphertext_RC4A + x), x < (strlen(salt_text)-1) ? ' ' : '\n');
		printf("\n");
	}
	fprintf(stdout, Cyan "\t***********************************************************\n\n"); printf(Reset);	

	free(ciphertext_spritz);
	free(ciphertext_vmpc);
	free(ciphertext_RC4A);
}
