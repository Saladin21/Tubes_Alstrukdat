/* ********** Definisi TYPE MAP dengan indeks dan elemen integer ********** */

#ifndef MAP_H
#define MAP_H

#include "boolean.h"
#include "mappoint.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 1
#define BrsMax 100
#define KolMin 1
#define KolMax 100

typedef int indeks; /* indeks baris, kolom */
typedef char ElType; 
typedef struct { 
	ElType Mem[BrsMax+1][KolMax+1];
   int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
   POINT GerbangX; // point gerbang yg di atas/bawah
   POINT GerbangY; // gerbang di kiri/kanan
} MAP;
/* NBrsEff >= 1 dan NKolEff >= 1 */
/* Indeks MAP yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori MAP yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MAP *** */
void MakeMAP (int NB, int NK, MAP * M); 
/* Membentuk sebuah MAP "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori MAP yang dibuat */
/* F.S. MAP M sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]
#define GerbangX(M) (M).GerbangX
#define GerbangY(M) (M).GerbangY

/* *** Selektor "DUNIA MAP" *** */
boolean IsIdxValid (int i, int j);
/* Mengirimkan true jika i, j adalah indeks yang valid untuk MAP apa pun */

/* *** Selektor: Untuk sebuah MAP M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MAP M);
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (MAP M);
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (MAP M);
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (MAP M);
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEff (MAP M, indeks i, indeks j);
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
ElType GetElmtDiagonal (MAP M, indeks i);
/* Mengirimkan elemen M(i,i) */

/* ********** Assignment  MAP ********** */
void CopyMAP (MAP MIn, MAP * MHsl);
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMAP (MAP * M, int NB, int NK);
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMAP(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi MAP :
1 2 3
4 5 6
8 9 10 
*/
void TulisMAP (MAP M);
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis MAP 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MAP ********** */
boolean EQ (MAP M1, MAP M2);
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
boolean NEQ (MAP M1, MAP M2);
/* Mengirimkan true jika M1 tidak sama dengan M2 */
boolean EQSize (MAP M1, MAP M2);
/* Mengirimkan true jika ukuran efektif MAP M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */

/* ********** Operasi lain ********** */
int NBElmt (MAP M);
/* Mengirimkan banyaknya elemen M */

void Transpose (MAP * M);
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */

int CountXBrs (MAP M, indeks i, ElType X);
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
int CountXKol (MAP M, indeks j, ElType X);
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */

#endif