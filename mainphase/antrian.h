/* File : Antrian.h */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut tidak mengecil berdasarkan elemen prio */

#ifndef Antrian_H
#define Antrian_H

#include "../ADT/boolean.h"
//#include "../ADT/arraypos.h"
#include "../ADT/build.h"


#define Nil -1
/* Konstanta untuk mendefinisikan address tak terdefinisi */
typedef struct {
    char TabID[3][4];
    int Nb;
} Lwahana;

int SearchLwahana(char IDawal[], Lwahana L);
//Menghasilkan index IDawal jika ada, jika tidak ada -1

void DelLwahana(Lwahana *L, int index);
//Menghapus elemen dengan indeks index

/* Definisi elemen dan address */
typedef struct {
    int prio;  /* [1..100], prioritas dengan nilai 1..100 (1 adalah prioritas tertinggi) */
    Lwahana info;  //Tabel berisi ID wahana yang ingin dinaiki
    int kesabaran;
    int current; //berisi ID wahana yang sedang dinaiki, atau -1 jika berada dalam antrian
} pengunjung; //Pengunjung

/* Contoh deklarasi variabel bertype Antrian : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct {
    pengunjung * T;   /* tabel penyimpan elemen */
    int HEAD;  /* alamat penghapusan */
    int TAIL;  /* alamat penambahan */
    int MaxEl;     /* Max elemen queue */
} Antrian;
/* Definisi Antrian kosong: HEAD=Nil; TAIL=Nil. */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah pengunjung dan Q adalah Antrian, maka akses elemen : */
#define Prio(e)     (e).prio
#define Info(e)     (e).info
#define Head(Q)     (Q).HEAD
#define Tail(Q)     (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q)    (Q).MaxEl
#define Elmt(Q,i)   (Q).T[(i)]

/* ********* Prototype ********* */
boolean IsAntrianEmpty (Antrian Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsAntrianFull (Antrian Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmtAntrian (Antrian Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
pengunjung MakePengunjung(int prio, Lwahana info, int kesabaran, int current);

void MakeEmptyAntrian (Antrian * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(Antrian * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue (Antrian * Q, pengunjung X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Dequeue (Antrian * Q, pengunjung * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintAntrian (Antrian Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/

void ReduceKesabaran(Antrian *Q, int X);
//Mengurangi kesabaran setiap pengunjung dalam antrian sebesar X

#endif
