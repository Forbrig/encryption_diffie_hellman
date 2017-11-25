#include "vigenere_func.h"

int main ( ) {
	char * msg;
	char key[MAX_BUF] = "";
	char* repeated_key;
	char* encrypt;
	char* decrypt;
	

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
		fgets(key, MAX_BUF, stdin);
		repeated_key = vc_repeat_key(msg, key);
		printf("Repeated key:\n%s\n", repeated_key);
	
	
		encrypt = vc_encryption(msg, repeated_key);
		printf("Encrypted:\n%s\n", encrypt);


		fclose(fopen("test/out1.txt", "w")); //clear the content
		FILE *out = fopen("test/out1.txt", "ab+");
		string_to_file(encrypt, out); // trows the encrypted content to a file
	
		
		decrypt = vc_decryption(encrypt, repeated_key);
		printf("Decrypted:\n%s\n", decrypt);
		
		/*
		fclose(in);
		fclose(out);
		*/
	}

	
	
	
	system("pause");
	return 0;
}
