#include <stdio.h>
#include <stdlib.h>
#include "ADT/mapmatriks.h"
#include "ADT/mapmatriks.c"
#include "mapplayer.c"
#include "mapplayer.h"
#include "ADT/mappoint.h"
#include "ADT/mappoint.c"
#define MAX_FILE_NAME 100

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
// ----------------------------- LOAD MAP FROM FILE -----------------------------------
void LoadMapFromFile(MAP *M, int Kode, char filename[MAX_FILE_NAME]) {

    // hitung jumlah char,brs,kol pada file
    FILE *fp = fopen(filename,"r");
    char c;
    int jmlEl = 0; int brs = 1;
    for (c = getc(fp); c != EOF; c = getc(fp)) {
        if (c != '\n' && c != '\r')
            jmlEl++;
        if (c == '\n')
            brs++;
    }
    fclose(fp);
    int kol = jmlEl/brs;

    // isi array temp
    FILE *fp1 = fopen(filename,"r");
    char c1; 
    char temp[jmlEl];

    int i = 0;
    while ((c1 = fgetc(fp1))!=EOF) {
        if (c1 != '\n' && c1 != '\r') {
            temp[i] = c1;
            i++;
        }
    }

    // BUAT MAP
    MakeMAP(brs,kol,M);
    
    // ISI
    int step = 0; int x,y;
    for (int i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++){
        for(int j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
            Elmt(*M,i,j) = temp[step];
            // Assign Point gerbang
			IJtoXY(&x,&y,i,j,GetLastIdxBrs(*M));
			if (temp[step] == '>' || temp[step] == '<') {
				GerbangX(*M).X = x;
				GerbangX(*M).Y = y;
			}
			if (temp[step] == 'V' || temp[step] == 'v' || temp[step] == '^') {
				GerbangY(*M).X = x;
				GerbangY(*M).Y = y;
            }
            step++;
        }
    }
    Kode(*M) = Kode; // ngasih kode map
}
void LoadAllMap (MAP *M1,MAP *M2,MAP *M3,MAP *M4) {
    LoadMapFromFile(M1,1,"map1.txt");
    LoadMapFromFile(M2,2,"map2.txt");
    LoadMapFromFile(M3,3,"map3.txt");
    LoadMapFromFile(M4,4,"map4.txt");
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

void UbahMapAddWahana(PLAYER *P,MAP *Mout, POINT point_wahana) {
    // Mout = M1/2/3/4
    // ubah CMap dan RealMap jadi ada W baru nya
    int i,j;
    XYtoIJ(Absis(point_wahana),Ordinat(point_wahana),&i,&j,NBrsEff(CMap(*P)));
    Elmt(CMap(*P),i,j) = 'W';
    Elmt(RealMap(*P),i,j) = 'W';
    CGedung(*P) = 'W';
    // copy Realmap ke Mout
    CopyMAP(RealMap(*P),Mout);
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
    Kode(CMap(P)) = Kode(M); 
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
/*
int main() { // INI DITARO DI PROGRAM UTAMA
    MAP M1,M2,M3,M4;
    LoadAllMap(&M1,&M2,&M3,&M4);
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
}*/
