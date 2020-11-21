#include <stdio.h>
#include <stdlib.h>
#include "ADT/mapmatriks.h"
#include "ADT/mapmatriks.c"
#include "mapplayer.c"
#include "mapplayer.h"
#include "ADT/mappoint.h"
#include "ADT/mappoint.c"

/*

Buat Ngakses bangunan, antrian,wahana, atau office
office : if (CGedung(P) = 'O')
antrian : if (CGedung(P) = 'A')
wahana : if (isWahana(P))

Diprogram Utama (CORET-CORETAN DOANG YG INI MAH):
CreatePlayer();
MAP M1,M2,M3,M4;
LoadMap(M1,M2,M3,M4);

while (true)
    PrintMap();
    Fungsi_Nama_Money_dll();
    Minta_input_perintah(input);
    
    if ( input = W/A/S/D )
        FMap();
        cls();
    else (misal upgrade, buy, dll)
        Contoh();
    cls();
*/

// ------------------------------ CLEAR, ISWAHANA ------------------------------------
void cls(void) {
    system("cls||clear");
    return;
}
boolean isWahana(PLAYER P) {
    // true jika ada wahana di sebelah P
    int i,j;
    char cu, cd, cl, cr; // char up,down,left right
    XYtoIJ(PosisiX(P),PosisiY(P),&i,&j,NBrsEff(CMap(P))); // cari index(i,j) player pada matrix
    cu = Elmt(CMap(P),i-1,j);
    cd = Elmt(CMap(P),i+1,j);
    cl = Elmt(CMap(P),i,j-1);
    cr = Elmt(CMap(P),i,j+1);
    return (cu == 'W' || cd == 'W' || cl == 'W' || cr == 'W');
}
// ------------------------------------------- MAP --------------------------------------
void Legenda() {
    // print legenda
    printf("\nLegenda:\nA = Antrian\nP = Player\nW = Wahana\nO = Office\n<, ^, >, V = Gerbang\n");
}

void PrintMap(MAP M) {
    // tulismap dan legenda
    TulisMAP(M); Legenda();
}
void
 LoadMap(MAP *M1,MAP *M2,MAP *M3,MAP *M4) {
    // load map dari file
    printf("belum");
}

void UbahMap (PLAYER *P, boolean isP) {
// Jadi kalau P nya gerak Cmap nya berubah

    int i,j;
    XYtoIJ(PosisiX(*P),PosisiY(*P),&i,&j,NBrsEff(CMap(*P)));

    if (isP)
        Elmt(CMap(*P),i,j) = 'P';
    else
        Elmt(CMap(*P),i,j) = CGedung(*P);
    
}
void GantiMapPlayer (PLAYER P,MAP M) {
// current map player diganti jadi M

    CMap(P) = M;
}

char cinMap (MAP M,int X,int Y) {
// return char pada koordinat X,Y

    int i,j;
    XYtoIJ(X,Y,&i,&j,NBrsEff(M));
    return Elmt(M,i,j);
}

// -------------------------------------- GERAK WASD ---------------------------------
void WASD (char C /* ini KATA */, int *x, int *y)
{
    *x = 0; *y = 0;
    if (C == 'W' || C == 'w') {
        *y = 1;
    }
    else if (C == 'A' || C == 'a') {
        *x = -1;
    }
    else if (C == 'S' || C == 's') {
        *y = -1;
    }
    else if (C == 'D' || C == 'd') {
        *x = 1;
    }
    else {
        *x = 0; *y = 0;
    }
}
void pindahPOSMAP (PLAYER *P, MAP M, int newX, int newY) {
    // pindah pos dan map
    UbahMap(P,false);
    PindahPOS(P,newX,newY);
    // Kalau Map berubah
    if (!(EQ(RealMap(*P),M)))
        PindahMAP(P,M);
    UbahMap(P,true);

}

// ------------------------------ FUNGSI FMAP -------------------------------------
void FMap(PLAYER *P, char C, MAP M1,MAP M2,MAP M3,MAP M4) {
    // Minta input arah W/A/S/D
    int x,y;
    WASD(C, &x, &y);
    MAP Mnew; // kalau pindah map

    // Kordinat baru x,y dan i,j
    int nX = PosisiX(*P)+x; int nY = PosisiY(*P)+y;

    int ni,nj;
    XYtoIJ(nX,nY,&ni,&nj,NBrsEff(CMap(*P)));

    // Gerak ke Objek

    // Kalau tidak lebih dari index maksimal
    if (ni<=NBrsEff(CMap(*P)) && nj<=NKolEff(CMap(*P))) {

        // Bukan Tembok (*)
        if (cinMap(CMap(*P),nX,nY) != '*' && cinMap(CMap(*P),nX,nY) != 'W') {

            // < > v ^ tiap Map
            if ( cinMap(CMap(*P),nX,nY) == '^' || cinMap(CMap(*P),nX,nY) == 'V') {
                // ini EQnya salah, soalnya CMap pasti beda
                int majuy = 0;
                if (EQ(RealMap(*P),M1)) {
                    Mnew = M4;
                    majuy = -1;
                } else if (EQ(RealMap(*P),M2)) {
                    Mnew = M3;
                    majuy = -1;
                } else if (EQ(RealMap(*P),M3)) {
                    Mnew = M2;
                    majuy = 1;
                } else if (EQ(RealMap(*P),M4)) {
                    Mnew = M1;
                    majuy = 1;
                } else
                    printf("\nMap Error\n");
                pindahPOSMAP(P,Mnew,GerbangY(Mnew).X,GerbangY(Mnew).Y+majuy);
            } else if ( cinMap(CMap(*P),nX,nY) == '<' || cinMap(CMap(*P),nX,nY) == '>') {
                int majux = 0;
                if (EQ(RealMap(*P),M1)) {
                    Mnew = M2; majux = 1;
                } else if (EQ(RealMap(*P),M2)) {
                    Mnew = M1; majux = -1;
                } else if (EQ(RealMap(*P),M3)) {
                    Mnew = M4; majux = -1;
                } else if (EQ(RealMap(*P),M4)) {
                    Mnew = M3; majux = 1;
                } else
                    printf("\nMap Error\n");
                pindahPOSMAP(P,Mnew,GerbangX(Mnew).X+majux,GerbangX(Mnew).Y);

            } else {
                pindahPOSMAP(P,RealMap(*P),nX,nY);
            }
        }
    }
}

int main() { // INI DITARO DI PROGRAM UTAMA
    MAP M1,M2,M3,M4;
    // nanti di ganti load dari file
    MakeMAP(10,20,&M1); MakeMAP(10,20,&M2); MakeMAP(10,20,&M3); MakeMAP(10,20,&M4);
    BacaMAP(&M1,10,20); BacaMAP(&M2,10,20); BacaMAP(&M3,10,20); BacaMAP(&M4,10,20);
    // assign player di x,y = (3,3), ini bebas nanti ganti
    PLAYER P;
    CreatePlayer(&P,M1,3,3);
    UbahMap(&P,true);
    cls();
    while (true) {
        char C;
        printf("\n");
        PrintMap(CMap(P));
        printf("\nInput W/A/S/D : ");
        scanf(" %c",&C);
        if (C == 'W' || C == 'A' ||C == 'S' ||C == 'D' || C == 'w' || C == 'a' ||C == 's' ||C == 'd')
            FMap(&P, C, M1, M2, M3, M4);
        else
            break;
        cls();
    }
    return 0;
}
