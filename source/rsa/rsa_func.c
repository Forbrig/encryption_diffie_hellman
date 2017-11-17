#include "rsa_func.h"


int rsa_encryption(int msg, int key) {
	int p = 7;
	int q = 11;
	int n, func;
	int i, j, mult, d;
	
	n = p * q;
	
	func = (p - 1) * (q - 1);
	
	i = func;
	
	while (i > 0) {
		mult = 0;
		for (j = i; j > 0; j--) {
			if (i % j == 0) {
				mult++;
			} 
		}
		if (mult == 2) {
			break;
		}
		i--;
	}
	printf("%d\n", j);
	
	//d = (2 * func + 1) / j;
	
	
	return 1;
	
}
