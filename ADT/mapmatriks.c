/*NIM / Nama : 13519187 / Ahmad Saladin*/
/*Tanggal : 24 September 2020*/
/*Topik Praktikum : ADT MAP*/
/*Deskripsi : Realisasi ADT MAP*/

#include <stdio.h>
#include "mapmatriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MAP *** */
void MakeMAP (int NB, int NK, MAP * M) 
/* Membentuk sebuah MAP "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori MAP yang dibuat */
/* F.S. MAP M sesuai dengan definisi di atas terbentuk */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
	GerbangX(*M).X = -1;
	GerbangX(*M).Y = -1;
	GerbangY(*M).X = -2;
	GerbangY(*M).Y = -2;
	Kode(*M) = -1;
}


/* *** Selektor "DUNIA MAP" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk MAP apa pun */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return (i>=BrsMin) && (i<= BrsMax) && (j>= KolMin) && (j<=KolMax);
}

/* *** Selektor: Untuk sebuah MAP M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MAP M)
/* Mengirimkan indeks baris terkecil M */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return BrsMin;	
}

indeks GetFirstIdxKol (MAP M)
/* Mengirimkan indeks kolom terkecil M */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return KolMin;
}

indeks GetLastIdxBrs (MAP M)
/* Mengirimkan indeks baris terbesar M */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return NBrsEff(M) - 1 + GetFirstIdxBrs(M);
}

indeks GetLastIdxKol (MAP M)
/* Mengirimkan indeks kolom terbesar M */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return NKolEff(M) - 1 + GetFirstIdxKol(M);
}

boolean IsIdxEff (MAP M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return (i>=GetFirstIdxBrs(M)) && (i<=GetLastIdxBrs(M)) && (j>=GetFirstIdxKol(M)) && (j<=GetLastIdxKol(M));
}

/* ********** Assignment  MAP ********** */
void CopyMAP (MAP MIn, MAP * MHsl)
/* Melakukan assignment MHsl  MIn */
{
	/*KAMUS LOKAL*/
	indeks i, j;
	/*ALGORITMA*/
	for (i=GetFirstIdxBrs(MIn);i<=GetLastIdxBrs(MIn);i++){
		for (j=GetFirstIdxKol(MIn);j<=GetLastIdxKol(MIn);j++)
		{
			Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
		}
	}
	NBrsEff(*MHsl) = NBrsEff(MIn);
	NKolEff(*MHsl) = NKolEff(MIn);
}

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMAP (MAP * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMAP(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi MAP :
1 2 3
4 5 6
8 9 10 
*/
{
	/*KAMUS LOKAL*/
	int i, j; int x,y;
	ElType nilai;
	/*ALGORITMA*/
	MakeMAP(NB, NK, M);
	for (i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++){
		for(j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
			scanf(" %c", &nilai);
			Elmt(*M, i, j) = nilai;

			// Assign Point gerbang
			IJtoXY(&x,&y,i,j,GetLastIdxBrs(*M));
			if (nilai == '>' || nilai == '<') {
				GerbangX(*M).X = x;
				GerbangX(*M).Y = y;
			}
			if (nilai == 'V' || nilai == 'v' || nilai == '^') {
				GerbangY(*M).X = x;
				GerbangY(*M).Y = y;
			}
		}
	}
}

void TulisMAP (MAP M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis MAP 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
	/*KAMUS LOKAL*/

    indeks i,j;

    //algoritma
    for (i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M); i++){
        for (j=GetFirstIdxKol(M); j<=GetLastIdxKol(M); j++){
            printf("%c ",Elmt(M,i,j));
        }
        if (i != GetLastIdxBrs(M)){
          printf("\n");
        }
    }
	printf("\n");
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MAP ********** */
boolean EQ (MAP M1, MAP M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
	/*KAMUS LOKAL*/
	boolean equal;
	indeks i, j;
	/*ALGORITMA*/
	equal = true;
	if ((GetFirstIdxBrs(M1) != GetFirstIdxBrs(M2)) || (GetLastIdxKol(M1) != GetLastIdxKol(M2)) || (NbElmtMatriks(M1) != NbElmtMatriks(M2))){
		equal = false;
	}
	else{
		i = GetFirstIdxBrs(M1);
		while (equal && i<=GetLastIdxBrs(M1)){
			j = GetFirstIdxKol(M1);
			while (equal && j<=GetLastIdxKol(M1)){
				if (Elmt(M1, i,j) != Elmt(M2, i, j)){
					equal = false;
				}
				else{
					j++;
				}
			}
			if(equal){
				i++;
			}
		}
	}
	return equal;
}

boolean NbElmtMatriks (MAP M){
	return NBrsEff(M) * NKolEff(M);

}