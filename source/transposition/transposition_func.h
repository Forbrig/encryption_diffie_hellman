//trasposition cipher
//key cant have repeated letters

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../file_manager.h"
#define MAX_BUF 100 //max size of the message

int * tc_ordenate_key(char*);
char *tc_encryption(char*, char*);
char *tc_decryption(char*, char*);
