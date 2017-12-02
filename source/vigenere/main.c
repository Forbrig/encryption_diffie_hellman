#include "vigenere_func.h"
#include "vigenere_breaker.h"

int main ( ) {
	char * msg;
	char key[MAX_BUF] = "";
	char* repeated_key;
	char* encrypt;
	char* decrypt;
	int i;

	FILE *in; //in file
	in = fopen("test/test1.txt", "r"); //open file in lecture mode only (frem where te exe is "../")
	if (in == NULL) {
		printf("Cannot open the file...\n");
		exit(0);
	} else {
		printf("Write a key: \n");
		fgets(key, MAX_BUF, stdin);

		msg = file_to_string(in);
		printf("MESSAGE TO ENCRYPT:\n%s\n", msg);

		//ignore the /n from the end of the string
		char auxkey[strlen(key)-1];
		for (i = 0; i < strlen(key) - 1; i++) {
			auxkey[i] = key[i];
		}

		repeated_key = vc_repeat_key(msg, auxkey);
		printf("REPEATED KEY:\n%s\n", repeated_key);

		encrypt = vc_encryption(msg, repeated_key);
		printf("ENCRYPTED MESSAGE:\n%s\n", encrypt);

		fclose(fopen("test/out1.txt", "w")); //clear the content
		FILE *out = fopen("test/out1.txt", "ab+");
		string_to_file(encrypt, out); // trows the encrypted content to a file


		decrypt = vc_decryption(encrypt, repeated_key);
		printf("DECRYPTED MESSAGE:\n%s\n", decrypt);


		/*
		fclose(in);
		fclose(out);
		*/
	}

	/*TESTS*/

	printf("***TRYING TO BREAK THE CIPHER***\n");

	FILE *test1 = fopen("test/out1.txt", "r");

	if (test1 == NULL) {
		printf("Cannot open the file...\n");
		exit(0);
	} else {
		vigenere_breaker(test1);
	}
	system("pause");
	return 0;
}
