#include <stdio.h>
#include <stdlib.h> //rand func
#include <time.h>
#define DH_PUBLIC_BASE 9 //must be prime
#define DH_PUBLIC_MODULUS 23 //must be prime
#define RAND_RANGE 10 //for personal keys (dont work when range > 10)

typedef struct dh_persona {
	int id;
	int private_key;
	long int encrypted_key; //private_key applied on encryption function
	long int received_encrypt;
	int final_key;
} _persona;

typedef struct dh_public_domain {
	int base;
	int modulus;
} _public_domain;

//_public_domain* dh_new_public_domain(void);
_persona* dh_new_persona(void);
void dh_id_persona(_persona*, int);
int dh_persona_p_key(_persona*);
void dh_receive_encrypt(_persona*, long int);
long int dh_generate_encrypt(_persona*);
int dh_final_key(_persona*);
