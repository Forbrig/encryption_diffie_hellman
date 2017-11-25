#include "vigenere_func.h"

char *vc_repeat_key(char* msg, char* key) {
	char* repeated_key = malloc(MAX_BUF * sizeof(char));
	int i;
	for (i = 0; i < strlen(msg); i++) {
		
		repeated_key[i] = key[i % (strlen(key)-1)];	
	}
	//repeated_key[j-1] = '\0';
	return repeated_key;
}

char *vc_encryption(char* msg, char* key) {
	int i;
	char* encrypt = malloc(MAX_BUF * sizeof(char));
	strcpy(encrypt, msg);
	for (i = 0; i < strlen(msg); i++) {
		encrypt[i] = encrypt[i] + key[i];
	}
	return encrypt;
}

char *vc_decryption(char* msg, char* key) {
	int i;
	char* decrypt = malloc(MAX_BUF * sizeof(char));
	strcpy(decrypt, msg);
	for (i = 0; i < strlen(msg); i++) {
		decrypt[i] = decrypt[i] - key[i];
	}
	return decrypt;
}

