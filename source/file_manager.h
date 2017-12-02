#include <stdio.h>
#include <string.h>
#include <stdlib.h> //dinamic alocation

char* file_to_string(FILE*);
void string_to_file(char*, FILE*);
char** string_break(char*);
void free_string_array(char**);
