#ifndef WAHANA_H
#define WAHANA_H
#include "ADT/mappoint.h"
#include "ADT/boolean.h"
#include "ADT/build.h"

//Struct untuk wahana yang sudah dibangun
typedef struct{
    char IDawal[3]; //ID menggambarkan nama wahana
    int ID; //ID unik untuk setiap wahana yang udah dibangun
    int NbPengunjung;
    int status; //-1 : rusak, 1 : operasional
    int dayride;
    int liferide;
    POINT lokasi;
    
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

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */


#define InfoWahana(P) (P)->info
#define NextWahana(P) (P)->next
#define FirstWahana(L) ((L).FirstWahana)
#define Nil NULL;

int Kapasitas(char IDawal[]);
//Mengembalikan kapasitas wahanan dengan IDawal
int Harga(char IDawal[]);
//Mengembalikan harga wahanan dengan IDawal
int Durasi(char IDawal[]);
//Mengembalikan durasi wahanan dengan IDawal



Wahana MakeWahana (char IDawal[], int ID, int NbPengunjung, int status, int dayride, int liferide, POINT lokasi);
//Menghasilkan suatu wahana

void AddWahana(char IDAwal[], POINT lokasi, AllWahana *L);
//Membuat wahana baru dengan tipe IDAwal pada lokasi,
//Langsung dimasukkan ke dalam AllWahana
/*
    ID : ID terkecil yang belum ada dalam AllWahana
    NbPengunjung : 0
    status : 1
    dayride : 0
    liferide 0
*/

boolean IsWahanaFull (Wahana W);
//Mengecek apakah kapasitas suatu wahana sudah penuh

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (AllWahana L);
/* Mengirim true jika  kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (AllWahana *L);
/* I.S. sembarang             */
/* F.S. Terbentuk AllWahana kosong */

/****************** Manajemen Memori ******************/
address AlokWahana (Wahana X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokWahana (address *P);
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
void InsertFirst (AllWahana *L, Wahana P);
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
void DelP (AllWahana *L, Wahana X);
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
void PrintInfo (AllWahana L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmtWahana (AllWahana L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

#endif