#include "transposition_func.h"

char *tc_encryption(char* msg, char* key) {
	int pos; 
	int keypos[strlen(key) - 1]; //ignoring /n
	int i = 0;
	int j = 0;
	char * new_msg; //full message (when strlen(message) % strlen(key) != 0)

	//printf("%d\n", strlen(key) - 1);
	for (i = 0; i < strlen(key) - 1; i++) { //all 0
		keypos[i] = 0;
	}

	/*
	//in the keypost put numbers of wich letter come first in the alphabet (ordenation):
	key 	= 	balon
	keypos 	=	21354
	*/

	for (i = 0; i < strlen(key) - 1; i++) { 
		pos = 0;
		for (j = 0; j < strlen(key) - 1; j++) {
			if (key[i] > key[j]) {
				pos++;
			}
		}
		keypos[i] = pos + 1;
	}

	//if strlen(message) % strlen(key) != 0 we need to add more letters on the message (fill to mod be 0)
	//printf("%d %d %d\n", strlen(msg), strlen(key)-1, strlen(msg) % (strlen(key)-1));
	//printf("%s\n", msg);
	if (strlen(msg) % ((strlen(key)-1)) != 0) {
		//aux = how much left to % be == 0
		int aux = (strlen(key)-1) - (strlen(msg) % (strlen(key)-1));

		//use sizeof(char)
		new_msg =  malloc(strlen(msg) + aux); //alloc a size that the message should have
		//printf("tamanho da mensagem nova %d\n", strlen(msg));
		//printf("tamanho da mensagem nova %d\n", aux);
		
		for (i = 0; i < (strlen(msg) + aux); i++) {
			if (i < (strlen(msg))) {
				new_msg[i] = msg[i];
			} else {
				new_msg[i] = 'x';
			}
		}
		//printf("tamanho da mensperdjdfagem nova %d\n", strlen(new_msg));
		
	} else { //strlen(message) % strlen(key) == 0
		new_msg = (char *)malloc(strlen(msg));
		strcpy(new_msg, msg);
	}
	printf("complete message: %s\n", new_msg);

	char* encrypt = (char *)malloc(strlen(new_msg));
	int aux = 0;
	for (i = 1; i < strlen(key); i++) {
		j = 0;
		while (keypos[j] != i) {
			j++;
		}
		j++;
		//printf("i %d j %d s %c\n", i, j, key[j]);
		for (i = 0; i < strlen(new_msg); i++) {
			if (i % j == 0) {
				encrypt[aux] = new_msg[i];
				aux++;
			}

		}
	}
	return encrypt;
}

/*
char *tc_decryption(char* msg, char* key) {
	char* decrypt = malloc(strlen(char));
	strcpy(decrypt, msg);
	
	int i;
	//int aux;
	for (i = 0; i < strlen(msg); i++) {

	}

	return decrypt;
}
*/