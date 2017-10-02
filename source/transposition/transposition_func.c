#include "transposition_func.h"

char *tc_encryption(char* msg, char* key) {
	int pos;
	int aux;
	int keypos[strlen(key) - 1];
	int i = 0;
	int j = 0;
	int flag = 0;

	//printf("%d\n", strlen(key) - 1);
	for (i = 0; i < strlen(key) - 1; i++) {
		keypos[i] = 0;
	}

	for (i = 0; i < strlen(key) - 1; i++) { //ordenation
		pos = 0;
		for (j = 0; j < strlen(key) - 1; j++) {
			if (msg[i] > msg[j]) {
				printf("%c %d ", msg[i], pos);
				pos++;
			}
		}
		printf("\n");
		keypos[i] = pos + 1;
	}

	for (i = 0; i < strlen(key) - 1; i++) {
		printf("%d ", keypos[i]);
	}

	printf("\n");

	aux = strlen(key) - (strlen(msg) % strlen(key));
	printf("%d\n", aux);

	char* encrypt = malloc(MAX_BUF * sizeof(char));
	strcpy(encrypt, msg);
	
	for (i = 0; i < strlen(msg); i++) {

	}
	return encrypt;
}

char *tc_decryption(char* msg, char* key) {
	char* decrypt = malloc(MAX_BUF * sizeof(char));
	strcpy(decrypt, msg);
	
	int i;
	int aux;
	for (i = 0; i < strlen(msg); i++) {

	}

	return decrypt;
}