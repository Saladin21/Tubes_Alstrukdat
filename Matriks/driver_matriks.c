#include<stdio.h>
#include "matriks.h"

int main(){
	//KAMUS
	int nbrs, nkol;
	float det;
	MATRIKS M;
	ElType max, min;
	ElType x = 1;
	//ALGORITMA
	scanf("%d %d", &nbrs, &nkol);
	BacaMATRIKS(&M, nbrs, nkol);
	TulisMATRIKS(M);
	printf("\n");
	printf("ratabrs1 %.2f \n",RataBrs(M, 1));
	printf("ratakol1 %.2f \n",RataKol(M,1));
	printf("test\n");
	MaxMinBrs(M, 1, &max, &min);
	printf("test\n");
	printf("%d %d", max, min);
	MaxMinKol(M, 1, &max, &min);
	printf("test\n");
	printf("%d %d", max, min);
	printf("%d", CountXBrs(M, 1, 1));
	printf("%d", CountXKol(M, 1, 1));
	det = Determinan(M);
	printf("%.2f", det);
	return 0;
}