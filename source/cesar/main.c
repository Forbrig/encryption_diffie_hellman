#include "cesar_func.h"

int main ( ) {
	char msg[MAX_BUF] = "";
	char *encrypt;
	int key;
	
	printf("Write the message to encrypt\n");
	scanf("%s", msg);
	printf("Write a key\n");
	scanf("%d", &key);
	
	&encrypt = cc_encryption(msg, key);
	
	printf("%s\n", encrypt);
	return 0;
}
