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
	int i, bigger = 0, ind = 0;

	for (i = 0; i < 256; i++) {
		if (vec[i] > bigger) {
			bigger = vec[i];
			ind = i;
		}
	}
	return ind;
}


char *sc_breaker(char* msg, int freq[]) {
	int i, m, size = strlen(msg), j;
	int count_array[256];
	char new_key[256];
	char* decrypt = malloc(sizeof(char*) * size);

	// Initialize the counting vector with zero
	for (i = 0; i < 256; i++){
		count_array[i] = 0;
		new_key[i] = 0;
	}

	// Count the frequency
	for (i = 0; i < size; i++) {
		count_array[(int)msg[i]]++;
	}


	for (i = 0; i < 26; i++) {
		m = pop(count_array, -1);
		new_key[m] = freq[i];
		count_array[m] = -1;
	}

	// Decrypt
	for (i = 0; i < size; i++) {
		decrypt[i] = new_key[(int)msg[i]];
	}

	return decrypt;
}
