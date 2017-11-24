#include "cesar_func.h"


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
		printf("Message to encrypt\n");
		msg = file_to_string(in);
		printf("%s\n", msg);
		printf("Write a key\n");
		scanf("%d", &key);
	
		encrypt = cc_encryption(msg, key);
		printf("Encrypted message:\n%s\n", encrypt);
		fclose(fopen("test/out1.txt", "w")); //clear the content
		FILE *out = fopen("test/out1.txt", "ab+");
		string_to_file(encrypt, out); // trows the encrypted content to a file
	
		decrypt = cc_decryption(encrypt, key);
		printf("Decrypted message:\n%s\n", decrypt);
	}	

	return 0;
}
