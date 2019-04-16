/* Hash function */

#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include "../../Header/hash.h"

void SHA_256 (unsigned char *text)
{
	unsigned char digest_256[SHA256_DIGEST_LENGTH];
	SHA256 (text, strlen(text), digest_256);

	for (int x = 0; x < SHA256_DIGEST_LENGTH; x++)
		printf("%02X", digest_256[x]);
	return;
}

void SHA_384 (unsigned char *text)
{
	unsigned char digest_384[SHA384_DIGEST_LENGTH];
	SHA384 (text, strlen(text), digest_384);

	for (int x = 0; x < SHA384_DIGEST_LENGTH; x++)
		printf("%02X", digest_384[x]);
	return;
}

void SHA_512 (unsigned char *text)
{
	unsigned char digest_512[SHA512_DIGEST_LENGTH];
	SHA512 (text, strlen(text), digest_512);

	for (int x = 0; x < SHA512_DIGEST_LENGTH; x++)
		printf("%02X", digest_512[x]);
	return;
}
