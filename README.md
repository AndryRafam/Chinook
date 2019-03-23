# RAND_CIPHER
RAND_CIPHER is a random encryption program; based on Blowfish (Symmetric key block Cipher), Spritz (variant of ARC4) and VMPC (Variably Modified Permutation Composition); and also three hash function SHA-256, SHA-384 and SHA-512. The program also goes with a salt function which adds extra bits at the end of the clear message, in order to reduce the risk of collision.

If no argument is given, default argument is: "THIS A TEST".

# How its works ?
- 1) Salt the clear message with a pseudo random salt function
- 2) Choose randomly the digital signature
- 3) Choose randomly the encryption function
- 4) Output all

# Files included
- Header files
  - Blowfish.h
  - Colors.h
  - function.h
  - hash.h
  - ORIG_S_P.h
  - Spritz.h
  - VMPC.h
  
- .C files
  - Blowfish.c
  - function.c
  - hash.c
  - Main.c
  - Spritz.c
  - VMPC.c

- Makefile
