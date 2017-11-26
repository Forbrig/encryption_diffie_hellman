#include "transposition_func.h"

int main ( ) {
	char msg[MAX_BUF] = "";
	char key[MAX_BUF] = "";
	char* encrypt;
	char* decrypt;
	
	printf("Write the message to encrypt\n");
	fgets (msg, MAX_BUF, stdin);
	//scanf("%s", msg);
	printf("Write a key\n");
	fgets(key, MAX_BUF, stdin);
	
	encrypt = tc_encryption(msg, key);
	printf("Encrypted: %s\n", encrypt);
/*
	decrypt = tc_decryption(encrypt, key);
	printf("Decrypted: %s\n", decrypt);
*/	
	system("pause");
	return 0;
}
