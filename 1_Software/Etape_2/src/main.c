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

int RandA()
{
	return rand()%MAX_VALUE;
}

int RandB()
{
	return rand()%MAX_VALUE;
}

int main (int argc, char * argv []){
	printf("(II) Starting PGCD program\n");

	// Declaration des variables
	int pgcd = 0, nbtest = 0, nb1 = 0, nb2 = 0;

	// Verification du nombre des arguments
	exit_if(argc != 2, "Nombre d'arguments incorrect, veuillez rentrer un seul nombre"); // 2 arguments l'executable et le nombre de test à faire

	// Recuperation des arguments
	nbtest = atoi(argv[1]);

	// Verification de la valeur des arguments
	exit_if((nbtest < 0), "Nombre 1 incorrect, veuillez rentrer un nombre entre 1 et 65535");

	// Calcul du PGCD
	for(int i = 0; i < nbtest; i++)
	{
		nb1 = RandA();
		nb2 = RandB();
		pgcd = PGCD(nb1, nb2);
		printf("Le PGCD de %5d et de %5d est %5d\n", nb1, nb2, pgcd);
	}

	printf("(II) End of PGCD program\n");
  return 0;
}
