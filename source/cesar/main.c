#include "cesar_func.h"
#include "cesar_breaker.h"


int main ( ) {
	char * msg;
	char * encrypt;
	char * decrypt;
	int key = 4;


	FILE *in; //in file
	in = fopen("test/test1.txt", "r"); //open file in lecture mode only (frem where te exe is "../")
	if (in == NULL) {
		printf("Cannot open the file...\n");
		exit(0);
	} else {
		msg = file_to_string(in);
		printf("Write a key: ");
		scanf("%d", &key);
		printf("\nMESSAGE TO ENCRYPT:\n%s\n", msg);

		encrypt = cc_encryption(msg, key);
		printf("\nENCRYPTED MESSAGE:\n%s\n", encrypt);

		fclose(fopen("test/out1.txt", "w")); //clear the content
		FILE *out = fopen("test/out1.txt", "ab+");
		string_to_file(encrypt, out); // trows the encrypted content to a file

		decrypt = cc_decryption(encrypt, key);
		printf("\nDECRYPTED MESSAGE:\n%s\n", decrypt);

		/*
		fclose(in);
		fclose(out);
		*/
	}

	/*TESTS*/
	FILE *test1 = fopen("test/out1.txt", "r");

	cesar_breaker(test1);



	return 0;
}
