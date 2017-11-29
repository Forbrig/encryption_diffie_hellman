#include "transposition_func.h"
#include "transposition_breaker.h"

int main ( ) {
	char * msg;
	char auxkey[MAX_BUF] = "";
	char* encrypt;
	char* decrypt;
	
	/*
	printf("Write the message to encrypt\n");
	fgets (msg, MAX_BUF, stdin);
	//scanf("%s", msg);
	*/

	FILE *in; //in file
	in = fopen("test/test1.txt", "r"); //open file in lecture mode only (frem where te exe is "../")
	if (in == NULL) {
		printf("Cannot open the file...\n");
		exit(0);
	} else {
		msg = file_to_string(in);
		printf("MESSAGE TO ENCRYPT:\n%s\n", msg);
		printf("Write a key (cant have equal letters):\n");
		fgets(auxkey, MAX_BUF, stdin);
		char * key = strtok(auxkey, "\n"); //to get ride of \n from fgets
		
		encrypt = tc_encryption(msg, key);
		printf("ENCRYPTED MESSAGE:\n%s\n", encrypt);

		fclose(fopen("test/out1.txt", "w")); //clear the content
		FILE *out = fopen("test/out1.txt", "ab+");
		string_to_file(encrypt, out); // trows the encrypted content to a file_to_string
	
		decrypt = tc_decryption(encrypt, key);
		printf("DECRYPTED MESSAGE:\n%s\n", decrypt);

	}

	/*TESTS*/
	FILE *test1 = fopen("test/out1.txt", "r");
	transposition_breaker(test1);


	system("pause");
	return 0;
}
