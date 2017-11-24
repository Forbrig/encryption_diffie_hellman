#include "cesar_func.h"
#include "../file_manager.h"

int main ( ) {
	
	char* msg;
	char* encrypt;
	char* decrypt;
	int key;

	FILE *in; //in file
	in = fopen("../in.txt", "r"); //open file in lecture mode only (frem where te exe is "../")
	
	if (in == NULL) {
		printf("Cannot open the file...\n");
		exit(0);
	} else {		
		printf("Write the message to encrypt\n");
		/*
		char msg[MAX_BUF] = "";
		fgets (msg, MAX_BUF, stdin);
		//scanf("%s", msg);
		*/
		
		msg = file_to_string(in);
		
		printf("Message:\n%s\n", msg);
		if (msg == NULL) {
			printf("Error parsing the file to string, exiting...\n");
			return 0;
		}
	}
	
	printf("Write a key\n");
	scanf("%d", &key);
	
	encrypt = cc_encryption(msg, key);
	printf("%s\n", encrypt);

	string_to_file(encrypt);

	decrypt = cc_decryption(encrypt, key);
	printf("%s\n", decrypt);


	return 0;
}
