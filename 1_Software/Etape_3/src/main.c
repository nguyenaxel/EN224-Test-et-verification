#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <time.h>

#define MAX_VALUE 65535

void exit_if(int condition, const char *prefix)
{
    if (condition) {
        perror(prefix);
        exit(EXIT_FAILURE);
    }
}

// Premiere methode calcul PGCD
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

int main (int argc, char * argv []){
	printf("(II) Starting PGCD program\n");

	// Declaration des variables
	int pgcd = 0, pgcd2 = 0, nb_erreur = 0, j = 28;

	// Verification du nombre des arguments
	exit_if(argc != 1, "Aucun argument demandé"); // 1 argument : l'executable

	// Calcul du PGCD
	for(int i = 0; i < MAX_VALUE; i++)
	{
		pgcd = PGCD(i, j);
		pgcd2 = PGCD2(i, j);
		if(pgcd == pgcd2)
			printf("Le PGCD de %5d et de %5d est %5d(validé)\n", i, j, pgcd);
		else
		{
			printf("Erreur calcul PGCD %d != %d\n", pgcd, pgcd2);
			nb_erreur++;
		}
		
	}

	printf("Nombre d'erreur : %d\n", nb_erreur);

	printf("(II) End of PGCD program\n");
  return 0;
}
