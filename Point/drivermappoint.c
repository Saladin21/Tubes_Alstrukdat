#include "mappoint.h"
#include <stdio.h>

int main(){
    POINT P;
    printf("Masukkan point P(X, Y) : \n");
    BacaPOINT(&P);
    printf("P(X, Y) = ("); TulisPOINT(P); printf(")\n");
    POINT O = MakePOINT(0,0);
    printf("Memiliki panjang: %f\n", Panjang(P, O));
    // fungsi
    int i, j, baris;
    printf("Merubah P(X,Y) menjadi elemen matriks (i,j) dengan panjang baris 10: \n");
    TulisPOINT(P); printf(" -> "); XYtoIJ(Absis(P), Ordinat(P), &i, &j, 10); printf("(%d,%d)\n", i, j);
    printf("Merubah indeks elemen matriks (5,6) dengan panjang baris 10 ke POINT: \n");
    int X, Y;
    IJtoXY(&X, &Y, 5, 6, 10);
    POINT P1 = MakePOINT(X, Y);
    printf("(5,6) -> ("); TulisPOINT(P1); printf(")\n");
    
}
// gcc drivermappoint.c mappoint.c -o drivermappoint