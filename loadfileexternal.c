#include <stdio.h>
#include <stdlib.h>
#include "loadfileexternal.h"
#include "boolean.h"

/* Membentuk data tipe MAP dari file dengan nama namafile */
/* Contoh pemakaian MAP M1 = LoadMap("map1.txt"); */
/* Ukurannya 10x20 */
MAP LoadMap(char NamaFile[]){
    FILE *fp;
    fp = fopen(NamaFile, "r");
    int baris = 1;
    MAP M;
    int Brs = 10;
    int Kol = 20;
    int GerbangXx, GerbangXy, GerbangYx, GerbangYy;
    MakeMAP(Brs, Kol, &M);
    char data[Kol+2];
    while (fgets(data, Kol+2, fp)!=NULL){
        for (int i=0; i<20; i++){
            if (data[i]=='^' || data[i]=='V'){
                GerbangXx = baris;
                GerbangXy = i+1;
            }
            if (data[i]=='<' || data[i]=='>'){
                GerbangYx = baris;
                GerbangYy = i+1;
            }
            Elmt(M, baris, i+1) = data[i];
        }
        //printf("%d %s\n", baris, data);
        baris++;
    }
    fclose(fp);
    GerbangX(M).X = GerbangXx;
    GerbangX(M).Y = GerbangXy;
    GerbangY(M).X = GerbangYx;
    GerbangY(M).Y = GerbangYy;
    return M;
}