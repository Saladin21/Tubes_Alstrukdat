#include <stdio.h>
#include <stdlib.h>
#include "mapplayer.h"


void PindahPosisi (PLAYER *P, MAP M, int newX, int newY)
// pindah titik, inget index matriks sama kartesius beda jadi we lieur dari tadi
// misal A(4,1) -> di matriks (3,4)
{
    CMap(*P) = M;
    PosisiX(*P) = newX;
    PosisiY(*P) = newY;
    int i,j;
    XYtoIJ(newX,newY,&i,&j,NBrsEff(M));
    if (Elmt(M,i,j) != 'P')
        CGedung(*P) = Elmt(M,i,j);
}
void XYtoIJ (int X, int Y, int *i, int *j, int lenBrsM)
{
    *i = lenBrsM - Y + 1;
    *j = X;
}