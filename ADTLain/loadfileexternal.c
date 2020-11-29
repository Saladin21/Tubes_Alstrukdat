#include <stdio.h>
#include <stdlib.h>
#include "loadfileexternal.h"
#include "boolean.h"
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
    while(fgets(line,64,fp)!=NULL && i<NMaterial+1){
        int col = 0;
        if(i!=0){
            //char *tok;
            for(char *tok = strtok(line,";"); tok!=NULL; tok = strtok(NULL, ";")){
                if(col == 1){
                    HargaM(M,row) = atoi(tok);
                } else{
                    strcpy(JenisM(M,row),tok);
                }
                col++;
            }
            row++;
        }
        i++;
    }
    fclose(fp);
    return M;
}

daftarwahana LoadWahana(char NamaFile[]){
    FILE *fp;
    fp = fopen(NamaFile, "r");
    daftarwahana W;
    int row = 0;
    int i = 0;
    char line[255];
    while(fgets(line,255,fp)!=NULL && i<NWahana+1){
        int col = 1;
        if(i!=0){
            char *tok;
            tok = strtok(line,";");
            while(tok!=NULL){
                if(col == 1){
                    strcpy(IDw(W, row), tok);
                } else if (col==2){
                    strcpy(NamaW(W, row), tok);
                } else if(col==3){
                    strcpy(AsalW(W, row), tok);
                } else if(col==4){
                    KapasitasW(W, row) = atoi(tok);
                } else if(col==5){
                    MoneyreqW(W, row) = atoi(tok);
                } else if(col==6){
                    MaterialW(W, row, 0) = atoi(tok);
                } else if(col==7){
                    MaterialW(W, row, 1) = atoi(tok);
                } else if(col==8){
                    DurasiBW(W, row) = atoi(tok);
                } else if(col==9){
                    DurasiNW(W, row) = atoi(tok);
                } else if(col==10){
                    HargaW(W, row) = atoi(tok);
                } else{
                    strcpy(DeskripsiW(W,row),tok);
                }
                col++;
                tok = strtok(NULL, ";");
            }
            row++;
        }
        i++;
    }
    fclose(fp);
    return W;
}