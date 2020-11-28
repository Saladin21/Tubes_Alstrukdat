#include <stdio.h>
#include <stdlib.h>
#include "loadfileexternal.h"
#include "boolean.h"
#include "ADT/build.h"
#include <string.h>

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


material LoadMaterial(char NamaFile[]){
    FILE *fp;
    fp = fopen(NamaFile, "r");
    material M;
    int row = 0;
    int i = 0;
    char line[64];
    while(fgets(line,64,fp) && i<NMaterial+1){
        int col = 0;
        if(i!=0){
            char *tok;
            for(tok = strtok(line,";"); tok && *tok; col++, tok=strtok(NULL,";")){
                if(col == 1){
                    HargaM(M,row) = atoi(tok);
                } else{
                    strcpy(JenisM(M,row),tok);
                }
            }
            row++;
        }
        i++;
    }
    fclose(fp);
    return M;
}

