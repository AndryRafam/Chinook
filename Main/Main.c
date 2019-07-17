/* CHINOOK (RANDOM CIPHER program)

Author: Andry RAFAM ANDRIANJAFY

License: Open Source

Tools: Ubuntu Linux 16.04 - LTS / GCC -v 6.5.0 && GDB -v 8.2

============================================================ */

#include "../Header/function.h"
#include "../Header/Colors.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **args)
{
	system("clear");
	fprintf(stdout, "\n");
	fprintf(stdout, Cyan "\t********** CHINOOK - Andry RAFAM ANDRIANJAFY **********\n\n"); printf(Reset);	
	
	if (argc != 2)
	{
		args[1] = "THIS IS A TEST"; /*Default argument if no argument is given.*/
		fprintf(stdout, "[ No argument is given after ./Main.exe. Default argument is ] >> %s", args[1]);
		printf("\n\n");	
	}		
	print(args[1]);
	return EXIT_SUCCESS;
}
