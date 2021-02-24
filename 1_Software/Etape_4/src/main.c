#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <assert.h>

int PGCD(int A, int B)
{
	if(A == 0)
		return B;
	if(B == 0)
		return A;
	while(A != B)
	{
		if(A > B)
			A = A - B;
		else 
			B = B - A;
	}

	return A;
}

int main (int argc, char * argv []){
	printf("(II) Starting PGCD program\n");

	// Declaration des variables
	int pgcd = 0, nb1 = 0, nb2 = 0;

	// Verification du nombre des arguments
	assert(argc == 3); // 3 arguments l'executable et les deux nombres

	// Recuperation des arguments
	nb1 = atoi(argv[1]);
	nb2 = atoi(argv[2]);

	// Verification de la valeur des entrées
	assert((nb1 > 1 && nb1 < 65535));
	assert((nb2 > 1 && nb2 < 65535));

	// Calcul du PGCD
	pgcd = PGCD(nb1, nb2);

	printf("Le PGCD de %d et de %d est %d\n", nb1, nb2, pgcd);

	printf("(II) End of PGCD program\n");
  return 0;
}
