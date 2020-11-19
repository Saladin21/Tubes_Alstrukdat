#include<stdio.h>
#include "matriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M) 
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
}


/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return (i>=BrsMin) && (i<= BrsMax) && (j>= KolMin) && (j<=KolMax);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return BrsMin;	
}

indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return NBrsEff(M) - 1 + GetFirstIdxBrs(M);
}

indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return NKolEff(M) - 1 + GetFirstIdxKol(M);
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return (i>=GetFirstIdxBrs(M)) && (i<=GetLastIdxBrs(M)) && (j>=GetFirstIdxKol(M)) && (j<=GetLastIdxKol(M));
}

ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return Elmt(M, i, i);
}


/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
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
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
	/*KAMUS LOKAL*/
	int i, j;
	ElType nilai;
	/*ALGORITMA*/
	MakeMATRIKS(NB, NK, M);
	for (i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++){
		for(j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
			scanf("%d", &nilai);
			Elmt(*M, i, j) = nilai;
		}
	}
	
}

void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
	/*KAMUS LOKAL*/
	indeks i, j;
	/*ALGORITMA*/
	for (i=GetFirstIdxBrs(M);i<GetLastIdxBrs(M);i++){
		for(j=GetFirstIdxKol(M);j<GetLastIdxKol(M);j++){
			printf("%d ", Elmt(M, i, j));
		}
		printf("%d\n", Elmt(M,i,j));
	}

	for(j=GetFirstIdxKol(M);j<GetLastIdxKol(M);j++){
		printf("%d ", Elmt(M, i, j));
	}
	printf("%d", Elmt(M, i, j));
}


/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
	/*KAMUS LOKAL*/
	MATRIKS MHsl;
	indeks i,j;
	/*ALGORITMA*/
	MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &MHsl);
	for (i=GetFirstIdxBrs(MHsl);i<=GetLastIdxBrs(MHsl);i++){
		for(j=GetFirstIdxKol(MHsl);j<=GetLastIdxKol(MHsl);j++){
			Elmt(MHsl, i, j) = Elmt(M1, i, j) + Elmt(M2, i, j);
		}
	}	
	return MHsl;
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
{
	/*KAMUS LOKAL*/
	MATRIKS MHsl;
	indeks i, j;
	/*ALGORITMA*/
	MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &MHsl);
	for (i=GetFirstIdxBrs(MHsl);i<=GetLastIdxBrs(MHsl);i++){
		for(j=GetFirstIdxKol(MHsl);j<=GetLastIdxKol(MHsl);j++){
			Elmt(MHsl, i, j) = Elmt(M1, i, j) - Elmt(M2, i, j);
		}
	}
	return MHsl;
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
	/*KAMUS LOKAL*/
	MATRIKS MHsl;
	indeks i, j, k;
	ElType elemen;
	/*ALGORITMA*/
	MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &MHsl);
	for (i=GetFirstIdxBrs(MHsl);i<=GetLastIdxBrs(MHsl);i++){
		for(j=GetFirstIdxKol(MHsl);j<=GetLastIdxKol(MHsl);j++){
			elemen = 0;
			for(k=GetFirstIdxKol(M1);k<=GetLastIdxBrs(M2);k++){
				elemen += Elmt(M1, i, k) * Elmt(M2, k, j);
			}
			Elmt(MHsl, i, j) = elemen;
		}
	}

	return MHsl;
}

MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
	/*KAMUS LOKAL*/
	MATRIKS MHsl;
	indeks i, j;
	/*ALGORITMA*/
	MakeMATRIKS(NBrsEff(M), NKolEff(M), &MHsl);
	for (i=GetFirstIdxBrs(MHsl);i<=GetLastIdxBrs(MHsl);i++){
		for(j=GetFirstIdxKol(MHsl);j<=GetLastIdxKol(MHsl);j++){
			Elmt(MHsl, i, j) = Elmt(M, i, j) * X;
		}
	}
	return MHsl;
}

void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
	/*KAMUS LOKAL*/
	indeks i, j;
	/*ALGORITMA*/
	for (i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++){
		for(j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
			Elmt(*M, i, j) = Elmt(*M, i, j) * K;
		}
	}	
}


/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
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

boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return !EQ(M1, M2);
}	

boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return (NBrsEff(M1) == NBrsEff (M2)) && (NKolEff (M1) == NKolEff (M2));
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return NBrsEff(M) * NKolEff(M);
}


/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
	/*KAMUS LOKAL*/

	/*ALGORITMA*/
	return NBrsEff(M) == NKolEff(M);
}

boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
	/*KAMUS LOKAL*/
	boolean simetri;
	indeks i,j;
	/*ALGORITMA*/
	simetri = true;
	if (!IsBujurSangkar(M)){
		simetri = false;
	}
	else{
		i = GetFirstIdxBrs(M);
		while (simetri && i<=GetLastIdxBrs(M)){
			j = GetFirstIdxKol(M);
			while (simetri && j<i){
				if (Elmt(M, i, j) != Elmt(M, j, i)){
					simetri = false;
				}
				else{
					j++;
				}
			}
			if(simetri){
				i++;
			}
		}	
	}

	return simetri;
}

boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
{
	/*KAMUS LOKAL*/
	boolean satuan;
	indeks i, j;
	/*ALGORITMA*/
	if (!IsBujurSangkar(M)){
		satuan = false;
	}
	else{
		satuan = true;
		i = GetFirstIdxBrs(M);
		while (satuan && i<=GetLastIdxBrs(M)){
			j = GetFirstIdxKol(M);
			while (satuan && j<=GetLastIdxKol(M)){
				if ((i == j) && (Elmt(M,i,j) != 1)){
					satuan = false;
				}
				else if((i != j) && (Elmt(M,i,j) != 0)){
					satuan = false;
				}
				else{
					j++;
				}
			}
			if(satuan){
				i++;
			}
		}	
	}
	return satuan;	
}

boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
{
	/*KAMUS LOKAL*/
	float maks;
	int count;
	indeks i, j;
	boolean sparse;
	/*ALGORITMA*/
	maks = NBElmt(M) * 0.05;
	sparse = true;
	count = 0;
		
	i = GetFirstIdxBrs(M);
	while (sparse && i<=GetLastIdxBrs(M)){
		j = GetFirstIdxKol(M);
		while (sparse && j<=GetLastIdxKol(M)){
			if ((Elmt(M,i,j) != 0)){
				count++;
			}
			if(count>maks){
				sparse = false;
			}
			else{
				j++;
			}
		}
		if(sparse){
			i++;
		}
	}	
	return sparse;	
}

MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
	/*KAMUS LOKAL*/
	MATRIKS MHsl;
	indeks i, j;
	/*ALGORITMA*/
	MakeMATRIKS(NBrsEff(M), NKolEff(M), &MHsl);
	for (i=GetFirstIdxBrs(MHsl);i<=GetLastIdxBrs(MHsl);i++){
		for(j=GetFirstIdxKol(MHsl);j<=GetLastIdxKol(MHsl);j++){
			Elmt(MHsl, i, j) = Elmt(M, i, j) * (-1);
		}
	}
	return MHsl;
	
}

float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
	/*KAMUS LOKAL*/
	indeks i, j,  k, a, b;
	int sign;
	MATRIKS M1;
	float hasil;
	/*ALGORITMA*/
	if(NBElmt(M) == 4){
		hasil = (Elmt(M, 1, 1) * Elmt(M,0,0)) - (Elmt(M,0,1)*Elmt(M,1,0));
	}
	else if(NBElmt(M)==1){
		hasil = Elmt(M,0,0);
	}
	else if(NBElmt(M)==0){
		hasil = 0;
	}
	else{
		sign = 1;
		hasil = 0;
		for (k=GetFirstIdxBrs(M);k<=GetLastIdxBrs(M);k++){
			MakeMATRIKS((NBrsEff(M)-1), (NKolEff(M)-1), &M1);
			for (i=GetFirstIdxBrs(M)+1; i<=GetLastIdxBrs(M); i++){
				a = GetFirstIdxKol(M1);
				b = i -1;
				for (j = GetFirstIdxKol(M); j<=GetLastIdxKol(M); j++){
					if(j==k){

					}
					else{
						Elmt(M1, b, a) = Elmt(M, i, j);
						a++;
					}
				}
			}

			hasil += sign * Elmt(M, GetFirstIdxBrs(M), k) * Determinan(M1);
			sign *= -1;
		}		
	}

	return hasil;
	
}

void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
	/*KAMUS LOKAL*/
	indeks i, j;
	/*ALGORITMA*/
	for (i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++){
		for(j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
			Elmt(*M, i, j) = Elmt(*M, i, j) * (-1);
		}
	}	
}

void Transpose (MATRIKS * M)
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

/* Operasi berbasis baris dan per kolom */

float RataBrs (MATRIKS M, indeks i)
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
{
	/*KAMUS LOKAL*/
	ElType sum;
	float count;
	indeks j;
	float avg;
	/*ALGORITMA*/
	sum = 0;
	count = 0;
	for(j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
		sum += Elmt(M, i, j);
		count++;
	}
	avg = sum / count;
	return avg;

}
float RataKol (MATRIKS M, indeks j)
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
{
	/*KAMUS LOKAL*/
	ElType sum;
	float count;
	indeks i;
	float avg;
	/*ALGORITMA*/
	sum = 0;
	count = 0;
	for(i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
		sum += Elmt(M, i, j);
		count++;
	}
	avg = sum / count;
	return avg;
	
}
void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min)
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
{
	/*KAMUS LOKAL*/
	indeks j;
	/*ALGORITMA*/
	j = GetFirstIdxKol(M);
	*max = Elmt(M, i, j);
	*min = Elmt(M,i,j);

	for (j = GetFirstIdxKol(M)+1;j<=GetLastIdxKol(M);j++){
		if(Elmt(M,i,j)>*max){
			*max = Elmt(M,i,j);
		}
		if(Elmt(M,i,j)<*min){
			*min = Elmt(M,i,j);
		}
	}
}
void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min)
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
{
	/*KAMUS LOKAL*/
	indeks i;
	/*ALGORITMA*/
	i = GetFirstIdxBrs(M);
	*max = Elmt(M, i, j);
	*min = Elmt(M,i,j);

	for (i = GetFirstIdxBrs(M)+1;i<=GetLastIdxBrs(M);i++){
		if(Elmt(M,i,j) > *max){
			*max = Elmt(M,i,j);
		}
		if(Elmt(M,i,j) < *min){
			*min = Elmt(M,i,j);
		}
	}
	
}
int CountXBrs (MATRIKS M, indeks i, ElType X)
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
int CountXKol (MATRIKS M, indeks j, ElType X)
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