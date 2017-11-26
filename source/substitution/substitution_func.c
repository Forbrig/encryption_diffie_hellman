#include <string.h>
#include "substitution_func.h"


char *sc_encryption(char* msg, char key[]) {
	int i, size = strlen(msg);
	char* encrypt = malloc(size * sizeof(char));

	for (i = 0; i < size; i++) {
		encrypt[i] = key[(int)msg[i]];
	}
	return encrypt;
}

char *sc_decryption(char* msg, char key[]) {
	int i, j, size = strlen(msg);;
	char* decrypt = malloc(size * sizeof(char));


	for (j = 0; j < size; j++) {
		for (i = 0; i < 256; i++) {
			if (key[i] == msg[j]) {
				decrypt[j] = i;
				break;
			}
		}
	}

	return decrypt;
}
