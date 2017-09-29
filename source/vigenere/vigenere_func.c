#include "vigenere_func.h"

char *vc_repeat_key(char* msg, char* key) {
	char* repeated_key = malloc(MAX_BUF * sizeof(char));
	int i;
	int j = 0;
	
	for (i = 0; i < strlen(msg); i++) {
		
		if (i > strlen(key - 1)) {
			printf("%d\n", ((strlen(key)-1) * i);
		} else {
			printf("%d\n", i);
		}
		j++;
	}
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

