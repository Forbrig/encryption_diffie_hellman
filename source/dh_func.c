#include "dh_persona.h"

void dh_init_func(_public_domain* public) {
	_public_domain* new = (_public_domain *) malloc (sizeof(_public_domain));
	new->base = DH_PUBLIC_BASE;
	new->modulus = DH_PUBLIC_MODULUS;
	return public;
}

_persona* dh_new_persona(void) {
	_persona* new = (_persona *) malloc (sizeof(_persona));
	new->id = 0;
	new->private_key = 0;
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
