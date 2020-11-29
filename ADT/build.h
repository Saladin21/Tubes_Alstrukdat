/* File build.h
   Berisi ADT yang dibutuhkan untuk BUY, BUILD, dan UPGRADE */
   
#ifndef BUILD_H
#define BUILD_H
#define NMaterial 2  // Jumlah material yang ada dalam game
#define NWahana 9 // Jumlah wahana yang ada dalam game
#include "boolean.h"
#include "../mapplayer.h"
#include <string.h>
#include "../listupgrade.h"


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


// WAHANA.h
#define Nil NULL

//Struct untuk wahana yang sudah dibangun
typedef struct{
    char IDawal[4]; //ID menggambarkan nama wahana
    int ID; //ID unik untuk setiap wahana yang udah dibangun
    int NbPengunjung;
    int status; //-1 : rusak, 1 : operasional
    int dayride;
    int liferide;
    int map; //wahana ada di map 1,2,3, atau 4
    POINT lokasi;
    ListUpgrade upgrade;
    
    
} Wahana;
// info lain seperti harga, durasi dll ambil dari infowahana pake IDawal (nanti dibikin fungsinya).

typedef struct tElmtlist *address;
typedef struct tElmtlist { 
	Wahana info;
	address next;
} ElmtList;
typedef struct {
	address FirstWahana;
} AllWahana;

#define InfoWahana(P) (P)->info
#define NextWahana(P) (P)->next
#define FirstWahana(L) ((L).FirstWahana)

/*****************/
/* FUNGSI BUILD */
/***************/
void PrintDaftarBuild(daftarwahana W, material M);
// Mencetak daftar wahana yang bisa di-build beserta cost-nyaboolean IsWahanaFull (Wahana W, daftarwahana W2)

boolean IsWahanaAwal(char *s, daftarwahana W);
// Mengembalikan true jika a adalah nama wahana yang bukan hasil upgrade



/*******************/
/* FUNGSI UPGRADE */
/*****************/
void PrintWahanaSekitar(PLAYER P,daftarwahana W, AllWahana L);
// Mencetak daftar wahana yang ada di kiri, atas, kanan, bawah Player P

boolean IsWahanaNear(int ID, PLAYER P, AllWahana L);
// Mengembalikan true jika wahana ID ada di sebelah P



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

int CostMat(char IDAwal[], daftarwahana W, int j);
// Mengembalikan cost material j wahana dengan ID IDAwal

int IdxWahana(char IDAwal[], daftarwahana W);
// Mengembalikan index wahana dengan ID IDAwal




// WAHANA.h
/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

Wahana MakeWahana (char IDawal[], int ID, POINT lokasi, int map);
//Menghasilkan suatu wahana

void AddWahana(char IDAwal[], POINT lokasi, int map, AllWahana *L, PLAYER *Player);
//Membuat wahana baru dengan tipe IDAwal pada lokasi,
//Langsung dimasukkan ke dalam AllWahana
/*
    ID : ID terkecil yang belum ada dalam AllWahana
    NbPengunjung : 0
    status : 1
    dayride : 0
    liferide 0
*/

void RemoveLastWahana(AllWahana *L, PLAYER P);
//Menghapus Wahana terakhir dari Allwahana dan menghapus dari map

boolean IsWahanaFull (Wahana W);
//Mengecek apakah kapasitas suatu wahana sudah penuh

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (AllWahana L);
/* Mengirim true jika  kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyWahana (AllWahana *L);
/* I.S. sembarang             */
/* F.S. Terbentuk AllWahana kosong */

/****************** Manajemen Memori ******************/
address AlokWahana (Wahana X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokWahana (address P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address SearchWahana (AllWahana L, int ID);
/* Mencari apakah ada elemen list dengan ID */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
boolean FSearchWahana (AllWahana L, int ID);
/* Mencari apakah ada elemen list dengan ID */
/* Mengirimkan true jika ada, false jika tidak ada */
address SearchWahanaKosong (AllWahana L, char IDAwal[]);
//Mengembalikan address wahana dengan IDAwal yang pertama tidak penuh
//Jika tidak ada mengembalikan nil


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (AllWahana *L, Wahana X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (AllWahana *L, Wahana X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (AllWahana *L, Wahana *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (AllWahana *L, Wahana *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (AllWahana *L, address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (AllWahana *L, address P, address Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (AllWahana *L, address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (AllWahana *L, address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (AllWahana *L, int ID);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (AllWahana *L, address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (AllWahana *L, address *Pdel, address Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintAllWahana (AllWahana L);
// Menampilkan Id dan nama wahana

void PrintInfo (Wahana W);
//Menamppilkan detail wahana

int NbElmtWahana (AllWahana L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */




#endif
