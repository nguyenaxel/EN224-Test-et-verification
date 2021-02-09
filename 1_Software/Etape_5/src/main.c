#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <assert.h>

// Deuxieme methode calcul PGCD
int PGCD2(int A, int B)
{
	int div = 0;
	if(A == 0)
		return B;
	if(B == 0)
		return A;
	while(B != 0)
	{
		div = A % B;
		A = B;
		B = div;
	}
	return A;
}

// Premiere methode calcul PGCD
int PGCD(int A, int B)
{
	// Verification de la valeur des entrées
	assert((A > 1 && A < 65535));
	assert((B > 1 && B < 65535));
	if(A == 0)
		return B;
	if(B == 0)
		return A;
	int pgcd2 = PGCD2(A, B);
	
	while(A != B)
	{
		if(A > B)
			A = A - B;
		else 
			B = B - A;
	}

	// Verification de la valeur de sortie
	assert((A > 1 && A < 65535));
	assert((A == pgcd2));

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

	// Calcul du PGCD
	pgcd = PGCD(nb1, nb2);

	printf("Le PGCD de %d et de %d est %d\n", nb1, nb2, pgcd);

	printf("(II) End of PGCD program\n");
  return 0;
}
