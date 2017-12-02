#include "vigenere_func.h"

char *vc_repeat_key(char* msg, char* key) {
	char* repeated_key = malloc(strlen(msg) * sizeof(char));
	int i;
	//make it ignore the /n's
	if (key[strlen(key)] == '\n') {
		key[strlen(key)] = '\0';
	}
	for (i = 0; i < strlen(msg); i++) {	
		repeated_key[i] = key[i % (strlen(key))];	
	}
	repeated_key[strlen(msg)] = '\0';
	return repeated_key;
}

char *vc_encryption(char* msg, char* key) {
	int i;
	char* encrypt = malloc(strlen(msg) * sizeof(char));
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

