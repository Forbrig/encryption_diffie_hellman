#include "vigenere_func.h"

char *vc_repeat_key(char* msg, char* key) {
	char* repeated_key = malloc(MAX_BUF * sizeof(char));
	int i;
	int j = 0;
	int k = 0;
	for (i = 0; i < strlen(msg); i++) {
		if (msg[i] == ' ') {
			repeated_key[i] = ' ';
			k++;	
		} else {
			repeated_key[i] = key[(i - k) % (strlen(key)-1)];	
		}
		j++;
	}
	repeated_key[j-1] = '\0';
	return repeated_key;
}

char *vc_encryption(char* msg, char* key) {
	char* encrypt = malloc(MAX_BUF * sizeof(char));
	strcpy(encrypt, msg);
	int i;
	int aux;
	for (i = 0; i < strlen(msg); i++) {
		if (msg[i] >= 'a' && msg[i] <= 'z') {
			if (key[i] + (msg[i] - 'a') > 'z') {
				aux = key[i] + (msg[i] - 'a') - 'z';
				encrypt[i] = 'a' + aux - 1;
			} else {
				encrypt[i] =  key[i] + (msg[i] - 'a');
			}
		} else if (msg[i] >= 'A' && msg[i] <= 'Z') {
			if (key[i] + (msg[i] - 'A') > 'Z') {
				aux = key[i] + (msg[i] - 'A') - 'Z';
				encrypt[i] = 'A' + aux - 1;
			} else {
				encrypt[i] =  key[i] + (msg[i] - 'A');
			}
		} 
	}
	return encrypt;
}

char *vc_decryption(char* msg, char* key) {
	char* decrypt = malloc(MAX_BUF * sizeof(char));
	strcpy(decrypt, msg);
	
	int i;
	int aux;
	for (i = 0; i < strlen(msg); i++) {

		if (msg[i] >= 'a' && msg[i] <= 'z') {
			if (msg[i] - (key[i] - 'a') < 'a' ) {
				aux = 'a' - (msg[i] - (key[i] - 'a'));
				decrypt[i] = 'z' - aux + 1;
			} else {
				decrypt[i] = msg[i] - (key[i] - 'a');
			}
		} else if (msg[i] >= 'A' && msg[i] <= 'Z') {
			if (msg[i] - (key[i] - 'A') < 'A' ) {
				aux = 'A' - (msg[i] - (key[i] - 'A'));
				decrypt[i] = 'Z' - aux + 1;
			} else {
				decrypt[i] = msg[i] - (key[i] - 'A');
			}
		}
	}

	return decrypt;
}

