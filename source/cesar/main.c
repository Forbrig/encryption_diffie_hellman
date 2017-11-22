#include "cesar_func.h"
#include "../file_manager.h"

int main ( ) {
	
	char* msg;
	char* encrypt;
	char* decrypt;
	int key;
	
	printf("Write the message to encrypt\n");
	/*
	char msg[MAX_BUF] = "";
	fgets (msg, MAX_BUF, stdin);
	//scanf("%s", msg);
	*/
	
	msg = file_to_string();
	
	printf("Message:\n%s\n", msg);
	if (msg == NULL) {
		printf("Exiting...\n");
		return 0;
	}
	
	printf("Write a key\n");
	scanf("%d", &key);
	
	encrypt = cc_encryption(msg, key);
	printf("%s\n", encrypt);

	decrypt = cc_decryption(encrypt, key);
	printf("%s\n", decrypt);


	return 0;
}
