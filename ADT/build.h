/* File build.h
   Berisi ADT yang dibutuhkan untuk BUY, BUILD, dan UPGRADE */
   
#ifndef BUILD_H
#define BUILD_H
#define NMaterial 2  // Jumlah material yang ada dalam game
#include "boolean.h"
#include <string.h>

typedef struct
{
    char jenis[20];     // Nama material, contoh: kayu, besi, dll.
    int harga;          // Harga material per buah
} infomaterial;         // Struct yang menyimpan info material

typedef struct
{
    infomaterial T[NMaterial];    // Tabel penyimpan semua info material
} material;

typedef struct
{
    char IDawal[4];         // Awalan ID wahana yang melambangkan jenis/nama wahana
    char namawahana[50];    // Nama dari wahana
    char asalwahana[50];    // Asal wahana sebelum upgrade, jika bukan hasil upgrade maka "None"
    int kapasitas;          // Maks. orang yang naik di wahana dalam satu waktu
    int moneyreq;           // Uang yang dibutuhkan untuk membangun wahana
    int matreq[NMaterial];  // Jumlah material yang dibutuhkan untuk membangun wahana
    int durasibuild;        // Waktu yang dibutuhkan untuk build wahana
    int durasinaik;         // Waktu yang dibutuhkan pelanggan untuk menaiki wahana
    int hargatiket;         // Pendapatan wahana per orang per sekali naik
    char deskripsi[100];    // Keterangan dari wahana
} infowahana;               // Struct berisi data dari pembacaan file wahana.txt
                            // Untuk menyimpan banyak wahana cukup dibuat array infowahana
                            // Tidak ada ID, karena hanya sebagai data semua wahana yang tersedia
                
#define JenisM(M,n) (M).T[n].jenis
#define HargaM(M,n) (M).T[n].harga

void PrintDaftarMaterial(material M);
// Mencetak daftar material beserta harganya, untuk fungsi BUY

boolean IsMaterial(char* s, material M);
// Mengembalikan true jika s merupakan salah satu material yang ada

int IdxMaterial(char* s, material M);
// Mengembalikan index material s. Asumsi s ada.

boolean IsStringSame(char a[], char b[]);


/***********************************/
/* FUNGSI PENGAMBILAN DATA WAHANA */
/*********************************/
void NamaWahana(char IDAwal[], infowahana W[]);
// Mencetak nama wahana dengan ID IDAwal

void DeskripsiWahana(char IDAwal[], infowahana W[]);
// Mencetak deskripsi wahana dengan ID IDAwal

int KapasitasWahana(char IDAwal[], infowahana W[]);
// Mengembalikan kapasistas wahana dengan ID IDAwal;

int DurasiNaik(char IDAwal[], infowahana W[]);
// Mengembalikan durasi naik wahana dengan ID IDAwal dalam menit

int DurasiBuild(char IDAwal[], infowahana W[]);
// Mengembalikan durasi build wahana dengan ID IDAwal dalam menit

int HargaTiket(char IDAwal[], infowahana W[]);
// Mengembalikan harga tiket wahana dengan ID IDAwal
#endif
