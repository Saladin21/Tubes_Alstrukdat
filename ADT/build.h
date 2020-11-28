/* File build.h
   Berisi ADT yang dibutuhkan untuk BUY, BUILD, dan UPGRADE */
   
#ifndef BUILD_H
#define BUILD_H
#define NMaterial 2  // Jumlah material yang ada dalam game
#define NWahana 9 // Jumlah wahana yang ada dalam game
#include "boolean.h"
#include <string.h>

typedef struct
{
    char jenis[20];     // Nama material, contoh: kayu, besi, dll.
    int harga;          // Harga material per buah
    int jumlah;         // Jumlah yang dimiliki saat ini
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

typedef struct
{
    infowahana T[NWahana];    // Tabel penyimpan semua info material
} daftarwahana;

#define IDw(W,n) (W).T[n].IDawal
#define NamaW(W,n) (W).T[n].namawahana
#define AsalW(W,n) (W).T[n].asalwahana
#define KapasitasW(W,n) (W).T[n].kapasitas
#define MoneyreqW(W,n) (W).T[n].moneyreq
#define MaterialW(W,n,m) (W).T[n].matreq[m] //m=0 Kayu, m=1 Besi
#define DurasiBW(W,n) (W).T[n].durasibuild
#define DurasiNW(W,n) (W).T[n].durasinaik
#define HargaW(W,n) (W).T[n].hargatiket
#define DeskripsiW(W,n) (W).T[n].deskripsi

#define JenisM(M,n) (M).T[n].jenis
#define HargaM(M,n) (M).T[n].harga


/*****************/
/* FUNGSI BUILD */
/***************/
void PrintDaftarBuild(daftarwahana W, material M);
// Mencetak daftar wahana yang bisa di-build beserta cost-nya

boolean IsWahanaAwal(char *s, daftarwahana W);
// Mengembalikan true jika a adalah nama wahana yang bukan hasil upgrade

/********************/
/* FUNGSI MATERIAL */
/******************/
void PrintDaftarMaterial(material M);
// Mencetak daftar material beserta harganya, untuk fungsi BUY

boolean IsMaterial(char* s, material M);
// Mengembalikan true jika s merupakan salah satu material yang ada

int IdxMaterial(char* s, material M);
// Mengembalikan index material s. Asumsi s ada.

boolean IsStringSame(char a[], char b[]);
// Mengembalikan true jika 2 string a b sama

/***********************************/
/* FUNGSI PENGAMBILAN DATA WAHANA */
/*********************************/
void NamaWahana(char IDAwal[], daftarwahana W);
// Mencetak nama wahana dengan ID IDAwal

void DeskripsiWahana(char IDAwal[], daftarwahana W);
// Mencetak deskripsi wahana dengan ID IDAwal

int KapasitasWahana(char IDAwal[], daftarwahana W);
// Mengembalikan kapasistas wahana dengan ID IDAwal;

int DurasiNaik(char IDAwal[], daftarwahana W);
// Mengembalikan durasi naik wahana dengan ID IDAwal dalam menit

int DurasiBuild(char IDAwal[], daftarwahana W);
// Mengembalikan durasi build wahana dengan ID IDAwal dalam menit

int HargaTiket(char IDAwal[], daftarwahana W);
// Mengembalikan harga tiket wahana dengan ID IDAwal

int HargaBuild(char IDAwal[], daftarwahana W);
// Mengembalikan harga build wahana dengan ID IDAwal

int IdxWahana(char IDAwal[], daftarwahana W);
// Mengembalikan index wahana dengan ID IDAwal

#endif
