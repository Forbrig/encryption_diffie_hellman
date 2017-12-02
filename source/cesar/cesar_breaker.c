#include "cesar_breaker.h"

void cesar_breaker(FILE* encrypt){
	char** dictionary;
	char* sencrypt;
	char* aux;
	char* token;
	sencrypt = file_to_string(encrypt);
	char* sdecrypt = (char *)malloc(strlen(sencrypt));
	strcpy(sdecrypt, sencrypt);
	int i, key, point;

	FILE * dic = fopen("dictionary.dat", "r");

	if (dic == NULL) {
		printf("Couldn't open the dictionary, exiting...\n");
		exit(0);
	} else {
		aux = file_to_string(dic);
		dictionary = string_break(aux); //destroy the original string
		char* old_sdecrypt = (char *)malloc(strlen(sencrypt));
		char* aux_sdecrypt = (char *)malloc(strlen(sencrypt));
		strcpy(old_sdecrypt, sdecrypt);
		for (key = 1; key < 256; key++) { //ascii have 256 alphanumeric so there is 256 possibilities for the key
			for (i = 0; i < strlen(sencrypt); i++) {
				sdecrypt[i] = old_sdecrypt[i] - key;
			}
			strcpy(aux_sdecrypt, sdecrypt);
			point = 0;
			token = strtok(sdecrypt, " ");
			while (token != NULL) {
				for(i = 0; dictionary[i] != NULL; i++) {
					if(strcmp(token, dictionary[i]) == 0) { //1 world match with dictionary
						point++;
					}
				}
				token = strtok(NULL, " ");
			}
			if (point > 0) {
				printf("KEY: %d, POINTS: %d\nPOSSIBLE MESSAGE:\n%s\n", key, point, aux_sdecrypt);
			}
		}
	}
	return;
}
