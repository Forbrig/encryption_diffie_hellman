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

char *sc_decryption(char* msg, char* key) {
	int i;
	char* decrypt = malloc(MAX_BUF * sizeof(char));
	strcpy(decrypt, msg);
	for (i = 0; i < strlen(msg); i++) {
		decrypt[i] = decrypt[i] - key[i];
	}
	return decrypt;
}
