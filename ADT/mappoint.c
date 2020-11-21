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

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
	return Absis(P)==0 && Ordinat(P)==0;
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P){
	/*KAMUS*/

	/*ALGORITMA*/
	Absis(P) = Absis(P)+1;
	return P;
}
/* Mengirim salinan P dengan absis ditambah satu */
POINT NextY (POINT P){
	/*KAMUS*/

	/*ALGORITMA*/
	Ordinat(P) = Ordinat(P) + 1;
	return P;
}
/* Mengirim salinan P dengan ordinat ditambah satu */
POINT PlusDelta (POINT P, int deltaX, int deltaY){
	/*KAMUS*/

	/*ALGORITMA*/
	Absis(P) = Absis(P) + deltaX;
	Ordinat(P) = Ordinat(P) + deltaY;
	return P;
}
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
POINT MirrorOf (POINT P, boolean SbX){
	/*KAMUS*/
	POINT hasil;
	/*ALGORITMA*/
	if (SbX){
		hasil = MakePOINT(Absis(P),(Ordinat(P)*-1));
	}
	else{
		hasil = MakePOINT((Absis(P)*-1),Ordinat(P));
	}
	return hasil;
}
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
float Jarak0 (POINT P){
	/*KAMUS*/
	double jarak;
	/*ALGORITMA*/
	jarak = sqrt((Absis(P)*Absis(P)) + (Ordinat(P)*Ordinat(P)));
	return jarak;
}
/* Menghitung jarak P ke (0,0) */
float Panjang (POINT P1, POINT P2){
	/*KAMUS*/
	double panjang;
	float deltaX, deltaY;
	/*ALGORITMA*/
	deltaX = Absis(P1)-Absis(P2);
	deltaY = Ordinat(P1)-Ordinat(P2);
	panjang = sqrt((deltaX*deltaX) + (deltaY*deltaY));
	return panjang;
}
/* Menghitung jarak antara P1 dan P2 */

void Geser (POINT *P, int deltaX, int deltaY){
	/*KAMUS*/

	/*ALGORITMA*/
	Absis(*P) = Absis(*P) + deltaX;
	Ordinat(*P) = Ordinat(*P) + deltaY;
}

void Mirror (POINT *P, boolean SbX){
	/*KAMUS*/

	/*ALGORITMA*/
	if(SbX){
		Ordinat(*P) = -1*Ordinat(*P);
	}
	else{
		Absis(*P) = -1*Absis(*P);
	}
}
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
void Putar (POINT *P, float Sudut){
	/*KAMUS*/
	int x,y;
	/*ALGORITMA*/
	x=Absis(*P);
	y=Ordinat(*P);
	Sudut = Sudut*-0.0174533;

	Absis(*P) = x*cos(Sudut) - y*sin(Sudut);
	Ordinat(*P) = x*sin(Sudut) + y*cos(Sudut);

}
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) searah jarum jam*/