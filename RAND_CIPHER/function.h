#ifndef _function_h
#define _function_h

#include <stdint.h>

void swap (unsigned char *a, unsigned char  *b);
int GCD (int a, int b);
void crack_text (unsigned char *text, uint32_t *Left, uint32_t *Right, int len_text);
char *Salt();

#endif
