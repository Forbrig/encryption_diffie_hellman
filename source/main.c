#include "dh_persona.h"

time_t t;

int main ( ) {
	/* rand generator - must be inside a function */
	srand((unsigned) time(&t));
	
	//_public_domain* public;
	_persona* alice;
	_persona* bob;
	
	//public = dh_new_public_domain();
	
	alice = dh_new_persona();
	dh_id_persona(alice, 1);
	dh_persona_p_key(alice); //generate random key
	int alice_enc = dh_generate_encrypt(alice);
	
	bob = dh_new_persona();
	dh_id_persona(bob, 2);
	dh_persona_p_key(bob); //generate random key
	int bob_enc = dh_generate_encrypt(bob);
	
	dh_receive_encrypt(bob, alice_enc);
	
	
	dh_receive_encrypt(alice, bob_enc);
	
	printf("ALICE PRIVATE KEY %d\n", alice->private_key);
	printf("BOB PRIVATE KEY %d\n", bob->private_key);
	
	printf("ALICE PRIVATE KEY %d\n", alice->encrypted_key);
	printf("BOB PRIVATE KEY %d\n", bob->encrypted_key);
	
	printf("ALICE FINAL KEY %d\n", dh_final_key(alice));
	printf("BOB FINAL KEY %d\n", dh_final_key(bob));
	
	return 0;
}
