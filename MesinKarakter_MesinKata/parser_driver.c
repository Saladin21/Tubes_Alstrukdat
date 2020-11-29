#include "parser"
#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"
#include "mesinkar.h"




boolean IsKataSama(Kata K1, Kata K2){
	if(K1.Length==0 && K2.Length==0){
		return true;
	} else if(K1.Length == K2.Length){
		int i = 0;
		boolean kataSama = true;
		while(kataSama && i<K1.Length){
			if(K1.TabKata[i] != K2.TabKata[i]){
				kataSama = false;
			} else{
				i += 1;
			}
		}
		return kataSama;
	} else{
		return false;
	}

}


int main(){
	int kataReg = 0;
	int kataLong = 0;
	int Harga;

	Kata Koma;
	Koma.Length = 4;
	Koma.TabKata[0] = 'K';
	Koma.TabKata[1] = 'O';
	Koma.TabKata[2] = 'M';
	Koma.TabKata[3] = 'A';

	Kata Titik;
	Titik.Length = 5;
	Titik.TabKata[0] = 'T';
	Titik.TabKata[1] = 'I';
	Titik.TabKata[2] = 'T';
	Titik.TabKata[3] = 'I';
	Titik.TabKata[4] = 'K';

	STARTKATA();
	while(!(EndKata)){
		IgnoreBlank();
		if(IsKataSama(Koma, CKata)){
			printf(",");
		} else if(IsKataSama(Titik, CKata)){
			printf(".");
		} else{
			if(kataReg!=0 || kataLong!=0){
				printf(" ");
			}
			int i;
			for(i=0; i<CKata.Length; i++){
				char cc = CKata.TabKata[i];
				printf("%c", cc);
			}
			if(CKata.Length<10){
				kataReg += 1;
			} else{
				kataLong += 1;
			}
		}
		ADVKATA();
	}
	printf("\n");

	Harga = (kataReg*1000) + (kataLong*1500);
	if(kataReg+kataLong>=10){
		Harga *= 0.9;
	}

	printf("%d\n", kataReg);
	printf("%d\n", kataLong);
	printf("%d\n", Harga);
	return 0;
}