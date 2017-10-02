#include "vigenere_func.h"

int main ( ) {
	char msg[MAX_BUF] = "";
	char key[MAX_BUF] = "";
	char* repeated_key;
	char* encrypt;
	char* decrypt;
	
	printf("Write the message to encrypt\n");
	fgets (msg, MAX_BUF, stdin);
	//scanf("%s", msg);
	printf("Write a key\n");
	fgets(key, MAX_BUF, stdin);
	
	repeated_key = vc_repeat_key(msg, key);
	printf("Repeated key: %s\n", repeated_key);
	
	encrypt = vc_encryption(msg, repeated_key);
	printf("Encrypted: %s\n", encrypt);

	decrypt = vc_decryption(encrypt, repeated_key);
	printf("Decrypted: %s\n", decrypt);
	
	system("pause");
	return 0;
}
