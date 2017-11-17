#include "rsa_func.h"

int main ( ) {
	
	int msg, key;
	int encrypt;
	
	printf("Write the message (number) to encrypt\n");
	scanf("%d", &msg);
	printf("Write a key (number)\n");
	scanf("%d", &key);
	
	encrypt = rsa_encryption(msg, key);
	printf("Encrypted: %d\n", encrypt);

	/*
	 
	decrypt = vc_decryption(encrypt, repeated_key);
	printf("Decrypted: %s\n", decrypt);
	
	*/
	
	system("pause");
	return 0;
}

