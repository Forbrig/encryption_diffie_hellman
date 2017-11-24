#include "file_manager.h"

char* file_to_string(void) {
	char * buffer = 0;
	int length;
	FILE *in; //in file
	in = fopen("../in.txt", "r"); //open file in lecture mode only (frem where te exe is "../")
	
	if (in == NULL) {
		printf("Cannot open the file...\n");
		exit(0);
	} else {
		fseek(in, 0, SEEK_END); //set the seek on END
		length = ftell(in);
		fseek(in, 0, SEEK_SET); //set the seek on START
		buffer = malloc(length);
		if (buffer) {
			fread(buffer, 1, length, in);
			//buffer[length] = '\0';
			//printf("%s\n", buffer);
		}
		fclose(in);
	}
	return buffer;
}

void string_to_file(char* encrypt) {
	fclose(fopen("../cesar_encrypt.txt", "w")); //clear the content
	FILE *cesar_encrypt = fopen("../cesar_encrypt.txt", "ab+");
	if (cesar_encrypt == NULL) {
		printf("Couldn't open/create the encrypt file...\n");
		exit(0);
	} else {
		fputs(encrypt, cesar_encrypt);
		fclose(cesar_encrypt);
	}
	return;
}