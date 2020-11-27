#include<stdio.h>
#include "arraypos.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
{
	/*KAMUS LOKAL*/
	IdxType i;
	/*ALGORITMA*/
	for(i = IdxMin ; i <= IdxMax ; i++){
		ElmtTab(*T, i) = ValUndef;
	}

}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtTab (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
	/*KAMUS LOKAL*/
	IdxType i;
	/*ALGORITMA*/
	i = IdxMin;
	while(ElmtTab(T, i) != ValUndef && i<=IdxMax){
		i++;
	}
	return i-IdxMin;
}
/* *** Daya tampung container *** */
int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return (IdxMax-IdxMin+1);
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
	/*KAMUS LOKAL*/
	IdxType i;
	/*ALGORITMA*/
	i = IdxMin;
	return i;
	
}
IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return NbElmtTab(T)+IdxMin-1;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return (i>=IdxMin && i<=IdxMax);
}
boolean IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return (i >= GetFirstIdx(T)) && (i<= GetLastIdx(T));
	
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return ElmtTab(T, IdxMin) == ValUndef;
	
}
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return ElmtTab(T, IdxMax) != ValUndef;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
	/*KAMUS LOKAL*/
	int n, i, ElmtTab;
	/*ALGORITMA*/
	do{
		scanf("%d", &n);
	}while(n<0 || n > MaxNbEl(*T));

	MakeEmpty(T);
	for(i=0;i<n;i++){
		scanf("%d", &ElmtTab);
		ElmtTab(*T, i) = ElmtTab;
	}
}
void TulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
	/*KAMUS LOKAL*/
	int i;
	/*ALGORITMA*/
	if(IsEmpty(T)){
		printf("[]");
	}
	else{
		printf("[");
		for(i=GetFirstIdx(T); i<GetLastIdx(T); i++){
			printf("%d,", ElmtTab(T,i));
		}
		printf("%d", ElmtTab(T,i));
		printf("]");
	}
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab (TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
	/*KAMUS LOKAL*/
	TabInt T;
	IdxType i;
	/*ALGORITMA*/
	if(IsEmpty(T2)){
		return T1;
	}
	else if(IsEmpty(T1)){
		return T2;
	}
	else{
		MakeEmpty(&T);
			if(plus){
				for(i=GetFirstIdx(T1);i<=GetLastIdx(T1);i++){
					ElmtTab(T,i) = ElmtTab(T1,i) + ElmtTab(T2,i);
				}
			}
			else{
				for(i=GetFirstIdx(T1);i<=GetLastIdx(T1);i++){
					ElmtTab(T,i) = ElmtTab(T1,i) - ElmtTab(T2,i);
				}
			}
		return T;;
	}
	
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
	/*KAMUS LOKAL*/
	boolean equal;
	int i;
	/*ALGORITMA*/
	equal = false;
	if(IsEmpty(T1)){
		equal = IsEmpty(T2);
	}
	else if(GetLastIdx(T1) == GetLastIdx(T2)){
		equal = true;
		i = GetFirstIdx(T1);
		while(equal && (i <= GetLastIdx(T1))){
			if(ElmtTab(T1, i) != ElmtTab(T2,i)){
				equal =false;
			}
			else{
				i++;
			}
		}
	}
	return equal;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
	/*KAMUS LOKAL*/
	boolean found;
	IdxType i;
	/*ALGORITMA*/
	found = false;
	if(!IsEmpty(T)){
		i = GetFirstIdx(T);
		while(!found && (i<=GetLastIdx(T))){
			if(ElmtTab(T, i) == X){
				found = true;
			}
			else{
				i++;
			}
		}
	}
	if(found){
		return i;
	}
	else{
		return IdxUndef;
	}
	
}
boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{
	/*KAMUS LOKAL*/
	
	/*ALGORITMA*/
	return Search1(T, X) != IdxUndef;
}

/* ********** NILAI EKSTREM ********** */
void MaxMin (TabInt T, ElType * Max, ElType * Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
	/*KAMUS LOKAL*/
	IdxType i;
	/*ALGORITMA*/
	i = GetFirstIdx(T);
	*Max = ElmtTab(T,i);
	*Min = ElmtTab(T,i);
	for(i=i+1;i<=GetLastIdx(T);i++){
		if(ElmtTab(T,i)>*Max){
			*Max = ElmtTab(T,i);
		}
		if(ElmtTab(T,i)<*Min){
			*Min = ElmtTab(T,i);
		}
	}
	
}

/* ********** OPERASI LAIN ********** */
ElType SumTab (TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{
	/*KAMUS LOKAL*/
	IdxType i;
	ElType sum;
	/*ALGORITMA*/
	sum = 0;
	if(!IsEmpty(T)){
		for(i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
		sum += ElmtTab(T,i);
		}
	}
	return sum;
	
}
int CountX (TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
	/*KAMUS LOKAL*/
	int n;
	IdxType i;
	/*ALGORITMA*/
	n = 0;
	if(!IsEmpty(T)){
		for(i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
			if(ElmtTab(T,i)==X){
				n+=1;
			}
		}
	}
	return n;
}
boolean IsAllGenap (TabInt T)
/* Menghailkan true jika semua elemen T genap */
{
	/*KAMUS LOKAL*/
	boolean genap;
	IdxType i;
	/*ALGORITMA*/
	if(IsEmpty(T)){
		genap = true;
	}
	else{
		genap = true;
		i = GetFirstIdx(T);
		while(genap && (i<=GetLastIdx(T))){
			if((ElmtTab(T, i) % 2) != 0){
				genap = false;
			}
			else{
				i++;
			}
		}
	}
	return genap;
}

/* ********** SORTING ********** */
void Sort (TabInt * T, boolean asc)
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{
	/*KAMUS LOKAL*/
	IdxType i, j, idFirst, idLast, id;
	ElType temp;
	/*ALGORITMA*/
	if(!IsEmpty(*T)){
		idFirst = GetFirstIdx(*T);
		idLast =  GetLastIdx(*T);
		if(asc){
			for(i=idFirst;i<=idLast;i++){
				id = i;
				for(j=i+1;j<=idLast;j++){
					if(ElmtTab(*T, j) < ElmtTab(*T, id)){
						id = j;
					}
				}
				temp = ElmtTab(*T, i);
				ElmtTab(*T,i) = ElmtTab(*T, id);
				ElmtTab(*T, id) = temp;
			}
		}
		else{
			for(i=idFirst;i<=idLast;i++){
				id = i;
				for(j=i+1;j<=idLast;j++){
					if(ElmtTab(*T, j) > ElmtTab(*T, id)){
						id = j;
					}
				}
				temp = ElmtTab(*T, i);
				ElmtTab(*T,i) = ElmtTab(*T, id);
				ElmtTab(*T, id) = temp;
			}			
		}
		
	}
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	if(ElmtTab(*T, IdxMax == ValUndef)){
		ElmtTab(*T, GetLastIdx(*T)+1) = X;
	}
	
}
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	*X = ElmtTab(*T, GetLastIdx(*T));
	ElmtTab(*T, GetLastIdx(*T)) = ValUndef;
}