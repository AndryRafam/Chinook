Main.exe : Blowfish.o function.o hash.o Spritz.o VMPC.o Main.o
		 gcc -Wall Blowfish.o function.o hash.o Spritz.o VMPC.o Main.o -o Main.exe -lssl -lcrypto

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

Main.o : Main.c Blowfish.h function.h hash.h ORIG_S_P.h Spritz.h VMPC.h Colors.h
	    gcc -c -lssl Main.c -lcrypto
