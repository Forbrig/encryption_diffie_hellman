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
	buffer[length] = '\0';
	//printf("in file to string: %s\n", buffer);
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

//break the string in a vector of strings (breaking by spaces)
//the last index of the result vector is == NULL so we can loop into it till vector[i] == NULL!
//note: destroy the original string
char** string_break(char* string) {
	int i; //to know the size that the vector should have
	char** string_vector  = malloc(sizeof(char*)); //start the vector
	char* token;
	token = strtok(string, " "); //put the first word in the token
	for (i = 0; token != NULL; i++) {
		string_vector = (char**)realloc(string_vector, (i+1) * sizeof(char*));
		string_vector[i] = (char*)malloc(sizeof(token));
		(string_vector)[i] = token;
		token = strtok(NULL, " ");
	}
	string_vector = (char**)realloc(string_vector, (i+1) * sizeof(char*));
	string_vector[i] = NULL;
	return string_vector;
}

//loop to free alocated array of string
void free_string_array(char** string_array) {
	int i;
	//char * aux;
	for(i = 0; string_array[i] != NULL; i++) { //free the alocated spaces in the indexes
		//printf("%d %s\n", i, string_array[i]);
	}
	free(string_array); //free the array pointer
	return;
}