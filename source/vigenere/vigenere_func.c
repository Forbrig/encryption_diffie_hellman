#include "vigenere_func.h"

char *vc_repeat_key(char* msg, char* key) {
	char* repeated_key = malloc(MAX_BUF * sizeof(char));
	int i;
	int j = 0;
	
	for (i = 0; i < strlen(msg); i++) {
		
		repeated_key[i] = key[i % (strlen(key)-1)];
		
		
		/*
		if (i > strlen(key - 1)) {
			printf("%d\n", i % (strlen(key)-1));
		}
		*/
		j++;
	}
	repeated_key[j-1] = '\0';
	return repeated_key;
}

char *vc_encryption(char* msg, char* key) {
	char* encrypt = malloc(MAX_BUF * sizeof(char));
	strcpy(encrypt, msg);
	
	return encrypt;
}

char *vc_decryption(char* msg, char* key) {
	char* decrypt = malloc(MAX_BUF * sizeof(char));
	strcpy(decrypt, msg);
	

	return decrypt;
}

