#include <stdio.h>
#include <stdlib.h>
#include "mapplayer.h"
//#include "ADT/mapmatriks.h"

void CreatePlayer (PLAYER *P, MAP M, int initX, int initY) {
    // Assign Attribute Nama, dll
        // pass
    // Assign Posisi Awal dan CMap

    
    // int i = NBrsEff(M) - initY + 1; // ubah x,y jadi i,j
    // int j = initX;
    // CGedung(*P) = Elmt(M,i,j);
    
    PindahPOS(P, initX, initY);
    PindahMAP(P, M);
}
void PindahPOS (PLAYER *P, int newX, int newY) {
// pindah titik, inget index matriks sama kartesius beda jadi we lieur dari tadi
// misal A(4,1) -> di matriks (3,4)

    PosisiX(*P) = newX;
    PosisiY(*P) = newY;

    // ubah x,y jadi i,j
    int i = NBrsEff(CMap(*P)) - newY + 1;
    int j = newX;

    if (Elmt(CMap(*P),i,j) != 'P')
        CGedung(*P) = Elmt(CMap(*P),i,j);
}
void PindahMAP(PLAYER *P, MAP M) {
    // M = Map baru, dicopy ke CMap dan RealMap
    CopyMAP(M,&CMap(*P));
    Kode(CMap(*P)) = Kode(M);
    CopyMAP(M,&RealMap(*P));
    Kode(RealMap(*P)) = Kode(M);
    CGedung(*P) = '-';
}