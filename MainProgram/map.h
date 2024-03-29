#ifndef MAP1_H
#define MAP1_H


#include <stdio.h>
#include <stdlib.h>
#include "../Matriks/mapmatriks.h"
#include "mapplayer.h"
#include "../Point/mappoint.h"
#define MAX_FILE_NAME 100

void cls(void);

boolean isWahana(PLAYER P);
// true jika ada wahana di sebelah P

// ----------------------------- LOAD MAP FROM FILE -----------------------------------
void LoadMapFromFile(MAP *M, int Kode, char filename[MAX_FILE_NAME]);

void LoadAllMap (MAP *M1,MAP *M2,MAP *M3,MAP *M4);

// ------------------------------------------- MAP --------------------------------------
void Legenda();
//Print Legenda

void PrintMap(MAP M);
//Tulis Map dan Legenda

void UbahMapAddWahana(PLAYER *P,int map, POINT point_wahana, boolean add);
// merubah map1/2/3/4

void UbahMap(PLAYER *P, boolean isP);
// Mengubah Cmap saat bergerak

void GantiMapPlayer(PLAYER P, MAP M);
//Current map pada PLAYER P diganti menjadi M

char cinMap(MAP M,int X, int Y);
//return char pada koordinat X,Y

// -------------------------------------- GERAK WASD ---------------------------------
void WASD (char C , int *x, int *y);

void pindahPOSMAP (PLAYER *P, MAP M, int newX, int newY);
// pindah pos dan map


// ------------------------------ FUNGSI FMAP -------------------------------------
void FMap(PLAYER *P, char C);
// Menerima input arah w/a/s/d

#endif

