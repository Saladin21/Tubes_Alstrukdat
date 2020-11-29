#include<stdio.h>
#include "jam.h"

/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid (int H, int M){
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
	return H>=0 && H<=23 && M>=0 && M<=59;
}

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM){
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
	/*KAMUS LOKAL*/
	JAM j;
	/*Algoritma*/
	Hour(j) = HH;
	Minute(j) = MM;

	return j;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J){
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh:
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */
	/*KAMUS LOKAL*/
	int h, m, s;

	/*Algoritma*/
	scanf("%d %d", &h, &m);
	while(IsJAMValid(h, m)==false){
		printf("Jam tidak valid\n");
		scanf("%d %d", &h, &m);
	}

	*J = MakeJAM(h,m);

}

void TulisJAM (JAM J){
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH.MM */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH.MM
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.. */
	/*KAMUS LOKAL*/

	/*Algoritma*/
    if(Hour(J)==0)
    {
        printf("00.");
    }
    else if(Hour(J)<10)
    {
        printf("0%d.",Hour(J));
    }
    else
    {
        printf("%d.",Hour(J));
    }
    
    if(Minute(J)==0)
    {
        printf("00");
    }
    else if(Minute(J)<10)
    {
        printf("0%d",Minute(J));
    }
    else
    {
        printf("%d",Minute(J));
    }
}
/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToMenit(JAM J){
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah menit dari pukul 00.00 */
/* Rumus : menit = 60*HH + MM */
/* Nilai maksimum = 60*23+59 */
	/*KAMUS LOKAL*/

	/*Algoritma*/
	return 60*Hour(J) + Minute(J);

}

JAM MenitToJAM (long N){
/* Mengirim  konversi menit ke JAM */
/* Catatan: Jika N >= 1440, maka harus dikonversi dulu menjadi jumlah menit yang
   mewakili jumlah menit yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 1440, baru N1 dikonversi menjadi JAM */
	/*KAMUS LOKAL*/
	int h,m;
	/*Algoritma*/
	N = N % 1440;
	h = N / 60;
	m = (N % 60);

	return MakeJAM(h,m);
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2){
/* Mengirimkan true jika J1=J2, false jika tidak */
	return Hour(J1)==Hour(J2) && Minute(J1)==Minute(J2);
}
boolean JNEQ (JAM J1, JAM J2){
/* Mengirimkan true jika J1 tidak sama dengan J2 */
	return JEQ(J1, J2) == false;
}
boolean JLT (JAM J1, JAM J2){
/* Mengirimkan true jika J1<J2, false jika tidak */
	return JAMToMenit(J1)<JAMToMenit(J2);
}
boolean JGT (JAM J1, JAM J2){
/* Mengirimkan true jika J1>J2, false jika tidak */
	return JAMToMenit(J1)>JAMToMenit(J2);
}

/* *** Operator aritmatika JAM *** */
JAM NextMenit (JAM J){
/* Mengirim 1 menit setelah J dalam bentuk JAM */
	/*KAMUS LOKAL*/
	long menit;
	/*ALGORITMA*/
	menit = JAMToMenit(J);
	menit = menit + 1;
	return MenitToJAM(menit);
}
JAM NextNMenit (JAM J, int N){
/* Mengirim N menit setelah J dalam bentuk JAM */
	/*KAMUS LOKAL*/
	long menit;
	/*ALGORITMA*/
	menit = JAMToMenit(J);
	menit = menit + N;
	return MenitToJAM(menit);

}
JAM PrevMenit (JAM J){
/* Mengirim 1 menit sebelum J dalam bentuk JAM */
	/*KAMUS LOKAL*/
	long menit;
	/*ALGORITMA*/
	menit = JAMToMenit(J);
	menit = menit - 1;
	while(menit<0){
		menit = menit + 1440;
	}
	return MenitToJAM(menit);
}
JAM PrevNMenit (JAM J, int N){
/* Mengirim N menit sebelum J dalam bentuk JAM */
	/*KAMUS LOKAL*/
	long menit;
	/*ALGORITMA*/
	menit = JAMToMenit(J);
	menit = menit - N;
	while(menit<0){
		menit = menit + 1440;
	}
	return MenitToJAM(menit);
}

/* *** Kelompok Operator Aritmetika *** */
long Durasi (JAM JAw, JAM JAkh){
/* Mengirim JAkh-JAw dlm Menit, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
	/*KAMUS LOKAL*/
	long hasil;
	/*ALGORITMA*/
	if(JGT(JAw, JAkh)){
		hasil = JAMToMenit(JAkh) - JAMToMenit(JAw) + 1440;
	}
	else{
		hasil = JAMToMenit(JAkh) - JAMToMenit(JAw);
	}
	return hasil;
}