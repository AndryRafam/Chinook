/* Print function */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "../../Header/Blowfish.h"
#include "../../Header/function.h"
#include "../../Header/hash.h"
#include "../../Header/ORIG_S_P.h"
#include "../../Header/Spritz.h"
#include "../../Header/VMPC.h"
#include "../../Header/RC4A.h"
#include "../../Header/Colors.h"

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
	printf("\n\n\n");
	
	srand(time(0));	
	int random = rand() % 3;
	int select = rand() % 4;	
	int count = 0;
	// Digital signature		
	if (random == 0)
	{
		printf(Red "[ Digital Signature - SHA 256 ]\n\n"); printf(Reset); SHA_256(salt_text);
		printf("\n\n");
	}
	else if (random == 1)
	{
		printf(Red "[ Digital Signature- SHA 384 ]\n\n"); printf(Reset); SHA_384(salt_text);
		printf("\n\n");
	}
	else
	{
		printf(Red "[ Digital Signature - SHA 512 ]\n\n"); printf(Reset); SHA_512(salt_text);
		printf("\n\n");	
	}
	
	// Encryption part
	fprintf(stdout, Red "[ Encrypted Message ]\n\n"); printf(Reset);
	if (select == 0) // Blowfish 
	{
		int len_Blowfish_key = strlen(Blowfish_key());
		Blowfish_Init(Blowfish_key(), len_Blowfish_key);
		crack_text(salt_text,&L,&R,strlen(salt_text));
		Blowfish_Encipher(&L, &R);
		printf("%08o\n", R);
		printf("%08o\n", L);
		printf("\n");
	}
	else if (select == 1) // Spritz
	{
		SPRITZ_Encrypt (salt_text, SPRITZ_Key(), ciphertext_spritz);		
		for (int x = 0; x < strlen(salt_text); x++){
			count += 1;
			fprintf(stdout,"%02o ", *(ciphertext_spritz + x));
			if (count%4 == 0)
				printf("\n");
		}
		printf("\n");
	}
	else if (select == 2) // VMPC
	{
		VMPC_Encrypt (salt_text, VMPC_key(), ciphertext_vmpc);
		for (int x = 0; x < strlen(salt_text); x++){
			count += 1;
			fprintf(stdout,"%02o ", *(ciphertext_vmpc + x));
			if (count%4 == 0)
				printf("\n");
		}
		printf("\n");	
	}
	else if (select == 3)
	{
		RC4A_Encrypt (salt_text, RC4A_Key(), ciphertext_RC4A);
		for (int x = 0; x < strlen(salt_text); x++){
			count += 1;
			fprintf(stdout, "%02o ", *(ciphertext_RC4A + x));
			if (count%4 == 0)
				printf("\n");
		}
		printf("\n");
	}
	fprintf(stdout, Cyan "\t***********************************************************\n\n"); printf(Reset);

	free(ciphertext_spritz);
	free(ciphertext_vmpc);
	free(ciphertext_RC4A);
}
