#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#include "pgcd.h"

int main (int argc, char * argv []){
	printf("(II) Starting PGCD program\n");

	// Verification du nombre des arguments
	assert(argc == 1); // 1 argument : l'executable

	// Tests unitaires calcul du PGCD
	assert(PGCD(0, 0) == 0);
	assert(PGCD(65535, 65535) == 65535);
	assert(PGCD(0, 65535) == 65535);
	assert(PGCD(65535, 5) == 5);
	assert(PGCD(4, 4) == 4);
	assert(PGCD(128, 32) == 32);


	printf("(II) End of PGCD program\n");
  return 0;
}
