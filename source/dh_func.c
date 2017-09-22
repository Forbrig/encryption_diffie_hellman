#include "dh_persona.h"

/*
_public_domain* dh_new_public_domain(void) {
	_public_domain* new = (_public_domain *) malloc (sizeof(_public_domain));
	new->base = DH_PUBLIC_BASE;
	new->modulus = DH_PUBLIC_MODULUS;
	return new;
}
*/

_persona* dh_new_persona(void) {
	_persona* new = (_persona *) malloc (sizeof(_persona));
	new->id = 0;
	new->private_key = 0;
	new->encrypted_key = 0;
	new->received_encrypt = 0;
	new->final_key = 0;
	return new;
}

void dh_id_persona(_persona* x, int i) {
	x->id = i;
}

int dh_persona_p_key(_persona* x) {
	x->private_key = rand() % RAND_RANGE;
	return x->private_key;
}

void dh_receive_encrypt(_persona* p, long int x) {
	p->received_encrypt = x;
}

long int dh_generate_encrypt(_persona* p) {
	p->encrypted_key = (DH_PUBLIC_BASE^p->private_key) % DH_PUBLIC_MODULUS;
	return p->encrypted_key;
}

int dh_final_key(_persona* p) {
	p->final_key = (p->received_encrypt^p->private_key) % DH_PUBLIC_MODULUS;
	return p->final_key;
}
