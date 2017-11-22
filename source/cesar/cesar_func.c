#include "cesar_func.h"

char *cc_encryption(char* msg, int key) {
	char* encrypt = malloc(MAX_BUF * sizeof(char));
	
	strcpy(encrypt, msg);
	int i;
	int aux;
	//printf("Size of message: %ld\n", strlen(msg));
	for (i = 0; i < strlen(msg); i++) {
		if ((msg[i] + key >= 'a' && msg[i] + key <= 'z') || (msg[i] + key >= 'A' && msg[i] + key <= 'Z')) {
			encrypt[i] = msg[i] + key;
		} else if (msg[i] >= 'a' && msg[i] <= 'z') { //if is in the range of the no caps alphabet
			aux = 'z' - msg[i]; //lenght from z (z in great than x)
			//printf("%d\n", aux);
			encrypt[i] = (key - aux - 1) + 'a';
		} else if (msg[i] >= 'A' && msg[i] <= 'Z') {
			aux = 'Z' - msg[i];
			encrypt[i] = (key - aux - 1) + 'A';
		}
	}

	//printf("%s\n", encrypt);
	return encrypt;
}


char *cc_decryption(char* msg, int key) {
	char* decrypt = malloc(MAX_BUF * sizeof(char));
	
	strcpy(decrypt, msg);
	
	int i;
	int aux;
	for (i = 0; i < strlen(msg); i++) {
		if ((msg[i] - key >= 'a' && msg[i] - key <= 'z') || ((msg[i] - key >= 'A' && msg[i] - key <= 'Z'))) {
			decrypt[i] = msg[i] - key;
		} else if (msg[i] >= 'a' && msg[i] <= 'z') {
			aux = msg[i] - 'a';
			decrypt[i] = (aux - key +1) + 'z';
			
		} else if (msg[i] >= 'A' && msg[i] <= 'Z')  {
			aux = msg[i] - 'A';
			decrypt[i] = (aux - key +1) + 'Z';
		}
		
	}


	return decrypt;
}

