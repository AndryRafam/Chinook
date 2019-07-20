Chinook is a random encryption program; based on Blowfish (Symmetric key block Cipher), Spritz (variant of ARC4); VMPC (Variably Modified Permutation Composition) and RC4A; and also three hash function SHA-256, SHA-384 and SHA-512. The program also goes with a salt function which adds extra bits at the end of the clear message, in order to reduce the risk of collision.

# Files included
- Randomize folder
- Cipher folder
- Print folder  
- Main folder
- Header folder
- Makefile

# How to run on Linux (Debian / Ubuntu)
- 1) Upload the program
- 2) In command line, go to the folder which contains the program
- 3) Type make and press enter
- 4) Type ./exe (space)"Your text inside quotation mark" (If no argument is given after ./exe, default argument is: "THIS IS A TEST").

# How its works ?
- 1) Salt the clear message with a pseudo random salt function
- 2) Choose randomly the digital signature
- 3) Choose randomly the encryption function
- 4) Output all
