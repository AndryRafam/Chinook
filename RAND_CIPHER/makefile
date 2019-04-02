Main.exe : Blowfish.o function.o hash.o Spritz.o VMPC.o RC4A.o print.o Main.o
		 gcc -Wall Blowfish.o function.o hash.o Spritz.o VMPC.o RC4A.o print.o Main.o -o Main.exe -lssl -lcrypto

Blowfish.o : Blowfish.c Blowfish.h function.h ORIG_S_P.h
		   gcc -c Blowfish.c

function.o : function.c function.h 
		   gcc -c function.c

hash.o : hash.c hash.h
	    gcc -c -lssl hash.c -lcrypto

Spritz.o : Spritz.c function.h
		 gcc -c Spritz.c

VMPC.o : VMPC.c VMPC.h function.h
	    gcc -c VMPC.c

RC4A.o : RC4A.c RC4A.h function.h
	    gcc -c RC4A.c

print.o : print.c Blowfish.h function.h hash.h ORIG_S_P.h Spritz.h VMPC.h RC4A.h Colors.h
		gcc -c print.c 

Main.o : Main.c Blowfish.h function.h hash.h ORIG_S_P.h Spritz.h VMPC.h Colors.h
	    gcc -c -lssl Main.c -lcrypto
