#include <stdio.h>
#include <stdlib.h>
#include "ADT/mapmatriks.h"
#include "ADT/mapmatriks.c"
#include "mapplayer.c"
#include "mapplayer.h"
#include "ADT/mappoint.h"
#include "ADT/mappoint.c"
// ada 4 peta / bagian
// gerak W,A,S,D
// gerbang untuk pindah peta : < > v ^
// kosong (player bisa pindah ke sini) : -
// border / dinding : *

// Program
// Jadi intinya matriksnya diubah, terus di print
// Kalau ketemu tembok (*), posisi tetap
// Kalau ketemu gerbang, pindah map
// kalau ketemu (-), gerak

// Data yang diperlukan
// Posisi i,j player
// index tembok (Panjang baris dan kolom)

// variabel yang kira2 perlu
// index pemain, map keberapa

// 
void cls(void)
{
    system("cls||clear");
    return;
}
void UbahMap (PLAYER P,MAP *M, boolean isP)
// buat ngeprintnya, jadi misal Player pindah ada char yg berubah
{
    int i,j;
    XYtoIJ(PosisiX(P),PosisiY(P),&i,&j,NBrsEff(*M));
    if (isP)
        Elmt(*M,i,j) = 'P';
    else
        Elmt(*M,i,j) = CGedung(P);
    
}
void GantiMap (PLAYER P,MAP M)
{
    CMap(P) = M;
}

char CharinMap (MAP M,int X,int Y)
// return char pada koordinat X,Y
{
    int i,j;
    XYtoIJ(X,Y,&i,&j,NBrsEff(M));
    return Elmt(M,i,j);
}
boolean cEQ (char a,char b)
// true jika a == b
{
    return (a == b);
}

int main() {
    MAP Map1;
    // nanti di ganti load dari file
    BacaMAP(&Map1,10,20);
    
    printf("\n\n");
    // assign player
    PLAYER P;
    PindahPosisi(&P,Map1,3,3);
    UbahMap(P,&Map1,true);
    cls();
    
    while (true) {
        char input;
        TulisMAP(Map1);
        TulisPOINT(Posisi(P));
        int i,j;
        XYtoIJ(PosisiX(P),PosisiY(P),&i,&j,NBrsEff(Map1));
        printf("\n%d,%d",i,j);
        printf("\n%c",CGedung(P));

        printf("\nInput WASD : ");
        scanf(" %c",&input);
        int x,y;
        if (input == 'W' || input == 'w') {
            x = 0; y = 1;
        }
        else if (input == 'A' || input == 'a') {
            x = -1; y = 0;
        }
        else if (input == 'S' || input == 's') {
            x = 0; y = -1;
        }
        else if (input == 'D' || input == 'd') {
            x = 1; y = 0;
        }
        else {
            break;
        }
        int newX = PosisiX(P)+x; int newY = PosisiY(P)+y;
        int newi,newj;
        XYtoIJ(newX,newY,&newi,&newj,NBrsEff(Map1));

        if (newi<=NBrsEff(Map1) && newj<=NKolEff(Map1)) { // ga lebih dari ukuran matriks
            if (!(cEQ(CharinMap(Map1,newX,newY),'*'))) { // jika bukan tembok '*'
                UbahMap(P,&Map1,false);
                PindahPosisi(&P,Map1,newX,newY);
                UbahMap(P,&Map1,true);

                if (cEQ(CGedung(P),'v'))
                    GantiMap(P,Map1);
                else if (cEQ(CGedung(P),'<'))
                    GantiMap(P,Map1);
                else if (cEQ(CGedung(P),'>'))
                    GantiMap(P,Map1);
                else if (cEQ(CGedung(P),'^'))
                    GantiMap(P,Map1);
                else if (cEQ(CGedung(P),'A'))
                    printf("antrian");
                else if (cEQ(CGedung(P),'O'))
                    printf("office");
                else if (cEQ(CGedung(P),'W'))
                    printf("WAHANA");

            }
        }
        cls();
    }
    return 0;
}