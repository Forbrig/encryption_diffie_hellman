#include <stdio.h>
#include <math.h>

int main ( ) {
	int msg;
	int encrypt, decrypt;
	int p, q, n, d;
	int func, coprime;

	p = 3;
	q = 7;
	n = p * q; // 21
	coprime = 5; // should be calculated automatically
	func = (p - 1) * (q - 1) ;

	
	printf("Write the message (number) to encrypt\n");
	scanf("%d", &msg);


	d = (2 * func + 1) / coprime;
	printf("Private key: %d\n", d);

	encrypt = pow(msg, coprime);
	encrypt = encrypt % n;

	printf("Encrypted: %d\n", encrypt);


	decrypt = pow(encrypt, coprime);
	decrypt = decrypt % n;

	
	printf("Decrypted: %d\n", decrypt);
	
	system("pause");
	return 0;
}

