#include "cesar_func.h"

char *cc_encryption(char* msg, int key) {
	char* encrypt = malloc(MAX_BUF * sizeof(char));
	strcpy(encrypt, msg);
	int i;

	for (i = 0; i < strlen(msg); i++) {
		encrypt[i] = encrypt[i] + key;
	}
	return encrypt;
}

char *cc_decryption(char* encrypt, int key) {
	char* decrypt = malloc(MAX_BUF * sizeof(char));
	strcpy(decrypt, encrypt);
	int i;

	for (i = 0; i < strlen(encrypt); i++) {
		decrypt[i] = decrypt[i] - key;
	}
	return decrypt;
}

