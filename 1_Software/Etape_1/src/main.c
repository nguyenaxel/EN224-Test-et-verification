#include "stdio.h"
#include "stdlib.h"
#include "math.h"

void exit_if(int condition, const char *prefix)
{
    if (condition) {
        perror(prefix);
        exit(EXIT_FAILURE);
    }
}

int PGCD(int A, int B)
{
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
	exit_if(argc != 3, "Nombre d'arguments incorrect, veuillez rentrer 2 nombres entre 1 et 65535"); // 3 arguments l'executable et les deux nombres

	// Recuperation des arguments
	nb1 = atoi(argv[1]);
	nb2 = atoi(argv[2]);

	// Verification de la valeur des arguments
	exit_if((nb1 < 1 || nb1 > 65535), "Nombre 1 incorrect, veuillez rentrer un nombre entre 1 et 65535");
	exit_if((nb2 < 1 || nb2 > 65535), "Nombre 2 incorrect, veuillez rentrer un nombre entre 1 et 65535");

	// Calcul du PGCD
	pgcd = PGCD(nb1, nb2);
	printf("Le PGCD de %d et de %d est %d\n", nb1, nb2, pgcd);

	printf("(II) End of PGCD program\n");
  return 0;
}
