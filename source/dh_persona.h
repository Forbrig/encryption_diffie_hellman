#include <stdio.h>
#include <stdlib.h> //rand func
#include <time.h>
#define DH_PUBLIC_BASE 3 //must be prime
#define DH_PUBLIC_MODULUS 23 //must be prime
#define RAND_RANGE 100 //for personal keys

typedef struct dh_persona {
	int id;
	int private_key;
	int final_key;
} _persona;

typedef struct dh_public_domain {
	int base;
	int modulus;
} _public_domain;

_public_domain* dh_init_func(_public_domain*);
_persona* dh_new_persona(void);
void dh_id_persona(_persona*, int);
int dh_persona_p_key(_persona*);
