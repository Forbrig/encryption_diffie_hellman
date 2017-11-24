#include "cesar_breaker.h"

int main () {
	FILE * encrypted = fopen("../cesar_encrypt.txt", "r");
	if (encrypted == NULL) {
		printf("Couldn't open the encrypted file...\n");
		exit(0);
	} else {
		cesar_break(encrypted);
	}



	return 0;
}