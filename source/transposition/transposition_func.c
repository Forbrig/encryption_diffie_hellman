#include "transposition_func.h"


/*
in the keypost put numbers of wich letter come first in the alphabet (ordenation):
key 	= 	balon
keypos 	=	21354
*/
int * tc_ordenate_key(char* key) {
	int i, j;
	int pos;
	int * keypos = malloc(sizeof(int) * (strlen(key) - 1));
	//int keypos[strlen(key) - 1]; //ignoring /n
	for (i = 0; i < strlen(key); i++) { //all 0
		keypos[i] = 0;
	}

	
	for (i = 0; i < strlen(key); i++) { 
		pos = 0;
		for (j = 0; j < strlen(key); j++) {
			if (key[i] > key[j]) {
				pos++;
			}
		}
		keypos[i] = pos + 1;
	}

	return keypos;
}

char * tc_encryption(char* msg, char* key) {
	int i, j;
	char * new_msg; //full message (when strlen(message) % strlen(key) != 0)
	int * keypos;

	keypos = tc_ordenate_key(key);
	
	//if strlen(message) % strlen(key) != 0 we need to add more letters on the message (fill to mod be 0)
	if (strlen(msg) % (strlen(key)) != 0) {
		//aux = how much left to % be == 0
		int aux = strlen(key) - (strlen(msg) % strlen(key));
		new_msg =  malloc(strlen(msg) + aux); // (+1 for \0) alloc a size that the message should have		
		for (i = 0; i < (strlen(msg) + aux); i++) {
			if (i < (strlen(msg))) {
				new_msg[i] = msg[i];
			} else {
				new_msg[i] = 'x';
			}
		}
		new_msg[strlen(msg) + aux] = '\0';	
	} else { //strlen(message) % strlen(key) == 0
		printf("same size\n");
		new_msg = (char *)malloc(strlen(msg));
		strcpy(new_msg, msg);
	}

	char* encrypt = (char *)malloc(strlen(new_msg));
	int n_line = strlen(new_msg)/strlen(key); //nuber of lines that de matrix of should have
	int aux = 0; //at wich position the encrypted vector is filled
	int k;
	for (i = 1; i < strlen(key) + 1; i++) { //key ordenately
		for (j = 0; keypos[j] != i; j++) {}; //finds the position of the keys ordenately from 1 to strlen(keys) 		
		for (k = 0; k < n_line; k++) {			
			encrypt[aux] = new_msg[j + (strlen(key)*k)];
			aux++;
		}
	}
	encrypt[strlen(new_msg)-1] = '\0';
	return encrypt;
}


char * tc_decryption(char* msg, char* key) {
	int i, j, k;
	int * keypos;
	char* decrypt = (char *) malloc(strlen(msg));
	int n_line = strlen(msg)/strlen(key); //nuber of lines that de matrix of should have
	//strcpy(decrypt, msg);
	
	keypos = tc_ordenate_key(key);
	
	int aux = 0;
	for (i = 1; i < strlen(key) + 1; i++) { //key ordenately
		for (j = 0; keypos[j] != i; j++) {}; //finds the position of the keys ordenately from 1 to strlen(keys)
		for (k = 0; k < n_line; k++) {
			decrypt[j + (strlen(key)*k)] = msg[aux];
			aux++;
		}
	}

	decrypt[strlen(msg)-1] = '\0';
	return decrypt;
}