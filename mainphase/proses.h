#ifndef PROSES_H
#define PROSES_H

#include "antrian.h"
#include <stdlib.h>
#include<stdio.h>

typedef struct 
{
    pengunjung pengunjung;
    int durasi;
} proses;

typedef struct 
{
    proses Tab[100];
    int NbElmt;
}TabProses;

proses MakeProses(pengunjung p, int durasi);
//Menghasilkan sebuah proses

void MakeTabProses(TabProses *T);
//Membuat TabProses Kosong

void insert(TabProses *T, proses P);
//Menambahkan proses ke tabel

void Proses(TabProses *T, int durasi);
//Memproses isi TabProses Selama durasi

void DelAt(TabProses *T, int i, pengunjung *P);
//Menghapus elemen dengan indeks i dan bagian infotypenya disimpan di p

void SortProses(TabProses *T);
//Mengurutkan tabel dari durasi terkecil hingga terbesar

void PrintDurasiProses(TabProses T);
//Mencetak durasi setiap proses

#endif
