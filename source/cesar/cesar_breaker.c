#include "cesar_breaker.h"

void cesar_breaker(FILE* encrypt){
	char* dictionary[DIC_SIZE];
	char* sencrypt;
	char* aux;
	sencrypt = file_to_string(encrypt);
	char* sdecrypt = (char *)malloc(strlen(sencrypt));
	strcpy(sdecrypt, sencrypt);

	//printf("encrypted:\n%s\n", sencrypt);
	int i, key, point;
	char *token;


	FILE * dic = fopen("dictionary.dat", "r");

	if (dic == NULL) {
		printf("Couldn't open the dictionary, exiting...\n");
		exit(0);
	} else {
		aux = file_to_string(dic);

		printf("\nDICTIONARY:\n%s\n", aux);

	    token = strtok(aux, " ");
	    for (i = 0; token != NULL; i++) {
			dictionary[i] = token;
			//printf("%s\n", token);

			token = strtok(NULL, " ");
	    }
	    int usable_size = i; //in the dictionary
	    /*
	    for (i = 0; i < usable_size; i++) {
	    	printf("%s\n", dictionary[i]);
	    }
		*/
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
				for(i = 0; i < usable_size; i++) {
					if(strcmp(token, dictionary[i]) == 0) { //1 world match with dictionary
						point++;
					}

				}
				//printf("%s\n", token);

				token = strtok(NULL, " ");
			}

			if (point > 0) {
				printf("\nKEY: %d\nMESSAGE:\n%s\n\n", key, aux_sdecrypt);

			}
		}
	}
	return;
}
