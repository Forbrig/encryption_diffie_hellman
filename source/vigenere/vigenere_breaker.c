#include "vigenere_breaker.h"
#include "vigenere_func.h"


void vigenere_breaker(FILE* encrypt) {
	char* dictionary[DIC_SIZE];
	char* sencrypt;
	char* aux;
	sencrypt = file_to_string(encrypt);
	char* sdecrypt = (char *)malloc(strlen(sencrypt));
	strcpy(sdecrypt, sencrypt);

	int i, j, point;
	char *token;
	char* repeated_key;
	repeated_key = (char *)malloc(strlen(sencrypt))	;

	FILE * dic = fopen("dictionary.dat", "r");

	if (dic == NULL) {
		printf("Couldn't open the dictionary, exiting...\n");
		exit(0);
	} else {
		aux = file_to_string(dic);

		//printf("Words on dictionary:\n%s\n", aux);

	    token = strtok(aux, " ");
	    for (i = 0; token != NULL; i++) { //separate the words
			dictionary[i] = token;
			token = strtok(NULL, " ");
	    }

	    char* old_sdecrypt = (char *)malloc(strlen(sencrypt));
		char* aux_sdecrypt = (char *)malloc(strlen(sencrypt));
		strcpy(old_sdecrypt, sdecrypt); //saving the base encrypt
	    int usable_size = i; //in the dictionary
	    for (i = 0; i < usable_size; i++) { //we should use the words on dictionary as possible keys and try that key to decrypt the message
	    	//printf("%d\n", i);
	    	repeated_key = vc_repeat_key(sencrypt, dictionary[i]);
	    	//printf("repk: %s\n", repeated_key);
	    	/*
	    	printf("%s\n", repeated_key);
	    	printf("%d\n", usable_size);
	    	printf("%s\n", sencrypt);
	    	printf("%s\n", dictionary[i]);
	    	*/
	    	for(j = 0; j < strlen(sencrypt); j++) {
	    		sdecrypt[j] = old_sdecrypt[j] - repeated_key[j]; //use the barely new key and try to decrypt
	    	}

	    	strcpy(aux_sdecrypt, sdecrypt);
			point = 0;
			token = strtok(sdecrypt, " "); //break the words where there are spaces
			while (token != NULL) {
				for(j = 0; j < usable_size; j++) {
					if(strcmp(token, dictionary[j]) == 0) { //1 world match with dictionary
						point++;
					}
				}
				token = strtok(NULL, " ");
			}
			//printf("dec: %s\n", sdecrypt);
			if (point > 0) {
				printf("\nKEY:\n%s\nMESSAGE:\n%s\n", dictionary[i], aux_sdecrypt);
			}
	    }
	}
	return;
}
