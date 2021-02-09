#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#include "pgcd.h"

#define MAX_VALUE 65536

int main (int argc, char * argv []){
	printf("(II) Starting PGCD program\n");

	FILE *file_A = NULL, *file_B = NULL, *file_C = NULL;
	file_A = fopen ("./src/ref_A.txt", "r");
	file_B = fopen ("./src/ref_B.txt", "r");
	file_C = fopen ("./src/resu_C.txt", "w");


	int pgcd = 0, a = 0, b = 0;

	for(int i = 0; i < MAX_VALUE; i++)
	{
		fscanf(file_A, "%d", &a);
		fscanf(file_B, "%d", &b);
		pgcd = PGCD(a,b);
		fprintf(file_C, "%d\r\n", pgcd);
	}

	fclose(file_A);
	fclose(file_B);
	fclose(file_C);


	printf("(II) End of PGCD program\n");
	return 0;
}
