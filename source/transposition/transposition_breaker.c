#include "transposition_breaker.h"
#include "transposition_func.h"

void transposition_breaker(FILE* encrypt) {
	char* dictionary[DIC_SIZE];
	char* sencrypt;
	char* aux;
	sencrypt = file_to_string(encrypt);
	char* sdecrypt = (char *)malloc(strlen(sencrypt));
	strcpy(sdecrypt, sencrypt);
	int i, j, k, point;
	char *token;

	FILE * dic = fopen("dictionary.dat", "r");

	if (dic == NULL) {
		printf("Couldn't open the dictionary, exiting...\n");
		exit(0);
	} else {
		aux = file_to_string(dic);
		token = strtok(aux, " ");
	    for (i = 0; token != NULL; i++) {
			dictionary[i] = token;
			token = strtok(NULL, " ");
	    }
	    int usable_size = i; //in the dictionary

		char* old_sdecrypt = (char *)malloc(strlen(sencrypt));
		char* aux_sdecrypt = (char *)malloc(strlen(sencrypt));

		strcpy(old_sdecrypt, sdecrypt);
		int n_line; //nuber of lines that de matrix of should have
		int auxi = 0;
		int l;
		int* keypos;
		//printf("%d\n", usable_size);
	    for (l = 0; l < usable_size; l++) { //we should use the words on dictionary as possible keys and try that key to decrypt the message
	    	printf("%d %d\n", l, usable_size);
	    	n_line = strlen(sencrypt)/strlen(dictionary[l]); //number of lines that de matrix of should have
	    	keypos  = tc_ordenate_key(dictionary[l]);
	    	auxi = 0;
	    	for (i = 1; i < strlen(dictionary[l]) + 1; i++) { //key ordenately
				for (j = 0; keypos[j] != i; j++) {}; //finds the position of the keys ordenately from 1 to strlen(keys)
				for (k = 0; k < n_line; k++) {
					sdecrypt[j + (strlen(dictionary[l])*k)] = sencrypt[auxi];
					auxi++;
				}
			}
			sdecrypt[strlen(sencrypt)] = '\0';
			printf("%s\n", sdecrypt);
	    }
	}
	return;
}