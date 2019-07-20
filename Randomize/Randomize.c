#include "../Header/Randomize.h"
#include "../Header/function.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

unsigned char *shuffle(char *input){
	srand(time(0));
	for (int i = strlen(input)-1; i > 0; i--){
		int j = rand()%(i+1);
		swap(&input[i],&input[j]);
	}
}

	
