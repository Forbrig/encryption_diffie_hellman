#include <stdio.h>
#include <stdlib.h>
#define DIC_SIZE 100
/*
	Here we will use owrds from the dictionary as candidates do be the cipher key,
	if none of these words works we give up (brute force using the just the words in the dictionary).

	There are several technics to break the vigenere cipher, such as frequency analysis or Charles Babbage method.


*/

void vigenere_breaker(FILE*);