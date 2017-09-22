#include "dh_persona.h"

time_t t;

int main ( ) {
	/* rand generator - must be inside a function */
	srand((unsigned) time(&t));
	
	_public_domain* public;
	_persona* alice;
	_persona* bob;
	
	public = dh_init_func(public);
	
	alice = dh_new_persona();
	bob = dh_new_persona();
	
	dh_id_persona(alice, 1);
	dh_id_persona(bob, 2);
	
	//printf("%d\n", dh_persona_p_key(alice));
	//printf("%d\n", dh_persona_p_key(bob));

	return 0;
}
