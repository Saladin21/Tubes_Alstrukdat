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

ElType GetElmtDiagonal (MAP M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return Elmt(M, i, i);
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
	int i, j;
	ElType nilai;
	/*ALGORITMA*/
	MakeMAP(NB, NK, M);
	for (i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++){
		for(j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
			scanf(" %c", &nilai);
			Elmt(*M, i, j) = nilai;
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
	if ((GetFirstIdxBrs(M1) != GetFirstIdxBrs(M2)) || (GetLastIdxKol(M1) != GetLastIdxKol(M2)) || (NBElmt(M1) != NBElmt(M2))){
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

boolean NEQ (MAP M1, MAP M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return !EQ(M1, M2);
}	

boolean EQSize (MAP M1, MAP M2)
/* Mengirimkan true jika ukuran efektif MAP M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return (NBrsEff(M1) == NBrsEff (M2)) && (NKolEff (M1) == NKolEff (M2));
}

/* ********** Operasi lain ********** */
int NBElmt (MAP M)
/* Mengirimkan banyaknya elemen M */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return NBrsEff(M) * NKolEff(M);
}


void Transpose (MAP * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
	/*KAMUS LOKAL*/
	ElType temp;
	indeks i,j;
	/*ALGORITMA*/
	for (i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++){
		for(j=GetFirstIdxKol(*M);j<i;j++){
			temp = Elmt(*M, i, j);
			Elmt(*M, i, j) = Elmt(*M, j, i);
			Elmt(*M, j, i) = temp;
		}
	}		
}

int CountXBrs (MAP M, indeks i, ElType X)
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
{
	/*KAMUS LOKAL*/
	indeks j;
	int count;
	/*ALGORITMA*/
	count=0;
	for (j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
		if (Elmt(M,i,j)==X){
			count++;
		}
	}
	return count;
	
}
int CountXKol (MAP M, indeks j, ElType X)
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
{
	/*KAMUS LOKAL*/
	indeks i;
	int count;
	/*ALGORITMA*/
	count=0;
	for (i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
		if (Elmt(M,i,j)==X){
			count++;
		}
	}
	return count;
	
}