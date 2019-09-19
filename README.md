![Output Example](https://github.com/AndryRafam/Program-Output/blob/master/Chinook.gif)

Chinook is a random encryption program; based on Blowfish (Symmetric key block Cipher), Spritz (variant of ARC4); VMPC (Variably Modified Permutation Composition) and RC4A; and also three hash function SHA-256, SHA-384 and SHA-512. The program also goes with a salt function which adds extra bits at the end of the clear message, in order to reduce the risk of collision.

# Folder included
- Tools folder
- Cipher folder  
- Test folder (Contains automated testing / Main program)
- Header folder

# How to run on Linux (Debian / Ubuntu)
- 1) Upload the program
- 2) In command line, go to the folder which contains the program
- 3) Type make and press enter
- 4) Type ./exe (space)"Your text inside quotation mark" (If no argument is given after ./exe, default argument is: "THIS IS A TEST").

# How its works ?
- 1) Salt the clear message with a pseudo random salt function
- 2) Randomly shuffle the salt message
- 3) Choose randomly the digital signature
- 4) Choose randomly the encryption function
- 5) Output all

# WARRANTY
THE SOFTWARE IS UNDER MIT LICENSE AND IS PROVIDED "AS IS", WITH NO WARRANTY OF ANY KIND.
