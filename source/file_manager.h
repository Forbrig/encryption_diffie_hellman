#include <stdio.h>
#include <string.h>
#include <stdlib.h> //dinamic alocation

char* file_to_string(FILE*);
void string_to_file(char*, FILE*);
void realloc_vector_of_string(char**, int);
char** string_break(char*);
