#include "vigenere_breaker.h"
#include "vigenere_func.h"


void vigenere_breaker(FILE* encrypt) {
	char** dictionary;
	char* sencrypt;
	char* aux;
	sencrypt = file_to_string(encrypt);
	char* sdecrypt = (char *)malloc(strlen(sencrypt));
	strcpy(sdecrypt, sencrypt);
	int i, j, k, point;
	char* repeated_key;
	repeated_key = (char *)malloc(strlen(sencrypt))	;

	FILE * dic = fopen("dictionary.dat", "r");

	if (dic == NULL) {
		printf("Couldn't open the dictionary, exiting...\n");
		exit(0);
	} else {
		aux = file_to_string(dic);
		printf("DICTIONARY:\n%s\n", aux);
		dictionary = string_break(aux);
	    char* old_sdecrypt = malloc(strlen(sencrypt));
		char* aux2_sdecrypt = malloc(strlen(sencrypt));
		char** aux_sdecrypt; //will be destoyed
		strcpy(old_sdecrypt, sdecrypt); //saving the base encrypt
	    for (i = 0; dictionary[i] != NULL; i++) { //we should use the words on dictionary as possible keys and try that key to decrypt the message
	    	strcpy(sdecrypt, old_sdecrypt);
	    	repeated_key = vc_repeat_key(sencrypt, dictionary[i]);
	    	for(j = 0; j < strlen(sencrypt); j++) {
	    		sdecrypt[j] = old_sdecrypt[j] - repeated_key[j]; //use the barely new key and try to decrypt
	    	}
	    	//printf("%s\n", sdecrypt);
	    	strcpy(aux2_sdecrypt, sdecrypt); //save the original decrypted string
			
			aux_sdecrypt = string_break(sdecrypt);

			point = 0;
			for (j = 0; aux_sdecrypt[j] != NULL; j++) {
				for(k = 0; dictionary[k] != NULL; k++) {
					if(strcmp(aux_sdecrypt[j], dictionary[k]) == 0) { //1 world match with dictionary
						//printf("%s %s\n", aux_sdecrypt[j], dictionary[k]); //words that match
						point++;
					}
				}
			}

			if (point > 0) {
				printf("KEY:\n%s\nPOINTS: %d\nMESSAGE:\n%s\n", dictionary[i], point, aux2_sdecrypt);
			}
	    }
	}
	return;
}
