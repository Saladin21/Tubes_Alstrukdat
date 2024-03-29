#ifndef MAINPHASE_H
#define MAINPHASE_H

#include "../ADTLain/boolean.h"
#include "../Jam/jam.h"
#include "../Queue/antrian.h"
#include "../ADTLain/proses.h"
#include "../ADTLain/build.h"
#include<time.h>


void Serve (Antrian *A, AllWahana *L, JAM *T, int *money, TabProses *Tab);
//I.S. Pemain berada di sebelah antrian
//F.S. Pengunjung pertama dalam antrian dilayani sesuai input wahana jika
//wahana tersebut ada di daftar milik pengunjung dan tidak penuh, waktu dan uang akan bertambah

void repair (POINT Player, int map, JAM *J, TabProses *Tab, Antrian *A, AllWahana *L);
//I.S. pemain berada di sebelah wahana
//F.S. wahana rusak yang berada di sebelah posisi pemain diperbaiki dan waktu bertambah

void Detail (Wahana W);
//I.S. pemain berada di sebelah wahana
//F.S. Menampilkan detail dari wahana yang berada di sebelah pemain

void Office(AllWahana L);
//I.S. Pemain berada di sebelah office
//Menampilkan tampilan office

void Prepare(Antrian *A, TabProses *Tab, AllWahana *L);
//I.S. Sembarang
//F.S. Antrian kosong dan masuk ke preparation phase

void AdvTime (JAM *J, int durasi, TabProses *Tab, Antrian *A, AllWahana *L);
//Memajukan jam sebanyak durasi detik, memproses pengunjung yang berada dalam proses,
//mengembalikan pengunjung yang sudah selesai di proses ke antrian

int randomGenerator(int lower, int upper);
//Menghasilkan integer random X, lower <= X <= upper

void PrintStatus(JAM J, JAM Tutup, int money, Antrian A);
//Menampilkan status saat main phase



#endif