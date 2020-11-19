// gabungin ke ADT PLAYER YG ASLI

#ifndef PLAYER_H
#define PLAYER_H

#include "ADT/mapmatriks.h"
#include "ADT/boolean.h"
#include "ADT/mappoint.h"

typedef struct {
	// Kata NAME;
	MAP CMap; // current map
	POINT POS;
	char CGedung; // lagi nginjek apa, 'O','-' atau apa
} PLAYER;

#define CMap(P) (P).CMap
#define Posisi(P) (P).POS
#define PosisiX(P) (P).POS.X
#define PosisiY(P) (P).POS.Y
#define CGedung(P) (P).CGedung

void PindahPosisi (PLAYER *P, MAP M, int newX, int newY);
// pindah titik
void XYtoIJ (int X, int Y, int *i, int *j, int lenBrsM);
// ngerubah xy jadi ij

#endif