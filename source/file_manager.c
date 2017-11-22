#include "file_manager.h"

int main () {
	char * buffer = 0;
	char * aux;
	int length;
	FILE *in; //in file
	in = fopen("in.txt", "r"); //open file in lecture mode only
	
	if (in == NULL) {
		printf("Cannot open the file\n");
		return 0;
	} else {
		fseek(in, 0, SEEK_END); //set the seek on END
		length = ftell(in);
		fseek(in, 0, SEEK_SET); //set the seek on START
		buffer = malloc(length);
		if (buffer) {
			fread(buffer, 1, length, in);
			printf("%s\n", buffer);
		}
		fclose(in);
	}
	return 0;
}
