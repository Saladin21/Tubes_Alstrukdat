// gabungin ke ADT PLAYER YG ASLI

#ifndef PLAYER_H
#define PLAYER_H

#include "ADT/mapmatriks.h"
#include "ADT/boolean.h"
#include "ADT/mappoint.h"

typedef struct {
	// Kata NAME;
	MAP CMap; // current map
	MAP RealMap; // Ga diubah, untuk EQ(RealMap,M1)
	POINT POS;
	char CGedung; // lagi nginjek apa, 'O','-' atau apa
	int money;
} PLAYER;

#define CMap(P) (P).CMap
#define RealMap(P) (P).RealMap
#define Posisi(P) (P).POS
#define PosisiX(P) (P).POS.X
#define PosisiY(P) (P).POS.Y
#define CGedung(P) (P).CGedung
#define Money(P) (P).money

void CreatePlayer (PLAYER *P, MAP M, int newX, int newY);

void PindahPOS (PLAYER *P, int newX, int newY);
// pindah titik
void PindahMAP (PLAYER *P, MAP M);
// pindah MAP


#endif