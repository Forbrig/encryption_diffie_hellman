#include "file_manager.h"

char* file_to_string(FILE * file) {
	char * buffer = 0;
	int length;
	
	if (file == NULL) {
		printf("Cannot open the file...\n");
		exit(0);
	} else {
		fseek(file, 0, SEEK_END); //set the seek on END
		length = ftell(file);
		fseek(file, 0, SEEK_SET); //set the seek on START
		buffer = malloc(length);
		if (buffer) {
			fread(buffer, 1, length, file);
		}
		fclose(file);
	}
	return buffer;
}

void string_to_file(char* encrypt, FILE * file) {
	if (file == NULL) {
		printf("Couldn't open/create the encrypt file...\n");
		exit(0);
	} else {
		fputs(encrypt, file);
		fclose(file);
	}
	return;
}

