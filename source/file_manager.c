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

//increase/decrease amount of allocated strings
void realloc_vector_of_string(char** string, int new_size) {
	printf("new size: %d %d\n", new_size, sizeof(&string));
	string = realloc(string, new_size);
	return;
}

//break the string in a vector of strings (breaking by spaces)
//destroy the original string
char** string_break(char* string) {
	int i, count = 0; //to know the size that the vector should have
	char** string_vector  = malloc(sizeof(char*)); //start the vector
	char* token;
	token = strtok(string, " "); //put the first word in the token
	for (i = 0; token != NULL; i++) {
		count++;
		realloc_vector_of_string(string_vector, count);
		string_vector[i] = malloc(sizeof(token));
		//string_vector[i] = malloc(sizeof(token)+1);
		string_vector[i] = token;
		//string_vector[i][sizeof(token)+1] = '\0';
		printf("%s\n", string_vector[i]);
		token = strtok(NULL, " ");
	}
	return string_vector;
}

/*
//number of strings in the string vector
int size_of_string_vector (char** string_vector) {
	int count;
	
	
	
	
	return count;
}
*/
