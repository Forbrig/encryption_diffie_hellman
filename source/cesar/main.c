#include "cesar_func.h"

int main ( ) {
	char msg[MAX_BUF] = "";
	char* encrypt;
	char* decrypt;
	int key;
	
	printf("Write the message to encrypt\n");
	fgets (msg, MAX_BUF, stdin);
	//scanf("%s", msg);
	printf("Write a key\n");
	scanf("%d", &key);
	
	encrypt = cc_encryption(msg, key);
	printf("%s\n", encrypt);

	decrypt = cc_decryption(encrypt, key);
	//printf("%s\n", decrypt);


	return 0;
}
