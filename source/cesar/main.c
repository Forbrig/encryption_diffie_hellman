#include "cesar_func.h"

int main ( ) {

	char * msg = "Constantes são usadas em expressões para representar vários tipos de valores. Em C existem regras rígidas para determinar como devem ser escritos estes valores. A seguir iremos mostrar as regras para escrever constantes. ";
	char * encrypt;
	char * decrypt;
	int key = 4;


	printf("%s\n", msg);
	encrypt = cc_encryption(msg, key);
	printf("%s\n", encrypt);


	decrypt = cc_decryption(encrypt, key);
	printf("%s\n", decrypt);

	return 0;
}
