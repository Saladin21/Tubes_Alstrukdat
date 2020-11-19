#ifndef WAHANA_H
#define WAHANA_H

typedef struct{
    int ID;
    char Nama[100];
    int Harga;
    int Kapasitas;
    int NbPengunjung;
    int Durasi;
    int status; //-1 : rusak, 0 : belum dibangun, 1 : operasional
    char Deskripsi[100];
} Wahana;


#endif