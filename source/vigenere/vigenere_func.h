//vigenere cipher (poor Bellaso)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BUF 100 //max size of the message


char *vc_repeat_key(char*, char*); //repeat the key 'till reach the length of the message 
char *vc_encryption(char*, char*);
char *vc_decryption(char*, char*);
