#include <string.h>
#include <stdlib.h>
#include "substitution_func.h"


char *sc_encryption(char* msg, char key[]) {
	int i, size = strlen(msg);
	char* encrypt = malloc(size * sizeof(char));

	for (i = 0; i < size; i++) {
		encrypt[i] = key[(int)msg[i]];
	}
	return encrypt;
}


char *sc_decryption(char* msg, char key[]) {
	int i, j, size = strlen(msg);
	char* decrypt = malloc(size * sizeof(char));

	for (j = 0; j < size; j++) {
		for (i = 0; i < 256; i++) {
			if (key[i] == msg[j]) {
				decrypt[j] = i;
				break;
			}
		}
	}
	return decrypt;
}



int pop(int vec[256], int val) {
	int i, bigger = 0;

	for (i = 0; i < 256; i++) {
		if (vec[i] > bigger) bigger = i;
	}
	vec[i] = val;
	return i;
}


char *sc_breaker(char* msg, int key[]) {
	int i, size = strlen(msg);
	int count_array[256];

	// Initialize the counting vector with zero
	for (i = 0; i < 256; i++)
		count_array[i] = 0;

	// Count the frequency
	for (i = 0; i < size; i++)
		count_array[(int)msg[i]]++;



	char* decrypt = malloc(size * sizeof(char));

	return decrypt;
}
