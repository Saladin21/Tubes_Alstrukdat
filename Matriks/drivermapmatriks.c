#include <stdio.h>
#include "mapmatriks.h"
#include "../MainProgram/map.h"

int main(){
    MAP M1, M2;
    LoadMapFromFile(&M1, 1,"../MainProgram/map1.txt");
    LoadMapFromFile(&M2, 2,"../MainProgram/map2.txt");
    int fbrs, fkol, lbrs, lkol, fbrs2, fkol2, lbrs2, lkol2;
    printf("Map 1: \n");
    TulisMAP(M1);
    printf("\nM1:\n*First Baris: %d\n*First Kolom: %d\n*Last Baris: %d\n*Last Kolom: %d\n", GetFirstIdxBrs(M1), GetFirstIdxKol(M1), GetLastIdxBrs(M1), GetLastIdxKol(M1));
    printf("Mengecek indeks i dan j merupakan indeks valid dan efektif bagi M1 atau tidak: \n");
    int i, j;
    printf("Masukkan i dan j: ");
    scanf("%d %d", &i, &j);
    if (IsIdxValid(i, j)){
        if (IsIdxEff(M1, i, j)){
            printf("i = %d, j = %d adalah indeks yang valid dan indeks efektif\n", i, j);
        } else{
            printf("i = %d, j = %d adalah indeks yang valid\n", i, j);
        }
    } else{
        printf("i = %d, j = %d adalah indeks yang tidak valid\n", i, j);
    }
    printf("Map 2: \n");
    TulisMAP(M2);
    printf("\nM2:\n*First Baris: %d\n*First Kolom: %d\n*Last Baris: %d\n*Last Kolom: %d\n", GetFirstIdxBrs(M2), GetFirstIdxKol(M2), GetLastIdxBrs(M2), GetLastIdxKol(M2));
    printf("Mengecek indeks i dan j merupakan indeks valid dan efektif bagi M2 atau tidak: \n");
    int i2, j2;
    printf("Masukkan i dan j: ");
    scanf("%d %d", &i2, &j2);
    if (IsIdxValid(i2, j2)){
        if (IsIdxEff(M2, i2, j2)){
            printf("i = %d, j = %d adalah indeks yang valid dan indeks efektif\n", i2, j2);
        } else{
            printf("i = %d, j = %d adalah indeks yang valid\n", i2, j2);
        }
    } else{
        printf("i = %d, j = %d adalah indeks yang tidak valid\n", i2, j2);
    }
    printf("Mengecek apakah matriks M1 dan M2 sama atau tidak: \n");
    if (EQ(M1, M2)){
        printf("M1 dan M2 adalah matriks yang equivalen\n");
    } else{
        printf("M1 dan M2 adalah matriks yang tidak equivalen\n");
    }
}

// gcc drivermapmatriks.c ../MainProgram/map.c -o drivermapmatriks