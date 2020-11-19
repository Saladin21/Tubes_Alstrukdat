#ifndef PROSES_H
#define PROSES_H

#include "ADT/prioqueue.h"
#include "wahana.h"
#include <stdlib.h>

typedef struct 
{
    infotype pengunjung;
    int durasi;
} proses;

typedef struct 
{
    proses Tab[100];
    int NbElmt;
}TabProses;

proses MakeProses(infotype p, int durasi);
//Menghasilkan sebuah proses

void MakeTabProses(TabProses *T);
//Membuat TabProses Kosong

void insert(TabProses *T, proses P);
//Menambahkan proses ke tabel

void Proses(TabProses *T, int durasi);
//Memproses isi TabProses Selama durasi

void DelAt(TabProses *T, int i, infotype *P);
//Menghapus elemen dengan indeks i dan bagian infotypenya disimpan di p

void Sort(TabProses *T);

#endif
