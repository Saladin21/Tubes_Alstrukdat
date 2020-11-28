/*Nama/NIM : Ahmad Saladin/13519187*/
/*Tanggal : 1 September 2020*/


#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "mappoint.h"

/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y){
	/*KAMUS*/
	POINT P;
	/*ALGORITMA*/
	Absis(P) = X;
	Ordinat(P) = Y;
	return P;
}
/* Membentuk sebuah POINT dari komponen-komponennya */
void XYtoIJ (int X, int Y, int *i, int *j, int lenBrsM) {
// merubah xy jadi ij

    *i = lenBrsM - Y + 1;
    *j = X;
}

void IJtoXY (int *X, int *Y, int i, int j, int lenBrsM) {
// merubah ij jadi xy

    *Y = lenBrsM - i + 1;
    *X = j;
}
/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P){
	/*KAMUS*/
	int x;
	int y;
	/*ALGORITMA*/
	scanf("%d %d", &x, &y);
	*P = MakePOINT(x, y);
}
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void TulisPOINT (POINT P){
	printf("%d,%d", Absis(P), Ordinat(P));
}
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */

/* *** Kelompok operasi relasional terhadap POINT *** */
// boolean EQ (POINT P1, POINT P2){
// 	return Absis(P1)==Absis(P2) && Ordinat(P1)==Ordinat(P2);
// }
// /* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
// boolean NEQ (POINT P1, POINT P2){
// 	return !EQ(P1, P2);
// }
/* Mengirimkan true jika P1 tidak sama dengan P2 */