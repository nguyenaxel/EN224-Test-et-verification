#include "pgcd.h"

// Premiere methode calcul PGCD
int PGCD(int A, int B)
{
	// Verification de la valeur des entrées
	assert((A >= 0 && A <= 65535));
	assert((B >= 0 && B <= 65535));

	int pgcd2 = PGCD2(A, B);
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

	// Verification de la valeur de sortie
	assert((A >= 0 && A <= 65535));
	assert((A == pgcd2));

	return A;
}

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