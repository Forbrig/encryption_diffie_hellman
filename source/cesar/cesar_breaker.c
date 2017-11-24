#include "cesar_breaker.h"

void cesar_breaker(FILE* encrypt){
	char* sencrypt;
	sencrypt = file_to_string(encrypt);
	char* sdecrypt = (char *)malloc(strlen(sencrypt));
	strcpy(sdecrypt, sencrypt);

	printf("encrypted:\n%s\n", sencrypt);
	int i, key;

	for (key = 1; key < 256; key++) {
		for (i = 0; i < strlen(sencrypt); i++) {
			sdecrypt[i] = sdecrypt[i] - key;
		}
		printf("%s\n", sdecrypt);
	}
	return;
}